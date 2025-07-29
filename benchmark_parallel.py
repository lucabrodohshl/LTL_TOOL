from concurrent.futures import ProcessPoolExecutor, as_completed, TimeoutError
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
SRC_FOLDER = "./benchmark"
CSV_OUTPUT = "timing_summary.csv"


MAX_WORKERS = os.cpu_count() or 4
TIMEOUT_SEC = 50

def model_check(f, model_file):
    m = spot.ltsmin.load(model_file)
    nf = spot.formula.Not(f)
    ss = m.kripke(spot.atomic_prop_collect(nf))
    print(m,ss)
    return spot.otf_product(ss, nf.translate()).is_empty() 


def model_check_safe(args):
    f, model_file = args
    try:
        return model_check(f, model_file)
    except Exception as e:
        print(f"Exception in formula: {f} -> {e}")
        return None


tot = 0
start = time.perf_counter()

# Data to collect for pandas DataFrame
results = []

for folder in tqdm(os.listdir(SRC_FOLDER), position=0):
    if folder.startswith('.'):
        continue

    current_src_folder = os.path.join(SRC_FOLDER, folder)
    properties_file = os.path.join(current_src_folder, "properties.ltl")
    model_file = os.path.join(current_src_folder, "model.dve")
    if not os.path.isfile(model_file):
        model_file = os.path.join(current_src_folder, "model.pnml")

    if not os.path.isfile(properties_file):
        continue

    tqdm.write(f"Currently doing: {current_src_folder}")
    start_local = time.perf_counter()

    with open(properties_file, 'r') as f:
        ltl_formulas = [line.strip() for line in f if line.strip()]

    num_properties = len(ltl_formulas)
    tot += num_properties

    # Run formulas in parallel with timeouts
    with ProcessPoolExecutor(max_workers=MAX_WORKERS) as executor:
        futures = {
            executor.submit(model_check_safe, (formula, model_file)): formula
            for formula in ltl_formulas
        }

        for future in tqdm(as_completed(futures, timeout=TIMEOUT_SEC * len(ltl_formulas)),
                           total=len(futures), position=1, leave=False):
            formula = futures[future]
            try:
                result = future.result(timeout=TIMEOUT_SEC)
                # You can collect/store `result` if needed
            except TimeoutError:
                print(f"Timeout - killed process for formula: {formula}")
            except Exception as e:
                print(f"Error while checking {formula}: {e}")

    end_local = time.perf_counter()
    elapsed_local = end_local - start_local

    results.append({
        "Benchmark": folder,
        "Num Properties": num_properties,
        "Elapsed Time (seconds)": elapsed_local
    })


end = time.perf_counter()
elapsed_time = end - start

print(f"\nTotal formulas: {tot}")
print(f"Elapsed time: {elapsed_time:.2f} seconds")

# Create a DataFrame and save
df = pd.DataFrame(results)
df.loc["Total"] = ["All Benchmarks", tot, elapsed_time]  # Add total summary row

df.to_csv(CSV_OUTPUT, index=False)
print(f"\nSummary saved to: {CSV_OUTPUT}")
