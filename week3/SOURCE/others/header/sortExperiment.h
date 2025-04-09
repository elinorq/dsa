#pragma once

#include "helpFunctions.h"
#include "dataGenerator.h"

#include "../../algorithms/header/selectionSort.h"
#include "../../algorithms/header/insertionSort.h"
#include "../../algorithms/header/bubbleSort.h"
#include "../../algorithms/header/shakerSort.h"
#include "../../algorithms/header/shellSort.h"
#include "../../algorithms/header/heapSort.h"
#include "../../algorithms/header/mergeSort.h"
#include "../../algorithms/header/quickSort.h"
#include "../../algorithms/header/countingSort.h"
#include "../../algorithms/header/radixSort.h"
#include "../../algorithms/header/flashSort.h"

#ifndef SORT_EXPERIMENT_H
#define SORT_EXPERIMENT_H

#define NUMBER_DATA_ORDER 4 // 0: Random, 1: Nearly Sorted, 2: Sorted, 3: Reverse
#define NUMBER_SORT_ALGORITHM 11
#define SELECTION_SORT 0
#define INSERTION_SORT 1
#define BUBBLE_SORT 2
#define SHAKER_SORT 3
#define SHELL_SORT 4
#define HEAP_SORT 5
#define MERGE_SORT 6
#define QUICK_SORT 7
#define COUNTING_SORT 8
#define RADIX_SORT 9
#define FLASH_SORT 10

class ResultOfSorting {
    public:
        std::chrono::duration<double, std::milli> running_time; // in milliseconds
        size_t count_comparison; // number of comparison
};

class SortExperiment {
    public:
        std::vector<std::vector<int>> arr;      // array of data to sort, we need to store 4 arrays for 4 data orders
        std::string file_name;
        int output_parameter;                   // 1: running time, 2: comparison, 3: both
        int input_size;                         // number of elements in the array
        int data_order_id;                      // 0: Random, 1: Nearly Sorted, 2: Sorted, 3: Reverse
        int algorithm_id[2];                    // for compare mode, we need to identify 2 algorithms
        bool is_algorithm_mode;                 // true: algorithm mode, false: compare mode
        bool is_input_from_file;                // for  command line
        bool is_running_all;
        std::string output_file;
        std::vector<ResultOfSorting> results;   // store the result of sorting

        SortExperiment();
        ~SortExperiment();
        void runCompareMode();
        void runAlgorithmMode();
        void printResult();
};

void sort(std::vector<int> &arr, int algorithm_id, size_t &count_comparison);
void sort(std::vector<int> &arr, int algorithm_id, std::chrono::duration<double, std::milli> &running_time);
std::string getAlgorithmName(int algorithm_id);
int getAlgorithmID(std::string sort_name);

#endif