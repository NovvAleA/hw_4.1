#include "class.h"


CCompexVector& CCompexVector::operator=( CCompexVector& other) {
	dim = other.get_dim();
	vec_copy(other.get_real(), other.get_imag(), other.get_dim());
	return *this;
}
int CCompexVector::operator!=(CCompexVector& other) {
	if (dim != other.get_dim()) {
		return 1;
	}
	for (int i = 0; i < dim; i++)
	{
		if (arr[0][i] != other.get_real()[i]) {
			return 1;
		}
		if (arr[1][i] != other.get_imag()[i]) {
			return 1;
		}
	}
	return 0;
}
CCompexVector::CCompexVector(int d) {
	dim = d;
	strcpy(foutput, "rez.txt");
	arr = new double* [2];
	arr[0] = new double[dim];//real part
	arr[1] = new double[dim];//imaginary part
	for (int i = 0; i < dim; i++) {
		arr[0][i] = 0;
		arr[1][i] = 0;
	}
	if (arr[0] == nullptr || arr[1] == nullptr) {
		printf("Memory error");
	}
}
CCompexVector::CCompexVector(int d,const char* fname) {
	dim = d;
	strcpy(foutput, "rez.txt");
	arr = new double* [2];
	if (!arr) {
		cout << "memory error 1";
	}
	arr[0] = new double[dim];//real part
	arr[1] = new double[dim];//imaginary part
	if (!arr[0] ) {
		cout << "memory error 2";
	}
	if (!arr[1]) {
		cout << "memory error 3";
	}
	for (int i = 0; i < dim; i++) {
		arr[0][i] = 0;
		arr[1][i] = 0;
	}
	ifstream inp;
	
	inp.open(fname);
	char str[20];
	int I = 0;
	int i = 0;
	inp >> I;
	inp >> foutput;
	
	for (int j = 0; j < dim; j++) {
		inp >> arr[0][j];
		inp >> arr[1][j];
	}
	inp.close();
}

void CCompexVector::vec_copy(double* re, double* im, int d) {
	if (d == dim) {
		for (int i = 0; i < dim; i++ ) {
			arr[0][i] = re[i];
			arr[1][i] = im[i];
		}
	}
}
double* CCompexVector::get_re_p() {
	return arr[0];
}
double* CCompexVector::get_im_p() {
	return arr[1];
}

int CCompexVector::standart_out() {
	for (int i = 0; i < dim; i++) {
		if (arr[1][i] > 0) {
			cout << arr[0][i] << " + " << arr[1][i] << "i, ";
		}
		if (arr[1][i] < 0) {
			cout << arr[0][i] << " " << arr[1][i] << "i, ";
		}
		if (arr[1][i] == 0) {
			cout << arr[0][i] << ", ";
		}
	}
	return 1;
}
