#pragma once
#include "class.h"
#include "class_0.h"
#include "functions.h"
#include "operators.h"

int AT() {
	CCompexVector** arr;
	CCompexVector** arr1;
	ComplexNumber sc;
	int re, im = 0;
	int arrdim = 0;
	arr = fscan_data("at1.txt", 4, &arrdim);
	if (arrdim != 5) {
		cout << "Error! arrdim is" << arrdim << "instead 5" << endl;
		delete[] arr;
		return 0;
	}
	(*arr[0]) += (*arr[1]);
	(*arr[1]) -= (*arr[4]);
	arr1 = fscan_data("antans.txt", 4, &arrdim);
	if (arrdim != 5) {
		cout << "Error_1! arrdim is" << arrdim << "instead 5" << endl;
		delete[] arr;
		delete[] arr1;
		return 0;
	}
	for (int i = 0; i < arrdim; i++) {
		if ((*arr[i]) != (*arr1[i])) {
			delete[] arr;
			delete[] arr1;
			cout << "Error_2! vector on" << i << "string " << endl;
			return 0;
		}
	}
	re = -4;
	im = 0;
	sc = (*arr[3])*(*arr[4]);
	if (re != sc.re || im != sc.im) {
		delete[] arr;
		delete[] arr1;
		cout << "Error_3! sc is wrong" << endl;
		return 0;
	}

	delete[] arr;
	delete[] arr1;
	return 1;
}