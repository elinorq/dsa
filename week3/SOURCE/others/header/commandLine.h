#pragma once

#include "sortExperiment.h"

#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

void executeWithCommandLine(SortExperiment &experiment, int argc, char **argv);
bool parseCommandLine(SortExperiment &experiment, int argc, char **argv);
void handleAlgorithmMode(SortExperiment &experiment, char **argv);
void handleInputOutput(SortExperiment &experiment, char **argv);

#endif