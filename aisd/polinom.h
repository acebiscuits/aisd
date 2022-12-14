#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <cmath>
#include <iostream>
#ifndef FILE_H
#define FILE_H

using namespace std;

class polinom
{

protected:
	int size;
	struct P;
	P* head = NULL;
public:

	friend polinom operator *(const double& val, polinom& obj);

	friend ostream& operator << (ostream& os, const polinom& set);

	polinom(int sizem = 0);

	polinom(const polinom& obj);

	~polinom();

	double getcoeff(int i);

	void task();

	double operator [](const int& exp);

	void set(const double& coeff, const int& exp);

	bool operator == (const polinom& obj) const;

	polinom operator +(const polinom& obj);

	polinom operator -(const polinom& obj);

	polinom operator *(const double& val);

	double calculate(const double& val);

	//void print()const;
};


#endif