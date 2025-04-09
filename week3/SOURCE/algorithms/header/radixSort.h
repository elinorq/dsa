#pragma once

#include "../../others/header/helpFunctions.h"

#ifndef RADIX_SORT_H
#define RADIX_SORT_H

template<class T>
T getMax(std::vector<T>& array, size_t& count_comparison);

template<class T>
void countSort(std::vector<T>& array, size_t exp, size_t& count_comparison);

template<class T>
void radixSort(std::vector<T>& array, size_t& count_comparison);

template<class T>
T getMax(std::vector<T>& array);

template<class T>
void countSort(std::vector<T>& array, size_t exp);

template<class T>
void radixSort(std::vector<T>& array);

#endif // RADIX_SORT_H