import subprocess
import spot
import spot.ltsmin
import os
import re
import shutil

SRC_FOLDER = "./LTL-HVC16/experiments/"
BENCHMARKS = ["beem-gen", "beem-orig"]#, "mcc2015"]
DST_FOLDER = "./benchmark"



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


unique_dst = make_unique_folder(DST_FOLDER)

def quote_comparisons(ltl_str):
    pattern = r'\(\s*\(\s*([^)]+?)\s*\)\s*(<=|>=|<|>)\s*\(\s*([^)]+?)\s*\)\s*\)'
    def replacer(match):
        lhs = match.group(1).strip()
        op = match.group(2)
        rhs = match.group(3).strip()
        return f'"{lhs} {op} {rhs}"'
    return re.sub(pattern, replacer, ltl_str)

def preprocess_ltl(ltl_str, folder):
    # Replace a1=="S" → a1==S
    if "mcc" in folder:
        ltl_str=quote_comparisons(ltl_str)
    ltl_str = ltl_str.replace(r'\[', '[').replace(r'\]', ']')
    return re.sub(r'(\w+(?:\[\d+\])?)==\"([^"]+)\"', r'"\1==\2"', ltl_str)


def model_check(f, m):
    nf = spot.formula.Not(f)
    ss = m.kripke(spot.atomic_prop_collect(nf))
    return spot.otf_product(ss, nf.translate()).is_empty() 

not_done = []
done = 0
for benchmark in BENCHMARKS:
    current_benc =  os.path.join(SRC_FOLDER, benchmark)
    for folder in os.listdir(current_benc):
        current_src_folder = os.path.join(current_benc, folder)
        current_dst_folder = os.path.join(unique_dst, folder)
        print(f"Processing: {current_src_folder} -> {current_dst_folder}")
        current_dst_folder, folder = make_unique_folder(current_dst_folder, folder)
        formulas = []
        for filename in os.listdir(current_src_folder):
            if filename.endswith(".dve"):
                shutil.copy(os.path.join(current_src_folder, filename),
                             os.path.join(current_dst_folder, f"{folder}_model.dve"))
                continue  # Skip .dve files
            if not filename.endswith(".ltl"):
                continue  # Skip non-.ltl files

            filepath = os.path.join(current_src_folder, filename)
            with open(filepath, 'r') as f:
                lines = f.readlines()
                ltl_formulas = [line.strip() for line in lines if line.strip()]

            for ltl_formula_str in ltl_formulas:
                clean_formula_str = preprocess_ltl(ltl_formula_str, current_benc)
                try:
                    formula = spot.formula(clean_formula_str)  # Syntax check
                    formulas.append(clean_formula_str)
                except Exception as e:
                    not_done.append((filepath, ltl_formula_str))
                    #print(f"[!] Error parsing formula in {filepath}:\n{ltl_formula_str}\n{e}")

        done += len(formulas)
        print(f"{current_dst_folder}, {len(formulas)}")

        # Save all cleaned formulas
        with open(os.path.join(current_dst_folder, "properties.ltl"), 'w') as f:
            for item in formulas:
                f.write(f"{item}\n")
    

print(f"Not done {len(not_done)}")
print(f"Done {done}")

with open("notdone.ltl", 'w') as f:
        for item in not_done:
            f.write(f"{item[1]}\n")