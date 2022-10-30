#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <cmath>
#include <iostream>
using namespace std;
class polinom
{
public:
	int size;
	struct P
	{
		double coeff;
		int exp;
		P* next;
	};
	P* head = NULL;
	polinom(int sizem)
	{
		int new_sizem = -1;
		if (sizem > -1)
		{
			int i = 0;
			int c = 0;

			while (head == NULL && i <= sizem) {
				cout << "введите коэффициент многочлена при степени" << i << ":" << endl;
				cin >> c;
				if (c != 0)
				{
					head = new P;
					head->coeff = c;
					head->exp = 0;
					head->next = NULL;
					new_sizem = i;
				}
				else
				{
					i++;
				}
			}
			P* ptr = head;
			for (i; i <= sizem; i++)
			{

				cout << "введите коэффициент многочлена при степени" << i << ":" << endl;
				cin >> c;

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
					continue;
				}
			}
		}
		this->size = new_sizem;
	};

	~polinom()
	{

		while(head->next != NULL)
		{

			P* tmp = head;
			head = head->next;
			delete tmp;

		}
	}
	P& operator [](const int index)
	{
		P* tmp = head;
		for ( int i = 0; i < index; i++ )
		{
			tmp = tmp->next;
		}
		return *tmp;

	}

	void set(const double coeff, P& obj)
	{
		obj.coeff = coeff;
	}

	polinom& operator +(const polinom& obj)
	{

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
				for (int i = 0; i <= this->size; i++)
				{
					if (tmp_this != NULL && tmp_obj != NULL&& tmp_this->exp > tmp_obj->exp)
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
					else if(tmp_this != NULL)
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

			if (this->size < obj.size)
			{
				for (int i = 0; i <= obj.size; i++)
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
						tmp->coeff = tmp_this->coeff;
						tmp->exp = tmp_this->exp;
						tmp_this = tmp_this->next;
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
				return new_polinom;
			}
			else
			{
				return new_polinom;
			}
		}
	}

	polinom& operator -(const polinom& obj)
	{

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
				tmp->coeff = tmp_this->coeff - tmp_obj->coeff;
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
				for (int i = 0; i <= this->size; i++)
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
						tmp->coeff = tmp_this->coeff - tmp_obj->coeff;
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

			if (this->size < obj.size)
			{
				for (int i = 0; i <= obj.size; i++)
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
						tmp->coeff = tmp_this->coeff - tmp_obj->coeff;
						tmp->exp = tmp_this->exp;
						tmp_this = tmp_this->next;
						tmp_obj = tmp_obj->next;
						tmp->next = NULL;
					}
					else if (tmp_obj != NULL)
					{
						tmp->next = new P;
						tmp = tmp->next;
						tmp->coeff = tmp_this->coeff;
						tmp->exp = tmp_this->exp;
						tmp_this = tmp_this->next;
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

	polinom& operator *(const double val)
	{
		P* tmp_this = this->head;

		while (tmp_this != NULL);
		{
			
			tmp_this->coeff *= val;
			tmp_this = tmp_this->next;

		} 

		return *this;

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

	double calculate(const polinom& p, const double val)
	{

		double res = 0;
		P * tmp_this = this->head;

		while (tmp_this != NULL);
		{
			res += tmp_this->coeff * pow(val, tmp_this->exp);
		} 

		return res;
	}

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size = 0;

	printf("\nвведите степень многочлена: ");
	scanf("%d", &size);

	if (size < 0)
	{
		
		printf("\nвведите неотрицательную степень: ");
		scanf("%d", &size);

	}


	polinom polinom1(size);
	polinom1[1];
	polinom1.set(4, polinom1[2]);
	polinom new_polinom(size);
	new_polinom + polinom1;
	new_polinom - polinom1;
	new_polinom * 3;
	new_polinom.calculate(new_polinom, 3);

	return 0;
}