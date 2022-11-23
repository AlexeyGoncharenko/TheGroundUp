#include "main.h"
using namespace std;

// define global constant
#define SIZE 3			// количество служащих на которых формируется БД

// define global variable
char names[SIZE][80];	// Массив имен служащих
char phones[SIZE][80];	// Массив телефонных номеров служащих
float hours[SIZE];		// Массив часов, отработаных за неделю
float wage[SIZE];		// Массив окладов

int liteVerDB()
{
	int choice = 0;
	system("cls"); // очищаем экран от предыдущих сообщений
	cout << "i: Вы запустили программу liteVerDB, которая позволяет вести учет служащих\n\a";
	do {
		choice = menu();
		switch(choice) {
		case 0:
			cout << "i: Завершение программы liteVerDB...\n\a";
			break;
		case 1:
			enter();
			break;
		case 2:
			report();
			break;
		default:
			cout << "Некорретный ввод. Попробуйте снова\n\a";
		}
	}while(choice);  // Если в выборе меню было выбран 0 выходим из цикла
	system("pause");
	system("cls"); // очищаем экран от предыдущих сообщений, и возвращаем управление вызвавшей функции
	return EXIT_SUCCESS;
}

// Функция возвращает команду выбранную пользователем.
int menu()
{
	int choice = 0;
	cout << "0. Выход из программы\n";
	cout << "1. Ввод информации\n";
	cout << "2. Генерирование отчета\n";
	cout << "\tВыберите команду:"; cin >> choice;
	return choice;
}

// Функция ввода информации в БД
void enter()
{
	int i;
	for(i = 0; i < SIZE; i++) {
		cout << "Введите имя сотрудника: "; cin >> names[i];
		cout << "Введите номер телефона: "; cin >> phones[i];
		cout << "Введите количество отработанных часов: "; cin >> hours[i];
		cout << "Введите оклад: "; cin >> wage[i];
	}
}

// Функция отображения отчета
void report()
{
	int i;
	cout << "Отчет по сотрудникам\n";
	for(i = 0; i < SIZE; i++) {
		cout << "---"<<names[i] << ' ' << phones[i] << endl;
		cout << "   Заработная плата за неделю: " 
			 << hours[i]*wage[i] << " RUB\n";
	}
	cout << "\n\n";
}
