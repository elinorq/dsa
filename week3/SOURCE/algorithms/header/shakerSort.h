#pragma once

#include "../../others/header/helpFunctions.h"

#ifndef SHAKER_SORT_H
#define SHAKER_SORT_H

template<class T>
void shakerSort(std::vector<T>& array);

template<class T>
void shakerSort(std::vector<T>& array, size_t& count_comparison);

#endif // SHAKER_SORT_H