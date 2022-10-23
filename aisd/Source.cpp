#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <cmath>
 
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
	P* head;
	polinom(int sizem)
	{
		this -> size = sizem;
		head = new P;
		P* ptr = head;

		for (int i = size; i >= 0; i--)
		{
			int c = 0;

			printf("\nвведите коэффициент: ");
			scanf("%d", &c);
			ptr->coeff = c;
			ptr->exp = i;

			if (i > 0)
			{
				
				P* elem = new P;
				ptr->next = elem;
				ptr = ptr->next;

			}
			else
			{

				ptr->next = NULL;

			}

		}
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
		for (int i = 0; i < index; i++)
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

		polinom new_polinom(this->size);//ДОБАВИТЬ ЗДЕСЬ И В МИНУСЕ ПРОВЕРКУ НА НУЛЕВОЙ УКАЗАТЕЛЬ НА НЕКСТ (ЕСЛИ САЙЗ БОЛЬШЕ ЧЕМ НА САМОМ ДЕЛЕ ЭЛЕМЕНТОВ)
		P* tmp = new_polinom.head;
		P* tmp_this = this->head;
		P* tmp_obj = obj.head;
		
		if ( this->size >= obj.size )
		{	
			for ( int i = this->size; i >= 0; i-- )
			{

				while ( tmp_this->exp > obj.size )
				{
					tmp->coeff = tmp_this->coeff;
					tmp_this = tmp_this->next;
				}
				for ( int j = obj.size; j >= i; j-- )
				{
					if ( tmp_this->coeff == tmp_obj->coeff )
					{
						tmp->coeff = tmp_this->coeff + tmp->coeff;
					}

					tmp_obj = tmp_obj->next;
				}

				tmp->exp = tmp_this->exp;
				tmp_this = tmp_this->next;
				tmp_obj = obj.head;
				tmp = tmp->next;
			}
		}

		if( this->size < obj.size )
		{ 
			for (int i = obj.size; i >= 0; i--)
			{
				while (tmp_obj->exp > this->size)
				{
					tmp->coeff = tmp_obj->coeff;
					tmp_obj = tmp_obj->next;
				}

				for (int j = this->size; j >= i; j--)
				{
					if (tmp_this->coeff == tmp_obj->coeff)
					{
						tmp->coeff = tmp_this->coeff + tmp->coeff;
					}

					tmp_this = tmp_this->next;
				}

				tmp->exp = tmp_obj->exp;
				tmp_this = this->head;
				tmp_obj = tmp_obj->next;
				tmp = tmp->next;
			}
		}

		return new_polinom;
	}

	polinom& operator -(const polinom& obj)
	{

		polinom new_polinom(this->size);
		P* tmp = new_polinom.head;
		P* tmp_this = this->head;
		P* tmp_obj = obj.head;

		if (this->size >= obj.size)
		{
			for (int i = this->size; i >= 0; i--)
			{

				while (tmp_this->exp > obj.size)
				{
					tmp->coeff = tmp_this->coeff;
					tmp_this = tmp_this->next;
				}
				for (int j = obj.size; j >= i; j--)
				{
					if (tmp_this->coeff == tmp_obj->coeff)
					{
						tmp->coeff = tmp_this->coeff - tmp->coeff;
					}

					tmp_obj = tmp_obj->next;
				}

				tmp->exp = tmp_this->exp;
				tmp_this = tmp_this->next;
				tmp_obj = obj.head;
				tmp = tmp->next;
			}
		}

		if (this->size < obj.size)
		{
			for (int i = obj.size; i >= 0; i--)
			{
				while (tmp_obj->exp > this->size)
				{
					tmp->coeff = tmp_obj->coeff;
					tmp_obj = tmp_obj->next;
				}

				for (int j = this->size; j >= i; j--)
				{
					if (tmp_this->coeff == tmp_obj->coeff)
					{
						tmp->coeff = tmp_this->coeff - tmp->coeff;
					}

					tmp_this = tmp_this->next;
				}

				tmp->exp = tmp_obj->exp;
				tmp_this = this->head;
				tmp_obj = tmp_obj->next;
				tmp = tmp->next;
			}
		}

		return new_polinom;
	}

	polinom& operator *(const double val)
	{
		P* tmp_this = this->head;

		do
		{
			
			tmp_this->coeff *= val;
			tmp_this = tmp_this->next;

		} while (tmp_this->next != NULL);

		return *this;

		/*
		polinom new_polinom(this->size);
		P* tmp = new_polinom.head;
		P* tmp_this = this->head;
		do
		{

			tmp = tmp_this->coeff * val;
			tmp->exp = tmp_this->exp;
			tmp_this = tmp_this->next;
			tmp = tmp->next;

		} while (tmp_this->next != NULL);
		*/
	}

	double calculate(const polinom& p, const double val)
	{

		double res = 0;
		P * tmp_this = this->head;

		do 
		{
			res += tmp_this->coeff * pow(val, tmp_this->exp);
		} while (tmp_this->next != NULL);

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

	polinom polinom(size);
	polinom[1];
	polinom.set(4, polinom[2]);

	return 0;
}