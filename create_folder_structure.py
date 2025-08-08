from ltl_reducer import create_new_minimal_folder




ORIGINAL_FOLDER = "benchmark_000"
MINIMAL_FOLDER = "minimal_ltl"
NAME_NEW_FOLDER = "minimal_benchmarks"

def main():
    create_new_minimal_folder(NAME_NEW_FOLDER,
                                original_folder=ORIGINAL_FOLDER,
                                minimal_folder=MINIMAL_FOLDER)

if __name__ == "__main__":
    main()
    print(f"New folder '{NAME_NEW_FOLDER}' created with processed files.")