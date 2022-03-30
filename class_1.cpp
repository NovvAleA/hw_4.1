#include "class_1.h"

int CCompexVector1::output() {
	ofstream out;
	out.open(foutput, ios_base::app);
    for (int i = 0; i < dim; i++) {
        if (arr[1][i] > 0) {
            out << arr[0][i] << " + " << arr[1][i] << "i, ";
        }
        if (arr[1][i] < 0) {
            out << arr[0][i] <<  " "  << arr[1][i] << "i, ";
        }
        if (arr[1][i] == 0) {
            out << arr[0][i] << ", ";
        }
    }
    out << "\n\n";
    out.close();
	return 1;
}
//
//CCompexVector1 CCompexVector1::operator+( CCompexVector& other) {
//	CCompexVector1 temp(dim);
//	if (dim!= other.get_dim()) {
//		printf("dim error\n");
//	}
//	double* arr_re1 = arr[0];
//	double* arr_im1 = arr[1];
//	double* arr_re2 = other.get_re_p();
//	double* arr_im2 = other.get_im_p();
//
//	for (int i = 0; i++; i < dim) {
//		temp.get_real()[i] = arr_re1[i] + arr_re2[i];
//		temp.get_imag()[i] = arr_im1[i] + arr_im2[i];
//	}
//
//	return temp;
//}

//ComplexNumber CCompexVector1::operator*( CCompexVector* other) {
//	ComplexNumber sc;
//	sc.re = 0;
//	sc.im = 0;
//
//	double* arr_re1 = arr[0];
//	double* arr_im1 = arr[1];
//	double* arr_re2 = (*other).get_re_p();
//	double* arr_im2 = (*other).get_im_p();
//	;
//
//	for (int i = 0; i < dim; i++) {
//		sc.re += arr_re1[i] * arr_re2[i] + arr_im1[i] * arr_im2[i];
//		sc.im += arr_re1[i] * arr_im2[i] - arr_im1[i] * arr_re2[i];
//	}
//	return sc;
//}