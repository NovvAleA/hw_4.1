#pragma once
#include "class.h"
#include "class_0.h"
#include "class_1.h"


CCompexVector& CCompexVector::operator+=(CCompexVector& second) {
	/*CCompexVector0 temp(dim);*/
	
	double* arr_re2 = second.get_re_p();
	double* arr_im2 = second.get_im_p();

	for (int i = 0; i < dim; i++ ) {	
		
		arr[0][i] += arr_re2[i];
		arr[1][i] += arr_im2[i];
	}
	//this->output();
	return *this;
}

CCompexVector& CCompexVector::operator-=(CCompexVector& second) {
	/*CCompexVector0 temp(dim);*/

	double* arr_re2 = second.get_re_p();
	double* arr_im2 = second.get_im_p();

	for (int i = 0; i < dim; i++) {
		
		arr[0][i] -= arr_re2[i];
		arr[1][i] -= arr_im2[i];
	}
	//this->output();
	return *this;
}


ComplexNumber operator*( CCompexVector& first, CCompexVector& second) {
	ComplexNumber sc;
	sc.re = 0;
	sc.im = 0;

	double* arr_re1 = first.get_re_p();
	double* arr_im1 = first.get_im_p();
	double* arr_re2 = second.get_re_p();
	double* arr_im2 = second.get_im_p();

	for (int i = 0; i < first.get_dim(); i++) {
		sc.re += arr_re1[i] * arr_re2[i] + arr_im1[i] * arr_im2[i];
		sc.im += arr_re1[i] * arr_im2[i] - arr_im1[i] * arr_re2[i];
	}
	return sc;
}


//CCompexVector0 operator-(CCompexVector0& first, CCompexVector0& second) {
//	CCompexVector0 temp(first.get_dim());
//	if (first.get_dim() != second.get_dim()) {
//		printf("dim error\n");
//	}
//	double* arr_re1 = first.get_re_p();
//	double* arr_im1 = first.get_im_p();
//	double* arr_re2 = second.get_re_p();
//	double* arr_im2 = second.get_im_p();
//
//	for (int i = 0; i++; i < first.get_dim()) {
//		temp.get_real()[i] = arr_re1[i] - arr_re2[i];
//		temp.get_imag()[i] = arr_im1[i] - arr_im2[i];
//	}
//
//	return temp;
//}
//


