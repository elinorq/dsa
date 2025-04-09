#include "../header/commandLine.h"

bool parseCommandLine(SortExperiment &experiment, int argc, char **argv) {
    if (argc < 2 || argc != 7) return false;

    for (int i = 1; i < argc; ) {
        if (!strcmp(argv[i], "-a")) {
            if (i + 1 >= argc) return false;
            handleAlgorithmMode(experiment, argv + i + 1);
            i += 2;
        }
        else if (!strcmp(argv[i], "-i")) {
            if (i + 1 >= argc) return false;
            experiment.file_name = argv[i + 1];
            experiment.is_input_from_file = true;
            i += 2;
        }
        else if (!strcmp(argv[i], "-o")) {
            if (i + 1 >= argc) return false;
            experiment.output_file = argv[i + 1];
            i += 2;
        }
        else {
            i++;
        }
    }
    return true;
}

void handleAlgorithmMode(SortExperiment &experiment, char **argv) {
    experiment.is_algorithm_mode = true;
    experiment.algorithm_id[0] = getAlgorithmID(argv[0]);
    if (experiment.algorithm_id[0] == -1) {
        std::cout << "Unknown algorithm: " << argv[0] << "\n";
        exit(1);
    }
}

void executeWithCommandLine(SortExperiment &experiment, int argc, char **argv) {
    if (!parseCommandLine(experiment, argc, argv)) {
        std::cout << "Invalid command line syntax!\n";
        std::cout << "Usage: [execute file] -a [algorithm] -i [input] -o [output]\n";
        exit(1);
    }

    if (experiment.is_input_from_file) {
        if (!readData(experiment.arr[0], experiment.file_name)) {
            std::cout << "Failed to read input file\n";
            exit(1);
        }
        experiment.input_size = experiment.arr[0].size();
    }

    if (experiment.is_algorithm_mode) {
        experiment.runAlgorithmMode();
    } else {
        experiment.runCompareMode();
    }

    experiment.printResult();
}