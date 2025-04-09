#pragma once

#include "../../others/header/helpFunctions.h"

#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

template<class T>
void countingSort(std::vector<T>& array, size_t& count_comparison);

template<class T>
void countingSort(std::vector<T>& array);

#endif // COUNTING_SORT_H