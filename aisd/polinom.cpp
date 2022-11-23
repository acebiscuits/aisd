#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <cmath>
#include <math.h>
#include <cstdio>
#include <iostream>
#include "polinom.h"
#include <limits>
using namespace std;

struct polinom::P
{

	double coeff;
	int exp;
	P* next;

};
double polinom::getcoeff(int i)
{
	double c;
	cout << "введите коэффициент многочлена при степени " << i << ": ";
	cin >> c;
	cout << endl;
	return c;
}
polinom::polinom(int sizem)
{

	int new_sizem = -1;

	if (sizem > -1)
	{

		int i = 0;
		double c;

		while (head == NULL && i <= sizem)
		{

			c = this->getcoeff(i);

			if (c != 0)
			{

				head = new P;
				head->coeff = c;
				head->exp = i;
				head->next = NULL;
				new_sizem = i;
				i++;

			}
			else
			{

				i++;

			}
		}

		P* ptr = head;

		for (i; i <= sizem; i++)
		{

			c = this->getcoeff(i);

			if (c != 0)
			{

				ptr->next = new P;
				ptr = ptr->next;
				ptr->coeff = c;
				ptr->exp = i;
				ptr->next = NULL;
				new_sizem = i;

			}
			else
			{

				i++;
				continue;

			}
		}
	}

	this->size = new_sizem;

};

bool polinom::operator == (const polinom& obj) const
{

	if (this->size == obj.size)
	{
		P* tmp_this = this->head;
		P* tmp_obj = obj.head;
		for (int i = 0; i < this->size; i++)
		{

			if (tmp_this->exp == tmp_obj->exp && std::fabs(tmp_this->coeff - tmp_obj->coeff) < std::numeric_limits<double>::epsilon())
			{
				tmp_obj = tmp_obj->next;
				tmp_this = tmp_this->next;
			}
			else
			{
				return false;
			}

		}
		return true;
	}
	return false;

}

polinom::polinom(const polinom& obj)
{
	try {
		if (this->head)
		{

			P* tmp;

			while (this->head)
			{

				tmp = this->head;
				this->head = this->head->next;
				delete tmp;

			}
		}

		this->head = NULL;

		if (obj.head)
		{

			this->head = new P;
			P* tmp_this = this->head;
			P* tmp_obj = obj.head;
			tmp_this->coeff = tmp_obj->coeff;
			tmp_this->exp = tmp_obj->exp;
			tmp_this->next = NULL;
			tmp_obj = tmp_obj->next;

			while (tmp_obj)
			{

				tmp_this->next = new P;
				tmp_this = tmp_this->next;
				tmp_this->coeff = tmp_obj->coeff;
				tmp_this->exp = tmp_obj->exp;
				tmp_this->next = NULL;
				tmp_obj = tmp_obj->next;

			}

			this->size = obj.size;

		}
	}
	catch (...)
	{
		cout << "что-то пошло не так" << endl;
	}
}

polinom::~polinom()
{

	P* tmp;

	while (head)
	{

		tmp = head;
		head = head->next;
		delete tmp;

	}
}

ostream& operator << (ostream& os, const polinom& obj)
{

	if (obj.head)
	{
		polinom::P* tmp = obj.head;
		while (tmp->next)
		{

			os << tmp->coeff << "*x^" << tmp->exp << " + ";
			tmp = tmp->next;

		}
		os << tmp->coeff << "*x^" << tmp->exp;;
	}
	else
	{
		os << "в многочлене нет ни одного элемента" << endl;
	}
	return os;
}

