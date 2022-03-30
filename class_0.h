#pragma once
#include "class.h"

class CCompexVector0 : public CCompexVector {
public:
	CCompexVector0(int dim):CCompexVector(dim) {}
	CCompexVector0(int dim,const char* finput) :CCompexVector(dim, finput) {}
	int output() override;
	using CCompexVector::CCompexVector;
	using CCompexVector:: operator=;
	using CCompexVector:: operator+=;
	using CCompexVector:: operator-=;
	using CCompexVector:: operator!=;
};