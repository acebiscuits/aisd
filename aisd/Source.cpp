#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <cmath>
#include <iostream>
//#include "polinom.cpp"
#include "polinom.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int ch = 0;
	int ch2 = 0;

	cout << "Создать многочлен - 1" << endl << "Закончить - 0" << endl;
	cin >> ch;

	while (ch != 1 && ch != 0)
	{
		cout << "Создать многочлен - 1" << endl << "Закончить - 0" << endl;
		cin >> ch;
	}
	while (ch == 1)
	{

		int size = 0;


		cout << "Введите степень многочлена" << endl;

		cin >> size;

		while (size < 0)
		{
			cout << "Введите положительную степень многочлена" << endl;
			cin >> size;
		}

		polinom CRPolinom(size);
		cout << "Многочлен: ";
		CRPolinom.print();
		cout << endl;
		while (true) {
			cout << "Создать новый многочлен - 1" << endl;
			cout << "Посмотреть коэффициент при заданной степени - 2" << endl;
			cout << "Установить коэффициент при заданной степени - 3" << endl;
			cout << "Сложить два многочлена - 4" << endl;
			cout << "Вычесть один многочлен из другого - 5" << endl;
			cout << "Умножить многочлен на скаляр - 6" << endl;
			cout << "Вычисление значение многочлена при заданном х - 7" << endl;
			cout << "Закончить - 0" << endl;
			cin >> ch2;
			while (ch2 != 1 && ch2 != 2 && ch2 != 3 && ch2 != 4 && ch2 != 5 && ch2 != 6 && ch2 != 7 && ch2 != 0)
			{
				cout << "Создать новый многочлен - 1" << endl;
				cout << "Посмотреть коэффициент при заданной степени - 2" << endl;
				cout << "Установить коэффициент при заданной степени - 3" << endl;
				cout << "Сложить два многочлена - 4" << endl;
				cout << "Вычесть один многочлен из другого - 5" << endl;
				cout << "Умножить многочлен на скаляр - 6" << endl;
				cout << "Вычисление значение многочлена при заданном х - 7" << endl;
				cout << "Закончить - 0" << endl;
				cin >> ch2;

			}

			if (ch2 == 1)
			{
				break;
			}

			if (ch2 == 2)
			{

				int exp;
				cout << "Введите степень" << endl;
				cin >> exp;
				while (exp < 0)
				{
					cout << "Введите степень" << endl;
					cin >> exp;
				}
				if (CRPolinom[exp])
				{
					cout << "Коэффициент при заданной степени: " << CRPolinom[exp] << endl;
				}

			}

			if (ch2 == 3)
			{

				int exp;
				cout << "Введите степень" << endl;
				cin >> exp;
				while (exp < 0)
				{
					cout << "Введите степень" << endl;
					cin >> exp;
				}

				double coeff = 0;
				cout << "Введите коэффициент" << endl;
				cin >> coeff;
				CRPolinom.set(coeff, exp);

				cout << "Результат: ";
				CRPolinom.print();
				cout << endl;

			}

			if (ch2 == 4)
			{

				cout << "Многчлен: ";
				CRPolinom.print();
				cout << endl;

				int sizem;
				cout << "Введите степень многочлена, с которым нужно сложить: " << endl;
				cin >> sizem;
				while (sizem < 0)
				{
					cout << "Введите неотрицательную степень многочлена, с которым нужно сложить: " << endl;
					cin >> sizem;
				}
				polinom SECPolinom(sizem);

				polinom result = CRPolinom + SECPolinom;

				cout << "Результат: ";
				result.print();
				cout << endl;

			}

			if (ch2 == 5)
			{

				cout << "Многчлен: ";
				CRPolinom.print();
				cout << endl;

				int sizem;
				cout << "Введите степень многочлена, который нужно вычисть: " << endl;
				cin >> sizem;
				while (sizem < 0)
				{
					cout << "Введите неотрицательную степень многочлена, который нужно вычисть: " << endl;
					cin >> sizem;
				}
				polinom SECPolinom(sizem);

				polinom result = CRPolinom - SECPolinom;

				cout << "Результат: ";
				result.print();
				cout << endl;

			}

			if (ch2 == 6)
			{

				cout << "Многчлен: ";
				CRPolinom.print();
				cout << endl;

				double val;
				cout << "Введите число, на которое нужно умножить многочлен: " << endl;
				cin >> val;
				polinom result = CRPolinom * val;

				cout << "Результат: ";
				result.print();
				cout << endl;

			}

			if (ch2 == 7)
			{

				cout << "Многчлен: ";
				CRPolinom.print();
				cout << endl;

				double val;
				cout << "Введите число, относительно которого нужно посчитать многочлен: " << endl;
				cin >> val;

				cout << "Результат: " << CRPolinom.calculate(val) << endl;

			}

			if (ch2 == 0)
			{
				ch = 0;
				break;
			}
		}

	}

	return 0;
}


/*int main()
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
	polinom polinom2(size);

	polinom new_polinom = polinom1 + polinom2;
	polinom new_polinom2 = new_polinom - polinom1;
	polinom new_polinom3 = polinom2 + polinom1;
	new_polinom * 3;
	3 * new_polinom3;
	polinom2.calculate(3);
}*/