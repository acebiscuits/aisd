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
	polinom(int sizem = 0)
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

	polinom(const polinom& obj)
	{
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

	~polinom()
	{

		P* tmp;
		while(head)
		{
			tmp = head;
			head = head->next;
			delete tmp;

		}
	}
	double operator [](const int exp)
	{
		if (this->head)//---------------THROW если нет головы
		{
			if (exp > 0 && exp <= this->head->exp) //-------------------THROW если заданная степень меньше 0 или больше наибольшей в многочлене
			{
				P* tmp = this->head;
				while (tmp->exp < exp && tmp != NULL)
				{
					tmp = tmp->next;
				}
				if (tmp->exp == exp)//----------------------THROW если нет коэффициента при заданной степени(те = 0)
				{
					return tmp->coeff;
				}
			}
		}
			

	}

	void set(const double coeff, const int exp)
	{
		
		if (this->head)
		{
			P* tmp = this->head;

			while (tmp->exp < exp && tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			if (tmp->exp == exp)
			{
				tmp->coeff = coeff;
			}
			else
			{
				tmp->next = new P;
				tmp = tmp->next;
				tmp->coeff = coeff;
			}
		}
		else
		{
			this->head = new P;
			this->head->coeff = coeff;
			this->head->exp = exp;
			this->head->next = NULL;
		}
	}

	polinom operator +(const polinom& obj)
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

	polinom operator -(const polinom& obj) 
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

	polinom operator *(const double val)
	{
		P* tmp_this = this->head;

		while (tmp_this)
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

	double calculate(const double val)
	{

		double res = 0;
		P * tmp_this = this->head;

		while (tmp_this)
		{
			res += tmp_this->coeff * pow(val, tmp_this->exp);
			tmp_this = tmp_this->next;
		} 

		return res;
	}

	void print()const
	{
		if (this->head)//-----------THROW(esli nado)
		{
			P* tmp = this->head;
			while (tmp->next)
			{
				cout << " " << tmp->coeff << "*x^" << tmp->exp << " +";
				tmp = tmp->next;
			}
			cout << " " << tmp->coeff << "*x^" << tmp->exp;
		}
	}

};
polinom operator *(const double val, const polinom& obj )
{
	polinom::P* tmp_obj = obj.head;

	while (tmp_obj)
	{

		tmp_obj->coeff *= val;
		tmp_obj = tmp_obj->next;

	}

	return obj;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int ch = 0;
	do
	{
		cout << "Создать многочлен - 1" << endl << "Закончить - 0" << endl;
		cin >> ch;

		while (ch != 1 || ch != 0)
		{
			cout << "Создать многочлен - 1" << endl << "Закончить - 0" << endl;
			cin >> ch;
		}

		if (ch == 1)
		{
			cout << "Введите степень многочлена" << endl;
			int size = 0;
			cin >> size;

			while(size<0)
			{
				cout << "Введите положительную степень многочлена" << endl;
				cin >> size;
			}

			polinom CRPolinom(size);

			cout << "Создать новый многочлен - 1" << endl;
			cout << "Посмотреть коэффициент при заданной степени - 2" << endl;
			cout << "Установить коэффициент при заданной степени - 3" << endl;
			cout << "Сложить два многочлена - 4" << endl;
			cout << "Вычесть один многочлен из другого - 5" << endl;
			cout << "Умножить многочлен на скаляр - 6" << endl;
			cout << "Вычисление значение многочлена при заданном х - 7" << endl;
			cout << "Закончить - 0" << endl;
			cin >> ch;
			while (ch != 2 || ch != 3 || ch != 4 || ch != 5 || ch != 6 || ch != 7 || ch != 0)
			{

				cout << "Посмотреть коэффициент при заданной степени - 2" << endl;
				cout << "Установить коэффициент при заданной степени - 3" << endl;
				cout << "Сложить два многочлена - 4" << endl;
				cout << "Вычесть один многочлен из другого - 5" << endl;
				cout << "Умножить многочлен на скаляр - 6" << endl;
				cout << "Вычисление значение многочлена при заданном х - 7" << endl;
				//---------------------------------------------------------------------дать возможность создать новый многочлен
				cout << "Закончить - 0" << endl;
				cin >> ch;

			}

			if (ch == 1)
			{
				cout << "Введите степень многочлена" << endl;
				int size = 0;
				cin >> size;

				while (size < 0)
				{
					cout << "Введите положительную степень многочлена" << endl;
					cin >> size;
				}
				
				polinom NPolinom(size);
				CRPolinom = NPolinom;

			}

			if (ch == 2)
			{

				int exp;
				cout << "Введите степень многочлена" << endl;
				cin >> exp;
				while (exp < 0)
				{
					cout << "Введите степень многочлена" << endl;
					cin >> exp;
				}

				cout << "Коэффициент при заданной степени: " << CRPolinom[exp] << endl;

			}

			if (ch == 3)
			{

				int exp;
				cout << "Введите степень многочлена" << endl;
				cin >> exp;
				while (exp < 0)
				{
					cout << "Введите степень многочлена" << endl;
					cin >> exp;
				}

				double coeff = 0;
				cout << "Введите новый коэффициент" << endl;
				cin >> coeff;
				CRPolinom.set(coeff, exp);

				cout << "Результат: ";
				CRPolinom.print();
				cout << endl;

			}

			if (ch == 4)
			{

				cout << "Многчлен: ";
				CRPolinom.print();
				cout << endl;

				int sizem;
				cout << "Введите степень многочлена, с которым нужно сложить: " << endl;
				cin >> sizem;
				polinom SECPolinom(sizem);

				CRPolinom + SECPolinom;

				cout << "Результат: ";
				CRPolinom.print();
				cout << endl;

			}

			if (ch == 5)
			{

				cout << "Многчлен: ";
				CRPolinom.print();
				cout << endl;

				int sizem;
				cout << "Введите степень многочлена, который нужно вычисть: " << endl;
				cin >> sizem;
				polinom SECPolinom(sizem);

				CRPolinom - SECPolinom;

				cout << "Результат: ";
				CRPolinom.print();
				cout << endl;

			}

			if (ch == 6)
			{

				cout << "Многчлен: ";
				CRPolinom.print();
				cout << endl;

				double val;
				cout << "Введите число, на которое нужно умножить многочлен: " << endl;
				cin >> val;
				CRPolinom * val;

				cout << "Результат: ";
				CRPolinom.print();
				cout << endl;

			}

			if (ch == 7)
			{

				cout << "Многчлен: ";
				CRPolinom.print();
				cout << endl;

				double val;
				cout << "Введите число, относительно которого нужно посчитать многочлен: " << endl;
				cin >> val;

				cout << "Результат: " << CRPolinom.calculate(val) << endl;

			}

			if (ch == 0)
			{
				break;
			}

		}

	} while (ch != 0);

	return 0;
}//в вычитании проверить еслт становится нулем и проверить внимательно на отсутствие ошибок весь код


	/*int size = 0;

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
	polinom polinom2(size);

	polinom new_polinom = polinom1 + polinom2;
	polinom new_polinom2 = new_polinom - polinom1;
	polinom new_polinom3 = polinom2 + polinom1;
	new_polinom * 3;
	3 * new_polinom3;
	polinom2.calculate(3);
	*/