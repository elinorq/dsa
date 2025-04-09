#include "../header/sortExperiment.h"

SortExperiment::SortExperiment() {
    arr.resize(NUMBER_SORT_ALGORITHM);
    results.resize(NUMBER_SORT_ALGORITHM);
    output_parameter = -1;
    input_size = 0;
    is_running_all = false;
}

SortExperiment::~SortExperiment() {
    int size = arr.size();

    for (int i = 0; i < size; i++) {
        arr[i].clear();
    }

    arr.clear();
    results.clear();
}

void SortExperiment::printResult() {
    if (is_algorithm_mode) {
        std::cout << "ALGORITHM MODE\n";
        std::cout << "Algorithm: " << getAlgorithmName(algorithm_id[0]) << '\n';

        if (is_input_from_file) {
            std::cout << "Input file: " << file_name << '\n';
        }

        std::cout << "Input size: " << input_size << '\n';

        int number_data_order = is_running_all ? NUMBER_DATA_ORDER : 1;

        for (int i = 0; i < number_data_order; i++) {
            if (!is_input_from_file) {
                if (is_running_all) {
                    std::cout << "\nInput order: " << getDataOrderName(i) << '\n';
                }
                else {
                    std::cout << "Input order: " << getDataOrderName(data_order_id) << '\n';
                }        
            }

            std::cout << "------------------------------------\n";

            if (output_parameter == 3) {
                std::cout << "Running time: " << results[i].running_time.count() << " ms\n";
                std::cout << "Comparisons: " << results[i].count_comparison << '\n';
            }
            else if (output_parameter == 2) {
                std::cout << "Comparisons: " << results[i].count_comparison << '\n';
            }
            else {
                std::cout << "Running time: " << results[i].running_time.count() << " ms\n";
            }
        }
    }
    else {
        std::cout << "COMPARE MODE\n";
        std::cout << "Algorithm: " << getAlgorithmName(algorithm_id[0]) << " | " << getAlgorithmName(algorithm_id[1]) << '\n';

        if (is_input_from_file) {
            std::cout << "Input file: " << file_name << '\n';
        }

        std::cout << "Input size: " << input_size << '\n';
        
        if (!is_input_from_file) {
            std::cout << "Input order: " << getDataOrderName(data_order_id) << '\n';
        }

        std::cout << "---------------------------------------------\n";
        std::cout << "Running time: " << results[0].running_time.count() << " ms | " << results[1].running_time.count() << " ms\n";
        std::cout << "Comparisons: " << results[0].count_comparison << " | " << results[1].count_comparison << '\n';
    }

    return;
}
        
void SortExperiment::runAlgorithmMode() {
    output_parameter = 3;
    int loops = is_running_all ? NUMBER_DATA_ORDER : 1;
    std::vector<int> temp;

    for (int i = 0; i < loops; i++) {
        if (output_parameter == 3) {
            temp = arr[i];
            sort(temp, algorithm_id[0], results[i].count_comparison);

            temp = arr[i];
            sort(temp, algorithm_id[0], results[i].running_time);
        }

        else if (output_parameter == 2) {
            temp = arr[i];
            sort(temp, algorithm_id[0], results[i].count_comparison);
        }

        else if (output_parameter == 1) {
            temp = arr[i];
            sort(temp, algorithm_id[0], results[i].running_time);
        }

        else {
            std::cout << "Invalid output parameter\n";
            break;
        }
    }

    if (loops == 1) {
        writeData(temp, output_file);
    }
}

void SortExperiment::runCompareMode() {
    std::vector<int> temp;

    for (int i = 0; i < 2; i++) {
        temp = arr[0];
        sort(temp, algorithm_id[i], results[i].count_comparison);

        temp = arr[0];
        sort(temp, algorithm_id[i], results[i].running_time);
    }
}



