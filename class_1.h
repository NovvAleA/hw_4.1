#pragma once
#include "class.h"

class CCompexVector1 : public CCompexVector {
public:
	CCompexVector1(int dim) :CCompexVector(dim) {}
	CCompexVector1(int dim,const char* finput) :CCompexVector(dim, finput) {}
	int output() override;
	using CCompexVector::CCompexVector;
	using CCompexVector:: operator=;
	using CCompexVector:: operator+=;
	using CCompexVector:: operator-=;
	using CCompexVector:: operator!=;
};