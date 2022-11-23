#include "main.h"
using namespace std;

// define global constant
#define SIZE 3			// ���������� �������� �� ������� ����������� ��

// define global variable
char names[SIZE][80];	// ������ ���� ��������
char phones[SIZE][80];	// ������ ���������� ������� ��������
float hours[SIZE];		// ������ �����, ����������� �� ������
float wage[SIZE];		// ������ �������

int liteVerDB()
{
	int choice = 0;
	system("cls"); // ������� ����� �� ���������� ���������
	cout << "i: �� ��������� ��������� liteVerDB, ������� ��������� ����� ���� ��������\n\a";
	do {
		choice = menu();
		switch(choice) {
		case 0:
			cout << "i: ���������� ��������� liteVerDB...\n\a";
			break;
		case 1:
			enter();
			break;
		case 2:
			report();
			break;
		default:
			cout << "����������� ����. ���������� �����\n\a";
		}
	}while(choice);  // ���� � ������ ���� ���� ������ 0 ������� �� �����
	system("pause");
	system("cls"); // ������� ����� �� ���������� ���������, � ���������� ���������� ��������� �������
	return EXIT_SUCCESS;
}

// ������� ���������� ������� ��������� �������������.
int menu()
{
	int choice = 0;
	cout << "0. ����� �� ���������\n";
	cout << "1. ���� ����������\n";
	cout << "2. ������������� ������\n";
	cout << "\t�������� �������:"; cin >> choice;
	return choice;
}

// ������� ����� ���������� � ��
void enter()
{
	int i;
	for(i = 0; i < SIZE; i++) {
		cout << "������� ��� ����������: "; cin >> names[i];
		cout << "������� ����� ��������: "; cin >> phones[i];
		cout << "������� ���������� ������������ �����: "; cin >> hours[i];
		cout << "������� �����: "; cin >> wage[i];
	}
}

// ������� ����������� ������
void report()
{
	int i;
	cout << "����� �� �����������\n";
	for(i = 0; i < SIZE; i++) {
		cout << "---"<<names[i] << ' ' << phones[i] << endl;
		cout << "   ���������� ����� �� ������: " 
			 << hours[i]*wage[i] << " RUB\n";
	}
	cout << "\n\n";
}
