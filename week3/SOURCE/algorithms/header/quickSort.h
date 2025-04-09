#pragma once

#include "../../others/header/helpFunctions.h"

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

template<class T>
int Partition(std::vector<int>& array, int low, int high, size_t& count_comparison);

template<class T>
void impleQuickSort(std::vector<T>& array, int low, int high, size_t& count_comparison);

template<class T>
void quickSort(std::vector<T>& array, size_t& count_comparison);

template<class T>
int Partition(std::vector<int>& array, int low, int high);

template<class T>
void impleQuickSort(std::vector<T>& array, int low, int high);

template<class T>
void quickSort(std::vector<T>& array);

#endif // QUICK_SORT_H