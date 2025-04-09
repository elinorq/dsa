#include "../header/commandLine.h"

// #define EXPERIMENT

void overview() {
    int data_test[4] = {10000, 30000, 50000, 100000};
    std::vector<int> arr;

    #ifdef EXPERIMENT
        for (int i = 0; i < 4; i++) {
            data_test[i] /= 1000;
        }
    #endif

    for (int dataOrderCode = 0; dataOrderCode < NUMBER_DATA_ORDER; dataOrderCode++) {
        std::string fileName = getDataOrderName(dataOrderCode) + ".csv";
        std::ofstream out(fileName);    

        out << "Data order: " << getDataOrderName(dataOrderCode) << '\n';
        out << "Data size";

        std::cout << "Data order: " << getDataOrderName(dataOrderCode) << '\n';
        std::cout << "Data size";
        for (int size_idx = 0; size_idx < 4; size_idx++) {
            out << ", " << data_test[size_idx] << ", ";
            std::cout << ", " << data_test[size_idx] << ", ";
        }
        out << "\nResulting statics";
        std::cout << "\nResulting statics";
        for (int size_idx = 0; size_idx < 4; size_idx++) {
            out << ", Running time, Comparison";
            std::cout << ", Running time, Comparison";
        }
        out << '\n';
        std::cout << '\n';

        for (int algorithmID = 0; algorithmID < NUMBER_SORT_ALGORITHM; algorithmID++) {
            out << getAlgorithmName(algorithmID);
            std::cout << getAlgorithmName(algorithmID);
            for (int size_idx = 0; size_idx < 4; size_idx++) {
                int data_size = data_test[size_idx];
                arr.resize(data_size);
                generateData(arr, data_size, dataOrderCode);

                size_t comparisons = 0;
                std::chrono::duration<double, std::milli> running_time;

                std::vector<int> arr2 = arr;
                sort(arr2, algorithmID, running_time);

                arr2 = arr;
                sort(arr2, algorithmID, comparisons);

                out << ", " << running_time.count() << ", " << comparisons;
                std::cout << ", " << running_time.count() << ", " << comparisons;
            }
            out << "\n";
            std::cout << "\n";
        }
        out.close();
    }
}

int main(int argc, char **argv) {
    if (argc == 2 && !strcmp(argv[1], "-experiment")) {
        overview();
        return 0;
    }

    SortExperiment experiment;
    executeWithCommandLine(experiment, argc, argv);

    return 0;
}