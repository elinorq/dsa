#pragma once

#include "helpFunctions.h"

#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H

template <class T>
void generateRandomData(std::vector<int> &arr, int n);
void generateSortedData(std::vector<int> &arr, int n);
void generateReverseData(std::vector<int> &arr, int n);
void generateNearlySortedData(std::vector<int> &arr, int n);
void generateData(std::vector<int> &arr, int n, int dataType);
std::string getDataOrderName(int data_order_id);
int getDataOrderID(char agr_flag[]);

#endif // DATA_GENERATOR_H