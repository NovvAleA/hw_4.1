#pragma once
#include "class.h"
#include "class_0.h"
#include "class_1.h"

CCompexVector** fscan_data_and_output(const char* fname, int dim);
CCompexVector** fscan_data(const char* fname, int dim, int* arrdim);
CCompexVector** fscan_data(const char* fname, int dim);
int create_CCV(const char* fname, int dim);
int create_CCV_and_fout(const char* fname, int dim);
