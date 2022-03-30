#include "functions.h"
#include  < fstream >

CCompexVector** fscan_data_and_output(const char* fname, int dim) {
	ifstream inp;
	inp.open(fname);
	char str[20];
	int I = 0;
	int  i = 0;
	double re, im = 0;
	

	if (!inp.is_open()) {
		printf("Fileread error!");
	}

	CCompexVector** arr;
	arr = new CCompexVector*[10];
	while (inp >> I) {
		inp >> str;
		if (I == 0) {
			arr[i] = new CCompexVector0(dim);	
		}
		if (I == 1) {
			arr[i] = new CCompexVector1(dim);
		}
		arr[i]->set_fname(str);
		for (int j = 0; j < dim; j++) {
			inp >> re;
			inp >> im;
			arr[i]->set_ip(re, im, j);
		}
		arr[i]->output();
		i++;
	}
	
	
	inp.close();
	return arr;
}
CCompexVector** fscan_data(const char* fname, int dim) {
	ifstream inp;
	inp.open(fname);
	char str[20];
	int I = 0;
	int  i = 0;
	double re, im = 0;


	if (!inp.is_open()) {
		printf("Fileread error!");
	}

	CCompexVector** arr;
	arr = new CCompexVector * [10];
	while (inp >> I) {
		inp >> str;
		if (I == 0) {
			arr[i] = new CCompexVector0(dim);
		}
		if (I == 1) {
			arr[i] = new CCompexVector1(dim);
		}
		arr[i]->set_fname(str);
		for (int j = 0; j < dim; j++) {
			inp >> re;
			inp >> im;
			arr[i]->set_ip(re, im, j);
		}
		//arr[i]->output();
		i++;
	}


	inp.close();
	return arr;
}
CCompexVector** fscan_data(const char* fname, int dim, int* arrdim) {
	ifstream inp;
	inp.open(fname);
	char str[20];
	int I = 0;
	int  i = 0;
	double re, im = 0;


	if (!inp.is_open()) {
		printf("Fileread error!");
	}

	CCompexVector** arr;
	arr = new CCompexVector * [10];
	while (inp >> I) {
		inp >> str;
		if (I == 0) {
			arr[i] = new CCompexVector0(dim);
		}
		if (I == 1) {
			arr[i] = new CCompexVector1(dim);
		}
		arr[i]->set_fname(str);
		for (int j = 0; j < dim; j++) {
			inp >> re;
			inp >> im;
			arr[i]->set_ip(re, im, j);
		}
		//arr[i]->output();
		i++;
	}
	*arrdim = i;


	inp.close();
	return arr;
}

int create_CCV(const char* fname, int dim) {
	ifstream inp;
	inp.open(fname);
	char str[20];
	int I = 0;
	int  i = 0;
	double re, im = 0;


	if (!inp.is_open()) {
		printf("Fileread error!");
	}

	
	inp >> I;
	inp >> str;
	if (I == 0) {
		CCompexVector0 A(dim);
		A.set_fname(str);
		for (int j = 0; j < dim; j++) {
			inp >> re;
			inp >> im;
            A.set_ip(re,im, j);
		}
		A.standart_out();	
	}
	if (I == 1) {
		CCompexVector1 A(dim);
		A.set_fname(str);
		for (int j = 0; j < dim; j++) {
			inp >> re;
			inp >> im;
			A.set_ip(re, im, j);
		}
		A.standart_out();
	}
	
	inp.close();


	return 0;
}

int create_CCV_and_fout(const char* fname, int dim) {
	ifstream inp;
	inp.open(fname);
	char str[20];
	int I = 0;
	int  i = 0;
	double re, im = 0;

	if (!inp.is_open()) {
		printf("Fileread error!");
	}

	inp >> I;
	inp >> str;
	if (I == 0) {
		CCompexVector0 A(dim);
		A.set_fname(str);
		for (int j = 0; j < dim; j++) {
			inp >> re;
			inp >> im;
			A.set_ip(re, im, j);
		}
		A.output();
	}
	else if (I == 1) {
		CCompexVector1 A(dim);
		A.set_fname(str);
		for (int j = 0; j < dim; j++) {
			inp >> re;
			inp >> im;
			A.set_ip(re, im, j);
		}
		A.output();
	}
	else {
		cout << "I != 0 and != 1";
	}

	inp.close();
	return 0;
}


