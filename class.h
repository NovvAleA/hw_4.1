#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include  < fstream >


using namespace std;
class CCompexVector {
protected:
	int dim;
	double** arr;
	char foutput[60];
public:
	CCompexVector(int d);
	CCompexVector(CCompexVector& other) {
		dim = other.get_dim();
		vec_copy(other.get_real(), other.get_imag(), other.get_dim());
	}
	CCompexVector(int d,const char* finput);
	
	double get_real_ip(int i) {
		return arr[0][i];
	}
	double get_imag_ip(int i) {
		return arr[1][i];
	}

	double* get_real() {
		return arr[0];
	}
	double* get_imag() {
		return arr[1];
	}
	
	double* get_re_p();
	double* get_im_p();
	char* get_foutput() {
		return foutput;
	}

	int get_dim() { return dim; }

	void set_fname(char* fname) {
		strcpy(foutput, fname);
	}
	void set_ip(double real, double imag, int pos_n) {
		arr[0][pos_n] = real;
		arr[1][pos_n] = imag;

	}
	void vec_copy(double* re, double* im, int d);
	

    virtual int output() = 0;
	int standart_out();
	//virtual ComplexNumber operator*() = 0;
	CCompexVector& operator+=( CCompexVector& second);
	CCompexVector& operator-=(CCompexVector& second);
	CCompexVector& operator=( CCompexVector& other);
	int operator!=(CCompexVector& other);
	 ~CCompexVector() {
		 delete[] arr[0];
		 delete[] arr[1];
		 delete[] arr;
	 }
};

class ComplexNumber {
public:
	double re;
	double im;
	ComplexNumber() {
		re = 0;
		im = 0;
	}
	ComplexNumber (ComplexNumber& other) {
		re = other.re;
		im = other.im;
	}
	ComplexNumber& operator=(const ComplexNumber& other) {		
		re = other.re;
		im = other.im;
		return *this;
	}
	void print() {
		if (im > 0 ) {
			if (re != 0) {
				cout << re << " + " << im << "i, ";
			}
			else {cout << im << "i, ";}
		}
		if (im < 0) {
			if(re != 0){
				cout << re << " " << im << "i, ";
			}
			else { cout << im << "i,"; }		
		}
		if (im == 0) {
			cout << re << ", ";
		}
	}

	void file_otput(char* foutput) {
		ofstream out;
		out.open(foutput, ios_base::app);
		if (im > 0) {
			if (re != 0) {
				out << re << " + " << im << "i, ";
			}
			else { out << im << "i, "; }
		}
		if (im < 0) {
			if (re != 0) {
				out << re << " " << im << "i, ";
			}
			else { out << im << "i,"; }
		}
		if (im == 0) {
			out << re << ", ";
		}
		out << "\n\n";
		out.close();
	}
};

