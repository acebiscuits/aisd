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

	cout << "������� ��������� - 1" << endl << "��������� - 0" << endl;
	cin >> ch;

	while (ch != 1 && ch != 0)
	{
		cout << "������� ��������� - 1" << endl << "��������� - 0" << endl;
		cin >> ch;
	}
	while (ch == 1)
	{

		int size = 0;


		cout << "������� ������� ����������" << endl;

		cin >> size;

		while (size < 0)
		{
			cout << "������� ������������� ������� ����������" << endl;
			cin >> size;
		}

		polinom CRPolinom(size);
		cout << "���������: ";
		CRPolinom.print();
		cout << endl;
		while (true) {
			cout << "������� ����� ��������� - 1" << endl;
			cout << "���������� ����������� ��� �������� ������� - 2" << endl;
			cout << "���������� ����������� ��� �������� ������� - 3" << endl;
			cout << "������� ��� ���������� - 4" << endl;
			cout << "������� ���� ��������� �� ������� - 5" << endl;
			cout << "�������� ��������� �� ������ - 6" << endl;
			cout << "���������� �������� ���������� ��� �������� � - 7" << endl;
			cout << "��������� - 0" << endl;
			cin >> ch2;
			while (ch2 != 1 && ch2 != 2 && ch2 != 3 && ch2 != 4 && ch2 != 5 && ch2 != 6 && ch2 != 7 && ch2 != 0)
			{
				cout << "������� ����� ��������� - 1" << endl;
				cout << "���������� ����������� ��� �������� ������� - 2" << endl;
				cout << "���������� ����������� ��� �������� ������� - 3" << endl;
				cout << "������� ��� ���������� - 4" << endl;
				cout << "������� ���� ��������� �� ������� - 5" << endl;
				cout << "�������� ��������� �� ������ - 6" << endl;
				cout << "���������� �������� ���������� ��� �������� � - 7" << endl;
				cout << "��������� - 0" << endl;
				cin >> ch2;

			}

			if (ch2 == 1)
			{
				break;
			}

			if (ch2 == 2)
			{

				int exp;
				cout << "������� �������" << endl;
				cin >> exp;
				while (exp < 0)
				{
					cout << "������� �������" << endl;
					cin >> exp;
				}
				if (CRPolinom[exp])
				{
					cout << "����������� ��� �������� �������: " << CRPolinom[exp] << endl;
				}

			}

			if (ch2 == 3)
			{

				int exp;
				cout << "������� �������" << endl;
				cin >> exp;
				while (exp < 0)
				{
					cout << "������� �������" << endl;
					cin >> exp;
				}

				double coeff = 0;
				cout << "������� �����������" << endl;
				cin >> coeff;
				CRPolinom.set(coeff, exp);

				cout << "���������: ";
				CRPolinom.print();
				cout << endl;

			}

			if (ch2 == 4)
			{

				cout << "��������: ";
				CRPolinom.print();
				cout << endl;

				int sizem;
				cout << "������� ������� ����������, � ������� ����� �������: " << endl;
				cin >> sizem;
				while (sizem < 0)
				{
					cout << "������� ��������������� ������� ����������, � ������� ����� �������: " << endl;
					cin >> sizem;
				}
				polinom SECPolinom(sizem);

				polinom result = CRPolinom + SECPolinom;

				cout << "���������: ";
				result.print();
				cout << endl;

			}

			if (ch2 == 5)
			{

				cout << "��������: ";
				CRPolinom.print();
				cout << endl;

				int sizem;
				cout << "������� ������� ����������, ������� ����� �������: " << endl;
				cin >> sizem;
				while (sizem < 0)
				{
					cout << "������� ��������������� ������� ����������, ������� ����� �������: " << endl;
					cin >> sizem;
				}
				polinom SECPolinom(sizem);

				polinom result = CRPolinom - SECPolinom;

				cout << "���������: ";
				result.print();
				cout << endl;

			}

			if (ch2 == 6)
			{

				cout << "��������: ";
				CRPolinom.print();
				cout << endl;

				double val;
				cout << "������� �����, �� ������� ����� �������� ���������: " << endl;
				cin >> val;
				polinom result = CRPolinom * val;

				cout << "���������: ";
				result.print();
				cout << endl;

			}

			if (ch2 == 7)
			{

				cout << "��������: ";
				CRPolinom.print();
				cout << endl;

				double val;
				cout << "������� �����, ������������ �������� ����� ��������� ���������: " << endl;
				cin >> val;

				cout << "���������: " << CRPolinom.calculate(val) << endl;

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

	printf("\n������� ������� ����������: ");
	scanf("%d", &size);

	if (size < 0)
	{

		printf("\n������� ��������������� �������: ");
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