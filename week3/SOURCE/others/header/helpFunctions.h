#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <chrono>

#ifndef HELP_FUNCTIONS
#define HELP_FUNCTIONS

template <class T>
void swap(T &a, T &b);
int random(int l, int r);

bool readData(std::vector<int> &arr, std::string fileName);
bool writeData(std::vector<int> &arr, std::string fileName);
bool isNumber(char *str);
int getOutputParameterID(char *param_flag);
bool isOutputParameterID(char *param_flag);

#endif