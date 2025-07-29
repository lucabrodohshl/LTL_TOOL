import subprocess
import spot
import spot.ltsmin
import os
import re
import shutil
import time
import pandas as pd
from tqdm import tqdm
import concurrent.futures
import multiprocessing
SRC_FOLDER = "./benchmark_000"
CSV_OUTPUT = "timing_summary.csv"
RES_FOLDER = "./result"
model_temp_dir = "models_dir"
TIMEOUTS = 1000



def make_unique_folder(base_path, folder = None):
    """
    Create a folder. If it exists, append _001, _002, etc.
    Returns the path of the created folder.
    """
    counter = 0
    path = f"{base_path}_{counter:03}"
    while os.path.exists(path):
        counter += 1
        path = f"{base_path}_{counter:03}"
        
    os.makedirs(path)
    if folder is None:
        return path
    else:
        return path, f"{folder}_{counter:03}"


current_res = make_unique_folder(RES_FOLDER)

def model_check(f, m):
    nf = spot.formula.Not(f)
    ss = m.kripke(spot.atomic_prop_collect(nf))
    return spot.otf_product(ss, nf.translate()).is_empty() 



def model_check_worker(f, model_file, queue):
    try:
        result = model_check(f, model_file)
        queue.put(result)
    except Exception as e:
        queue.put(e)

def model_check_with_timeout(f, model_file, timeout_sec=TIMEOUTS):
    queue = multiprocessing.Queue()
    p = multiprocessing.Process(target=model_check_worker, args=(f, model_file, queue))
    p.start()
    p.join(timeout_sec)
    if p.is_alive():
        p.terminate()
        p.join()
        print(f"Timeout - killed process for formula: {f}")
        return None
    else:
        if not queue.empty():
            res = queue.get()
            if isinstance(res, Exception):
                print(f"Exception in model_check: {res}")
                return None
            else:
                return res
        else:
            return None

def test(f, model, model_temp_dir):
    print(model)
    
    
    #print("Available APs:", m)


tot = 0
start = time.perf_counter()

# Data to collect for pandas DataFrame
results = []


if not os.path.exists(model_temp_dir):
    os.makedirs(model_temp_dir)


dir_path = os.path.dirname(os.path.realpath(__file__))


df = pd.DataFrame(columns =["Benchmark", "Num Properties", "Total Elapsed Time (seconds)","Average Elapsed Time (seconds)",  "Timeouts"])

for folder in tqdm(sorted(os.listdir(SRC_FOLDER)), position=0):
    if folder.startswith('.'):  # skip hidden/system files
        continue
    timeouts = 0
    timings = {}
    current_src_folder = os.path.join(SRC_FOLDER, folder)
    properties_file = os.path.join(current_src_folder, "properties.ltl")
    model_file = os.path.join(current_src_folder, f"{folder}_model.dve")
    if not os.path.isfile(model_file):
        model_file = os.path.join(current_src_folder, f"{folder}_model.pnml")
    if not os.path.isfile(properties_file):
        continue

    tqdm.write(f"Currently doing: {current_src_folder}")
    

    with open(properties_file, 'r') as f:
        lines = f.readlines()
        ltl_formulas = [line.strip() for line in lines if line.strip()]
    num_properties = len(ltl_formulas)
    tot += num_properties

    os.chdir(model_temp_dir)
    m = spot.ltsmin.load("../"+model_file)
    
    for formula in tqdm(ltl_formulas, position=1, leave=False):
        ################
        start_local = time.perf_counter()
        res = model_check_with_timeout(formula, m)
        end_local = time.perf_counter()
        ##############
        timings[formula] = (end_local - start_local if res is not None else TIMEOUTS
                            ,res)
        if res is None:
            timeouts +=1
        tqdm.write(f"{formula} : {str(res)}")

    os.chdir(dir_path)

    timing_df = pd.DataFrame([
        {"formula": formula, "time": val[0], "result": val[1]}
        for formula, val in timings.items()
    ])

    timing_df.to_csv(f"{str(os.path.join(current_res, folder)[:-1])}.csv")

    tot_el = sum([t[0] for t in timings.values()])
    entry = {
    "Benchmark": folder,
    "Num Properties": num_properties,
    "Total Elapsed Time (seconds)": tot_el,
    "Average Elapsed Time (seconds)": tot_el / len(timings.values()),
    "Timeouts": timeouts
    }

    df = pd.concat([df, pd.DataFrame([entry])])
    df.to_csv(CSV_OUTPUT)
end = time.perf_counter()
elapsed_time = end - start

print(f"\nTotal formulas: {tot}")
print(f"Elapsed time: {elapsed_time:.2f} seconds")


df.to_csv(CSV_OUTPUT, index=False)
print(f"\nSummary saved to: {CSV_OUTPUT}")