void polinom::task()
{


	if (this->size != 3)
	{
		cout << "многочлен не 3 степени" << endl;

	}
	double* arr = new double[3];
	double* res = new double[3];
	P* tmp = this->head;
	P* tmpadd = this->head;
	double add;
	while (tmpadd->next)
	{


		tmpadd = tmpadd->next;

	}


	add = tmpadd->coeff;
	for (int i = 0; i < this->size; i++)
	{

		if (tmp)
		{

			arr[i] = tmp->coeff / add;
			tmp = tmp->next;
		}



	}
	/*double p = (3 * arr[3] * arr[1] - arr[2] * arr[2]) / (3 * arr[3] * arr[3]);
	double q = (2 * arr[2] * arr[2] * arr[2] - 9 * arr[3] * arr[2] * arr[1] + 27 * arr[3] * arr[3] * arr[0]) / 27 * arr[3] * arr[3] * arr[3];
	double D = (q / 2) * (q / 2) + (p / 3) * (p / 3) * (p / 3);


	if (D < 0)
	{
		double Fi;
		if (q < 0)
		{


			Fi = atan((sqrt((-1) * D)) / (q / 2));

		}
		else if (q > 0)
		{

			Fi = atan(((sqrt((-1) * D)) / (q / 2)) + acos(-1));

		}
		else
		{

			Fi = (acos(-1) / 2);

		}
		res[0] =    2 * sqrt(  (-1)*(p/3)   )    * cos(Fi / 3) - (arr[2] / (3 * arr[3]));
		res[1] = (2 * sqrt((-1) * (p / 3)) * cos((Fi / 3) + (acos(-1) * 2 / 3))) - (arr[2] / (3 * arr[3]));
		res[2] = (2 * sqrt((-1) * (p / 3)) * cos((Fi / 3) + (acos(-1) * 4 / 3))) - (arr[2] / (3 * arr[3]));


		cout << "три вещестыенных корня,x1: " << res[0] << " x2: " << res[1] << " x3: " << res[2] << endl;
		delete [] arr;
		delete[] res;
	}
	else if (D > 0)
	{
		if (q == 0)
		{
			res[0] = -(1)* (arr[2] / (3 * arr[3]));


		}
		else
		{

		res[0] = cbrt(((-1) * q / 2) + sqrt(D)) + cbrt(((-1) * q / 2) - sqrt(D)) -(arr[2] / (3 * arr[3]));
		}
		cout << "один вещественный корень, x1: " << res[0] <<  endl;
		delete [] arr;
		delete[] res;
	}

	else
	{

		double a = cbrt(-8);

		res[0] = 2 * cbrt(((-1)*q)/2) - (arr[2] / (3 * arr[3]));
		res[1] = (-1) * cbrt(((-1) * q) / 2) - (arr[2] / (3 * arr[3]));
		cout << "два вещественных корня x1: " << res[0] << " x2: " << res[1] << endl;
		delete [] arr;
		delete[] res;
	}*/


	double Q = (arr[2] * arr[2] - 3 * arr[1]) / 9;
	double R = (2 * arr[2] * arr[2] * arr[2] - 9 * arr[2] * arr[1] + 27 * arr[0]) / 54;
	double S = Q * Q * Q - R * R;


	if (S > 0)
	{


		double Fi = pow(3, -1) * acos(R / sqrt(Q * Q * Q));
		res[0] = -2 * sqrt(Q) * cos(Fi) - arr[2] / 3;
		res[1] = -2 * sqrt(Q) * cos(Fi + (2 * pow(3, -1)) * acos(-1)) - arr[2] / 3;
		res[2] = -2 * sqrt(Q) * cos(Fi - (2 * pow(3, -1)) * acos(-1)) - arr[2] / 3;
		cout << "три вещестыенных корня,x1: " << res[0] << " x2: " << res[1] << " x3: " << res[2] << endl;
		delete[] arr;
		delete[] res;
	}

	else if (S < 0)
	{
		if (Q > 0)

		{


			double e = exp(1);
			double z = abs(R) / sqrt(Q * Q * Q);
			double Fi = pow(3, -1) * log(z + sqrt(z * z - 1));
			double Fi1 = (-1) * Fi;

			double sgn = (R > 0) ? 1 : ((R < 0) ? -1 : 0);
			res[0] = (-2) * sgn * sqrt(Q) * ((pow(e, Fi) + pow(e, Fi1)) / 2) - arr[2] / 3;

			cout << "один вещественный корень, x1: " << res[0] << endl;
			delete[] arr;
			delete[] res;


		}
		else if (Q < 0)
		{

			double e = exp(1);
			double z = abs(R) / sqrt(abs(Q * Q * Q));
			double lg = z + sqrt(z * z + 1);
			double Fi = log(lg);

			double k = pow(3, -1);
			double Fi1 = k * Fi;

			double sgn = (R > 0) ? 1 : ((R < 0) ? -1 : 0);
			res[0] = (-2) * sgn * sqrt(abs(Q)) * ((pow(e, Fi) - pow(e, Fi1)) / 2) - arr[2] / 3;
			cout << "один вещественный корень, x1: " << res[0] << endl;
			delete[] arr;
			delete[] res;

		}
		else
		{

			res[0] = (-1) * cbrt((arr[0] - (arr[2] * arr[2] * arr[2] / 27))) - arr[2] / 3;
			cout << "один вещественный корень, x1: " << res[0] << endl;
			delete[] arr;
			delete[] res;
		}
	}

	else
	{

		res[0] = -2 * cbrt(R) - arr[2] / 3;
		res[1] = cbrt(R) - arr[2] / 3;

		cout << "два вещественных корня x1: " << res[0] << " x2: " << res[1] << endl;
		delete[] arr;
		delete[] res;
	}

}

