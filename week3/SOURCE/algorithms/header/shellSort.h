#pragma once

#include "../../others/header/helpFunctions.h"

#ifndef SHELL_SORT_H
#define SHELL_SORT_H

template <class T> void shellSort(std::vector<T> &arr, size_t &count_comparison);
template <class T> void shellSort(std::vector<T> &arr);

#endif // SHELL_SORT_H