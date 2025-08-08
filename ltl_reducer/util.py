import os 
import shutil

ORIGINAL_FOLDER = "benchmark_000"
MINIMAL_FOLDER = "minimal_ltl"
NAME_NEW_FOLDER = "minimal_benchmark"



def create_new_minimal_folder(name_new_folder,
                             original_folder,
                             minimal_folder):
    if not os.path.exists(name_new_folder):
        os.makedirs(name_new_folder)
    
    for folder in os.listdir(original_folder):
        dst = os.path.join(name_new_folder, folder)
        src = os.path.join(original_folder, folder)
        if not os.path.exists(dst):
            os.makedirs(dst)
        files = os.listdir(src)
        for file in files:
            if file.endswith(".dve"):
                shutil.copyfile(
                    os.path.join(src, file), 
                    os.path.join(dst, file)
                )
        src = os.path.join(minimal_folder, f"{folder}_minimal.ltl")
        try:
            shutil.copyfile(
                src,
                os.path.join(dst, f"properties.ltl")
            )
        except FileNotFoundError:
            print(f"Warning: {src} not found. Skipping copy.")
            continue





def main():
    create_new_minimal_folder(NAME_NEW_FOLDER,
                             original_folder=ORIGINAL_FOLDER,
                             minimal_folder=MINIMAL_FOLDER)
    print(f"New folder '{NAME_NEW_FOLDER}' created with processed files.")





if __name__ == "__main__":
    main()