double polinom::operator [](const int& exp)
{
	try
	{
		if (this->head)
		{

			if (exp >= 0 && exp <= this->size)
			{

				P* tmp = this->head;

				while (tmp->exp < exp && tmp != NULL)
				{

					tmp = tmp->next;

				}
				if (tmp && tmp->exp == exp)
				{

					return tmp->coeff;

				}
				else
				{
					throw"в многочлене нет элемента с заданной степенью";
				}

			}
			else if (exp < 0)
			{
				throw"степень меньше нуля";
			}
			else
			{
				throw"степень больше максимальной в данном многочлене";
			}
		}
		else
		{
			throw"в многочлене нет ни одного элемента";
		}
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	catch (...)
	{
		cout << "что-то пошло не так" << endl;
	}
}

void polinom::set(const double& coeff, const int& exp)
{
	try
	{
		if (exp <= this->size) //--------------throw
		{
			if (head)
			{

				P* tmp = head;
				//здесь *?
				while (tmp->exp < exp && tmp)
				{

					tmp = tmp->next;

				}
				if (tmp && tmp->exp == exp)
				{

					tmp->coeff = coeff;

				}
				else if (exp < this->size)//сделать счетчик *? чтобы не вышел за сайз
				{

					P* ptr = head;

					while (ptr->next != tmp)
					{

						ptr = ptr->next;

					}

					ptr->next = new P;
					ptr = ptr->next;
					ptr->coeff = coeff;
					ptr->exp = exp;
					ptr->next = tmp;

				}
			}
			else
			{

				head = new P;
				head->coeff = coeff;
				head->exp = exp;
				head->next = NULL;

			}
		}
		else
		{
			throw"размерность массива меньше заданной степени";
		}
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	catch (...)
	{
		cout << "что-то пошло не так" << endl;
	}
}

polinom polinom::operator +(const polinom& obj)
{
	try {
		polinom new_polinom(-1);

		if (this->head != NULL && obj.head != NULL)
		{

			new_polinom.head = new P;
			P* tmp = new_polinom.head;
			P* tmp_this = this->head;
			P* tmp_obj = obj.head;

			if (tmp_this->exp > tmp_obj->exp)
			{

				tmp->coeff = tmp_obj->coeff;
				tmp->exp = tmp_obj->exp;
				tmp->next = NULL;
				tmp_obj = tmp_obj->next;

			}
			else if (tmp_this->exp == tmp_obj->exp)
			{

				tmp->coeff = tmp_obj->coeff + tmp_this->coeff;
				tmp->exp = tmp_obj->exp;
				tmp->next = NULL;
				tmp_obj = tmp_obj->next;
				tmp_this = tmp_this->next;

			}
			else
			{

				tmp->coeff = tmp_this->coeff;
				tmp->exp = tmp_this->exp;
				tmp->next = NULL;
				tmp_this = tmp_this->next;

			}

			if (this->size >= obj.size)
			{
				for (int i = 1; i <= this->size; i++)
				{
					if (tmp_this != NULL && tmp_obj != NULL && tmp_this->exp > tmp_obj->exp)
					{
						while (tmp_obj->exp < tmp_this->exp && tmp_obj != NULL)
						{

							tmp->next = new P;
							tmp = tmp->next;
							tmp->coeff = tmp_obj->coeff;
							tmp->exp = tmp_obj->exp;
							tmp_obj = tmp_obj->next;
							tmp->next = NULL;

						}
					}
					else if (tmp_this != NULL && tmp_obj != NULL && tmp_this->exp < tmp_obj->exp)
					{
						while (tmp_this->exp < tmp_obj->exp && tmp_this != NULL)
						{

							tmp->next = new P;
							tmp = tmp->next;
							tmp->coeff = tmp_this->coeff;
							tmp->exp = tmp_this->exp;
							tmp_this = tmp_this->next;
							tmp->next = NULL;

						}
					}
					else if (tmp_this != NULL && tmp_obj != NULL)
					{

						tmp->next = new P;
						tmp = tmp->next;
						tmp->coeff = tmp_this->coeff + tmp_obj->coeff;
						tmp->exp = tmp_this->exp;
						tmp_this = tmp_this->next;
						tmp_obj = tmp_obj->next;
						tmp->next = NULL;

					}
					else if (tmp_this != NULL)
					{

						tmp->next = new P;
						tmp = tmp->next;
						tmp->coeff = tmp_this->coeff;
						tmp->exp = tmp_this->exp;
						tmp_this = tmp_this->next;
						tmp->next = NULL;

					}
				}

				new_polinom.size = this->size;
				return new_polinom;

			}

			else //if (this->size < obj.size)
			{
				for (int i = 1; i <= obj.size; i++)
				{
					if (tmp_this != NULL && tmp_obj != NULL && tmp_this->exp > tmp_obj->exp)
					{
						while (tmp_obj->exp < tmp_this->exp && tmp_obj != NULL)
						{

							tmp->next = new P;
							tmp = tmp->next;
							tmp->coeff = tmp_obj->coeff;
							tmp->exp = tmp_obj->exp;
							tmp_obj = tmp_obj->next;
							tmp->next = NULL;

						}
					}
					else if (tmp_this != NULL && tmp_obj != NULL && tmp_this->exp < tmp_obj->exp)
					{
						while (tmp_this->exp < tmp_obj->exp && tmp_this != NULL)
						{

							tmp->next = new P;
							tmp = tmp->next;
							tmp->coeff = tmp_this->coeff;
							tmp->exp = tmp_this->exp;
							tmp_this = tmp_this->next;
							tmp->next = NULL;

						}
					}
					else if (tmp_this != NULL && tmp_obj != NULL)
					{

						tmp->next = new P;
						tmp = tmp->next;
						tmp->coeff = tmp_this->coeff + tmp_obj->coeff;
						tmp->exp = tmp_this->exp;
						tmp_this = tmp_this->next;
						tmp_obj = tmp_obj->next;
						tmp->next = NULL;

					}
					else if (tmp_obj != NULL)
					{

						tmp->next = new P;
						tmp = tmp->next;
						tmp->coeff = tmp_obj->coeff;
						tmp->exp = tmp_obj->exp;
						tmp_obj = tmp_obj->next;
						tmp->next = NULL;

					}
				}

				new_polinom.size = obj.size;
				return new_polinom;
			}
		}
		else
		{
			if (this->head != NULL && obj.head == NULL)
			{

				new_polinom.head = new P;
				P* tmp = new_polinom.head;
				P* tmp_this = this->head;
				tmp->exp = tmp_this->exp;
				tmp->coeff = tmp_this->coeff;
				tmp_this = tmp_this->next;
				tmp->next = NULL;
				for (int i = 1; i <= this->size; i++)
				{
					if (tmp_this != NULL)
					{

						tmp->next = new P;
						tmp = tmp->next;
						tmp->coeff = tmp_this->coeff;
						tmp->exp = tmp_this->exp;
						tmp_this = tmp_this->next;
						tmp->next = NULL;

					}
				}

				new_polinom.size = this->size;
				return new_polinom;

			}
			else if (this->head == NULL && obj.head != NULL)
			{

				new_polinom.head = new P;
				P* tmp = new_polinom.head;
				P* tmp_obj = obj.head;
				tmp->exp = tmp_obj->exp;
				tmp->coeff = tmp_obj->coeff;
				tmp_obj = tmp_obj->next;
				tmp->next = NULL;

				for (int i = 1; i <= obj.size; i++)
				{
					if (tmp_obj != NULL)
					{

						tmp->next = new P;
						tmp = tmp->next;
						tmp->coeff = tmp_obj->coeff;
						tmp->exp = tmp_obj->exp;
						tmp_obj = tmp_obj->next;
						tmp->next = NULL;

					}
				}

				new_polinom.size = obj.size;
				return new_polinom;

			}
			else
			{

				return new_polinom;

			}
		}
	}
	catch (...)
	{
		cout << "что-то пошло не так";
	}
}

polinom polinom::operator -(const polinom& obj)
{
	try {
		polinom new_polinom(-1);


		if (this->head != NULL && obj.head != NULL)
		{
			P* tmp_this = this->head;
			P* tmp_obj = obj.head;
			if (tmp_this->exp > tmp_obj->exp)
			{
				new_polinom.head = new P;
				//P* tmp = new_polinom.head;
				new_polinom.head->coeff = (-1) * tmp_obj->coeff;
				new_polinom.head->exp = tmp_obj->exp;
				new_polinom.head->next = NULL;
				new_polinom.size = tmp_obj->exp;
				tmp_obj = tmp_obj->next;

			}
			else if (tmp_this->exp == tmp_obj->exp)
			{
				while (tmp_this && tmp_obj && tmp_this->exp == tmp_obj->exp && std::fabs(tmp_this->coeff - tmp_obj->coeff) < std::numeric_limits<double>::epsilon())
				{

					tmp_obj = tmp_obj->next;
					tmp_this = tmp_this->next;

				}
				if (tmp_this && tmp_obj && tmp_this->exp == tmp_obj->exp)
				{

					new_polinom.head = new P;
					new_polinom.head->coeff = tmp_this->coeff - tmp_obj->coeff;
					new_polinom.head->exp = tmp_obj->exp;
					new_polinom.head->next = NULL;
					new_polinom.size = tmp_obj->exp;
					tmp_obj = tmp_obj->next;
					tmp_this = tmp_this->next;

				}
				else if (tmp_this && tmp_obj && tmp_this->exp < tmp_obj->exp)
				{

					new_polinom.head = new P;
					new_polinom.head->coeff = tmp_this->coeff;
					new_polinom.head->exp = tmp_this->exp;
					new_polinom.head->next = NULL;
					new_polinom.size = tmp_this->exp;
					tmp_this = tmp_this->next;


				}
				else if (tmp_this && tmp_obj && tmp_this->exp > tmp_obj->exp)
				{

					new_polinom.head = new P;
					new_polinom.head->coeff = (-1) * tmp_obj->coeff;
					new_polinom.head->exp = tmp_obj->exp;
					new_polinom.head->next = NULL;
					new_polinom.size = tmp_obj->exp;
					tmp_obj = tmp_obj->next;
				}
				else if ((tmp_this && !tmp_obj) || (tmp_obj && !tmp_this))
				{
					new_polinom.head = new P;
					if (tmp_this)
					{
						new_polinom.head->coeff = tmp_this->coeff;
						new_polinom.head->exp = tmp_this->exp;
						new_polinom.head->next = NULL;
						new_polinom.size = tmp_this->exp;
						tmp_this = tmp_this->next;
					}
					else
					{
						new_polinom.head->coeff = (-1) * tmp_obj->coeff;
						new_polinom.head->exp = tmp_obj->exp;
						new_polinom.head->next = NULL;
						new_polinom.size = tmp_obj->exp;
						tmp_obj = tmp_obj->next;
					}
				}
				else
				{
					return new_polinom;
				}
			}
			else
			{
				new_polinom.head = new P;
				new_polinom.head->coeff = tmp_this->coeff;
				new_polinom.head->exp = tmp_this->exp;
				new_polinom.head->next = NULL;
				new_polinom.size = tmp_this->exp;
				tmp_this = tmp_this->next;

			}
			P* tmp = new_polinom.head;
			if (this->size >= obj.size)
			{
				for (int i = 1; i <= this->size; i++)
				{
					if (tmp_this != NULL && tmp_obj != NULL && tmp_this->exp > tmp_obj->exp)
					{
						while (tmp_obj->exp < tmp_this->exp && tmp_obj != NULL)
						{

							tmp->next = new P;
							tmp = tmp->next;
							tmp->coeff = (-1) * tmp_obj->coeff;
							tmp->exp = tmp_obj->exp;
							new_polinom.size = tmp_obj->exp;
							tmp_obj = tmp_obj->next;
							tmp->next = NULL;

						}
					}
					else if (tmp_this != NULL && tmp_obj != NULL && tmp_this->exp < tmp_obj->exp)
					{
						while (tmp_this->exp < tmp_obj->exp && tmp_this != NULL)
						{

							tmp->next = new P;
							tmp = tmp->next;
							tmp->coeff = tmp_this->coeff;
							tmp->exp = tmp_this->exp;
							new_polinom.size = tmp_this->exp;
							tmp_this = tmp_this->next;
							tmp->next = NULL;

						}
					}
					else if (tmp_this != NULL && tmp_obj != NULL)
					{
						if (std::fabs(tmp_this->coeff - tmp_obj->coeff) > std::numeric_limits<double>::epsilon())
						{

							tmp->next = new P;
							tmp = tmp->next;
							tmp->coeff = tmp_this->coeff - tmp_obj->coeff;
							tmp->exp = tmp_this->exp;
							new_polinom.size = tmp_this->exp;
							tmp_this = tmp_this->next;
							tmp_obj = tmp_obj->next;
							tmp->next = NULL;

						}
						else
						{

							tmp_this = tmp_this->next;
							tmp_obj = tmp_obj->next;

						}
					}
					else if (tmp_this != NULL)
					{

						tmp->next = new P;
						tmp = tmp->next;
						tmp->coeff = tmp_this->coeff;
						tmp->exp = tmp_this->exp;
						new_polinom.size = tmp_this->exp;
						tmp_this = tmp_this->next;
						tmp->next = NULL;

					}
				}
				return new_polinom;
			}

			else//if (this->size < obj.size)
			{
				for (int i = 1; i <= obj.size; i++)
				{
					if (tmp_this != NULL && tmp_obj != NULL && tmp_this->exp > tmp_obj->exp)
					{
						while (tmp_obj->exp < tmp_this->exp && tmp_obj != NULL)
						{

							tmp->next = new P;
							tmp = tmp->next;
							tmp->coeff = (-1) * tmp_obj->coeff;
							tmp->exp = tmp_obj->exp;
							new_polinom.size = tmp_obj->exp;
							tmp_obj = tmp_obj->next;
							tmp->next = NULL;

						}
					}
					else if (tmp_this != NULL && tmp_obj != NULL && tmp_this->exp < tmp_obj->exp)
					{
						while (tmp_this->exp < tmp_obj->exp && tmp_this != NULL)
						{

							tmp->next = new P;
							tmp = tmp->next;
							tmp->coeff = tmp_this->coeff;
							tmp->exp = tmp_this->exp;
							new_polinom.size = tmp_this->exp;
							tmp_this = tmp_this->next;
							tmp->next = NULL;

						}
					}
					else if (tmp_this != NULL && tmp_obj != NULL)
					{

						if (std::fabs(tmp_this->coeff - tmp_obj->coeff) > std::numeric_limits<double>::epsilon())
						{

							tmp->next = new P;
							tmp = tmp->next;
							tmp->coeff = tmp_this->coeff - tmp_obj->coeff;
							tmp->exp = tmp_this->exp;
							new_polinom.size = tmp_this->exp;
							tmp_this = tmp_this->next;
							tmp_obj = tmp_obj->next;
							tmp->next = NULL;

						}
						else
						{

							tmp_this = tmp_this->next;
							tmp_obj = tmp_obj->next;

						}

					}
					else if (tmp_obj != NULL)
					{

						tmp->next = new P;
						tmp = tmp->next;
						tmp->coeff = (-1) * tmp_obj->coeff;
						tmp->exp = tmp_obj->exp;
						new_polinom.size = tmp_obj->exp;
						tmp_obj = tmp_obj->next;
						tmp->next = NULL;

					}
				}
				return new_polinom;
			}
		}
		else
		{
			if (this->head != NULL && obj.head == NULL)
			{
				new_polinom.head = new P;
				P* tmp = new_polinom.head;
				P* tmp_this = this->head;
				tmp->exp = tmp_this->exp;
				tmp->coeff = tmp_this->coeff;
				new_polinom.size = this->size;
				tmp_this = tmp_this->next;
				tmp->next = NULL;
				for (int i = 1; i <= this->size; i++)
				{
					if (tmp_this != NULL)
					{
						tmp->next = new P;
						tmp = tmp->next;
						tmp->coeff = tmp_this->coeff;
						tmp->exp = tmp_this->exp;
						tmp_this = tmp_this->next;
						tmp->next = NULL;
					}
				}

				return new_polinom;
			}
			else if (this->head == NULL && obj.head != NULL)
			{
				new_polinom.head = new P;
				P* tmp = new_polinom.head;
				P* tmp_obj = obj.head;
				tmp->exp = tmp_obj->exp;
				tmp->coeff = (-1) * tmp_obj->coeff;
				new_polinom.size = obj.size;
				tmp_obj = tmp_obj->next;
				tmp->next = NULL;
				for (int i = 1; i <= obj.size; i++)
				{
					if (tmp_obj != NULL)
					{
						tmp->next = new P;
						tmp = tmp->next;
						tmp->coeff = tmp_obj->coeff;
						tmp->exp = tmp_obj->exp;
						tmp_obj = tmp_obj->next;
						tmp->next = NULL;
					}
				}

				return new_polinom;

			}
			else
			{
				return new_polinom;
			}
		}
	}
	catch (...)
	{
		cout << "что-то пошло не так" << endl;
	}
}

polinom polinom::operator *(const double& val)
{
	try
	{
		if (head && val != 0)
		{
			P* tmp_this = this->head;

			while (tmp_this)
			{

				tmp_this->coeff *= val;
				tmp_this = tmp_this->next;

			}

			return *this;
		}
		else if (head && val == 0)
		{
			P* tmp;

			while (head)
			{

				tmp = head;
				head = head->next;
				delete tmp;

			}
			return *this;
		}
		else
		{
			return *this;
		}
	}
	catch (...)
	{
		cout << "что-то пошло не так" << endl;
	}
	/*
	polinom new_polinom(-1);
	P* tmp = new_polinom.head;
	P* tmp_this = this->head;
	if(this->head)
	{
		new_polinom.head = new P;
		tmp->coeff = tmp_this->coeff * val;
		tmp->exp = tmp_this->exp;
		tmp->next = NULL;
		tmp_this = tmp_this->next;
	}
	while (tmp_this != NULL);
	{
		tmp->next = new P;
		tmp = tmp->next;
		tmp->coeff = tmp_this->coeff * val;
		tmp->exp = tmp_this->exp;
		tmp->next = NULL;
		tmp_this = tmp_this->next;

	}
	*/
}

double polinom::calculate(const double& val)
{

	double res = 0;
	P* tmp_this = this->head;

	while (tmp_this)
	{
		if (tmp_this->coeff)
		{
			res += tmp_this->coeff * pow(val, tmp_this->exp);
			tmp_this = tmp_this->next;
		}
		else
		{
			tmp_this = tmp_this->next;
		}

	}

	return res;
}

/*void polinom::print()const
{
	try {
		if (head)
		{
			P* tmp = this->head;
			while (tmp->next)
			{

				cout << *this <<" + ";
				tmp = tmp->next;

			}
			cout << *this;
		}
		else
		{
			throw"в многочлене нет ни одного элемента";
		}
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	catch (...)
	{
		cout << "что-то пошло не так" << endl;
	}
}*/

polinom operator *(const double& val, polinom& obj)
{
	try {
		polinom::P* tmp_obj = obj.head;

		if (tmp_obj && val != 0)
		{
			while (tmp_obj)
			{

				tmp_obj->coeff *= val;
				tmp_obj = tmp_obj->next;

			}

			return obj;
		}
		else if (tmp_obj && val == 0)
		{
			polinom::P* tmp_obj = obj.head;

			while (tmp_obj)
			{

				tmp_obj = obj.head;
				obj.head = obj.head->next;
				delete tmp_obj;

			}
			return obj;
		}
		else
		{
			return obj;
		}
	}
	catch (...)
	{
		cout << "что-то пошло не так" << endl;
	}
}