void sort(std::vector<int> &arr, int algorithm_id, size_t &count_comparison) {
    count_comparison = 0;

    switch (algorithm_id) {
        case SELECTION_SORT:
            selectionSort(arr, count_comparison);
            break;
        case INSERTION_SORT:
            insertionSort(arr, count_comparison);
            break;
        case BUBBLE_SORT:
            bubbleSort(arr, count_comparison);
            break;
        case SHAKER_SORT:
            shakerSort(arr, count_comparison);
            break;
        case SHELL_SORT:
            shellSort(arr, count_comparison);
            break;
        case HEAP_SORT:
            heapSort(arr, count_comparison);
            break;
        case MERGE_SORT:
            mergeSort(arr, count_comparison);
            break;
        case QUICK_SORT:
           quickSort(arr, count_comparison);
            break;
        case COUNTING_SORT:
            countingSort(arr, count_comparison);
            break;
        case RADIX_SORT:
            radixSort(arr, count_comparison);
            break;
        case FLASH_SORT:
            flashSort(arr, count_comparison);
            break;
        default:
            break;
    }
}

void sort(std::vector<int> &arr, int algorithm_id, std::chrono::duration<double, std::milli> &running_time) {
    const std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    switch (algorithm_id) {
        case SELECTION_SORT:
            selectionSort(arr);
            break;
        case INSERTION_SORT:
            insertionSort(arr);
            break;
        case BUBBLE_SORT:
            bubbleSort(arr);
            break;
        case SHAKER_SORT:
            shakerSort(arr);
            break;
        case SHELL_SORT:
            shellSort(arr);
            break;
        case HEAP_SORT:
            heapSort(arr);
            break;
        case MERGE_SORT:
            mergeSort(arr);
            break;
        case QUICK_SORT:
            quickSort(arr);
            break;
        case COUNTING_SORT:
            countingSort(arr);
            break;
        case RADIX_SORT:
            radixSort(arr);
            break;
        case FLASH_SORT:
            flashSort(arr);
            break;
        default:
            break;
    }

    const std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> time_count = end - start;
    running_time = time_count;
}

std::string getAlgorithmName(int algorithm_id) {
    switch(algorithm_id) {
        case SELECTION_SORT:
            return "Selection Sort";
        case INSERTION_SORT:
            return "Insertion Sort";
        case BUBBLE_SORT:
            return "Bubble Sort";
        case SHAKER_SORT:
            return "Shaker Sort";
        case SHELL_SORT:
            return "Shell Sort";
        case HEAP_SORT:
            return "Heap Sort";
        case MERGE_SORT:
            return "Merge Sort";
        case QUICK_SORT:
            return "Quick Sort";
        case COUNTING_SORT:
            return "Counting Sort";
        case RADIX_SORT:
            return "Radix Sort";
        case FLASH_SORT:
            return "Flash Sort";
        default:
            return "Unknown sort algorithm";
    }
}

int getAlgorithmID(std::string sort_name) {
    if (sort_name == "selection-sort") {
        return SELECTION_SORT;
    }

    else if (sort_name == "insertion-sort") {
        return INSERTION_SORT;
    }
    
    else if (sort_name == "bubble-sort") {
        return BUBBLE_SORT;
    } 
    
    else if (sort_name == "shaker-sort") {
        return SHAKER_SORT;
    } 
    
    else if (sort_name == "shell-sort") {
        return SHELL_SORT;
    } 
    
    else if (sort_name == "heap-sort") {
        return HEAP_SORT;
    } 
    
    else if (sort_name == "merge-sort") {
        return MERGE_SORT;
    } 
    
    else if (sort_name == "quick-sort") {
        return QUICK_SORT;
    } 
    
    else if (sort_name == "counting-sort") {
        return COUNTING_SORT;
    } 
    
    else if (sort_name == "radix-sort") {
        return RADIX_SORT;
    } 
    
    else if (sort_name == "flash-sort") {
        return FLASH_SORT;
    } 
    
    return -1;
}