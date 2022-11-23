#include "main.h"
using namespace std;

#define SIZE_IARRAY 10

int main(int argv, char* argc[])
{
	// Настройка парамтеров locale(местная специфика)
	{
		cout << "Current locale: " << ::setlocale(LC_ALL, NULL) << endl;
		cout << "Set locale: " << ::setlocale(LC_ALL, ".1251") << endl;
	}
	/* 
		Тестирование алгоритма пузырьковой сортировки 
	*/
	//int iArr[SIZE_IARRAY];
	//srand((unsigned int) time(NULL)); // инициализация начального значения для генератора случайных чисел
	//// заполняем массив iArr случайныйми числами
	//while(!_kbhit()) {
	//	for(int i = 0; i < SIZE_IARRAY; i++) iArr[i] = rand();
	//	bubble_sort_algorithm(iArr, SIZE_IARRAY);
	//	::Sleep(1500);
	//}
	demonstartion_array();
	system("pause");

	// пример использования массива строк, на примере простой программы ведения БД служащих
	liteVerDB();
	system("pause");
	return EXIT_SUCCESS;

}
// реализация алгоритма пузырьковой сортировки
void bubble_sort_algorithm(int* pInArr, unsigned int sizeArr)
{
	cout << "\ni: Состояние входного массива: размер = " << sizeArr << '\n';
	for(unsigned int i = 0; i < sizeArr; i++) cout << pInArr[i] << ' ';
	cout << endl;

	int temp = 0;
	for(unsigned int a = 1; a < sizeArr; a++) {
		for(unsigned int b = sizeArr-1; b >= a; b--) {
			if(pInArr[b-1] > pInArr[b]) { 
				temp = pInArr[b-1];
				pInArr[b-1] = pInArr[b];
				pInArr[b] = temp;	
			}
		}
	}

	cout << "i: Состояние отсортированного массива:\n";
	for(unsigned int i = 0; i < sizeArr; i++) cout << pInArr[i] << ' ';
	cout << endl;
}
// демонстрация использования функций из заголовка <cstring>
void use_cstring_function()
{
	// use strcpy()
	{
		char dst[11], 
		src[10] = "Test str";

		cout << "i: [использование ф. strcpy()]" << endl;
		cout << "src = " << src << endl;
		strcpy(dst, src);
		cout << "dst = " << dst << endl;
	}
	
	// use strcat()
	{
		///< NB!: Для русского языка необходимо использовать двубайтовый симв.тип wchar_t, поскольку длина строкового литерала   != 10, а равна 17 >///
		char s1[30] = "Привет,", 
			 s2[20] = "НИУ ИТМО!";

		cout << "i: [использование ф. strcat()]" << endl;
		cout << "Состояние перемеменных до применения функции\ns1 = " << s1 << endl;
		cout << "s2 = " << s2 << endl;
		strcat(s1, s2);
		cout << "Состояние перемеменных после применения функции\ns1 = " << s1 << endl;
		cout << "s2 = " << s2 << endl;
	}
	
	// use strcmp()
	{
		char strToPSWD[20] = {'\0'};
		char strPSWD[20] = "password";
		
		cout << "i: [использование ф. strcmp()]" << endl;
		cout << "Введите пароль: ";
		gets(strToPSWD);
		// Верификация: true - пароль принят, false - пароль отклонен
		if(!strcmp(strPSWD, strToPSWD)) {
			cout << "i: Пароль действителен. Доступ разрешен.\n";
		}
		else
			cout << "i: Пароль не действителен. Отказано в доступе.\n\a";
	}
	
	// use strlen() - указывает длину строки без учета нулевого символа(признака конца строки)
	{
		char chArr[20];
		
		cout << "i: [использование ф. strlen()]" << endl;
		cout << "Введите строку: "; 
		gets(chArr);
		for(int i = strlen(chArr) - 1; i >= 0; i--)
			cout << chArr[i];
		cout << endl;
	}

	// use toupper()
	{
		char inputString[30];
		cout << "i: [использование ф. toupper()]" << endl;
		cout << "Введите строку: "; 
		gets(inputString);
					   // используем признак конца строки для выхода из цикла 
		for(int i = 0; inputString[i]; i++) 
			inputString[i] = toupper(inputString[i]);

		cout << "Ваша строка прописными буквами: " << inputString << endl;
	}
}
// демонстрация использования массивов
void demonstartion_array()
{
	/*
		Работа с 3D and more массивами
	*/
	const unsigned int sizeMultiArray = 3;
	int multidim[sizeMultiArray][sizeMultiArray][sizeMultiArray] = {0}; // 3D array

	// проверяем исходное состояние массива
	for(unsigned int i = 0; i < sizeMultiArray; i++) {
		for(unsigned int j = 0; j < sizeMultiArray; j++) {
			for(unsigned int k = 0; k < sizeMultiArray; k++) {
				cout << multidim[i][j][k] << ' ';	// ***(multidim + (i*sizeMultiArray*sizeMultiArray) + (j*sizeMultiArray + k)) - некорректное обращение к памяти
			}
			cout << "  ";
		}
		cout << '\n';
	}
	cout << '\n';

	// экспериментируем с выделением и определением памяти для 3D массивов
	int *address_array3d = multidim[0][0]; //	неважно 2D или 3D [] [][] [][][] - это просто для расчета правильного индексирования/позиционнирования(и адресации) элементов внутри массива (все элементы массива расположены последовательно в смежных ячейках памяти), как пример *(address_array3d+4) = 4 - здесь уже переходим к соседнем ячекам подмассива
	*(address_array3d+0) = 1;
	*(address_array3d+1) = 2;
	*(address_array3d+2) = 3;
	*(address_array3d+3) = 4;	// переход к значению соседней смежной ячеки подмассива
	unsigned int size3D = sizeof(multidim);	// экспериментирование с тем как выделяется/определяется память для многомерных массивов. sizeof(multidim) = 108 байт, sizeof(multidim[0]) = 36 байт, sizeof(multidim[0][0]) = 12 байт
	
	// проверяем измененное состояние массива
	for(unsigned int i = 0; i < sizeMultiArray; i++) {
		for(unsigned int j = 0; j < sizeMultiArray; j++) {
			for(unsigned int k = 0; k < sizeMultiArray; k++) {
				cout << multidim[i][j][k] << ' ';	// ***(multidim + (i*sizeMultiArray*sizeMultiArray) + (j*sizeMultiArray + k)) - некорректное обращение к памяти
			}
			cout << "  ";
		}
		cout << '\n';
	}
	cout << '\n';

	/* 
		Работа с 2D массивами
	*/
	// инициализация многомерных массивов, НЕДОСТАЮЩИЕ ЧЛЕНЫ В СПИСКЕ ИНИЦИЛИЗАТОРОВ(ИНИЦИАЛИЗАЦИИ) БУДУТ ЗАМЕНЕНЫ НУЛЕВЫМИ ЗНАЧЕНИЯМИ
	int iArr1[3][3] = {1, 2, 3,
					   4, 5, 6,
					   7/*, 8, 9*/};

	// или аналогично список инициализаторов для каждой размерности разбить на подгруппы с использованием {}
	//int iArr2[3][3] = {{1, 2, 3},
	//				     {4, 5, 6},
	//				     {7, 8, 9}};
	
	/// <char *myCharExp[3] = {"test1", "test2", "test3"};> ///


	// выполним безразмерную инициализацию массива
	const int SIZE2 = 2;
	int iArr2[][SIZE2] = {	1, 1*1,   
							2, 2*2,
							3, 3*3,
							4, 4*4,
							5, 5*5,
							6, 6*6,
							7, 7*7,
							8, 8*8,
							9, 9*9,
							10, 10*10 };
	// определяем первый(или левый) индекс массива
	unsigned int size1 = (sizeof(iArr2)/sizeof(int))/SIZE2;
	unsigned int inputNumber = 0;

	cout << "Введите от 1 до 10: "; cin >> inputNumber;
	
	if(inputNumber < 1 && inputNumber > 10) {
		cout << "Введенное Вами число не входит в допустимый диапазон\n\a";
	}
	else {
		for(int i = 0; i < size1; i++) {
			if(iArr2[i][0] == inputNumber)
				cout << "Квадратный корень введенного Вами числа = " << iArr2[i][1] << endl;
		}
	}


	// вывод состояния всего 2D массива
	cout << "Состояние массива значений квадратов для чисел от 0 до 10\n";
	show_array(iArr2[0], 2, size1, SIZE2); 
}
// демонстрация вывода массива
void show_array(int *pInArray, unsigned int dims, unsigned int rows, unsigned int cols)
{
	switch(dims){
	case 1:
		cout << "Переданн 1D массив" << endl;
		for(int i = 0; i < cols; i++) {
			cout << *(pInArray + i) << ' ' << endl;
		}
		break;
	case 2:
		cout << "Переданн 2D массив" << endl;
		for(int i = 0; i < rows; i++) {
			cout << "{";
			for(int j = 0; j < cols; j++) {
				if(j != (cols-1))
					cout << ' ' << *(pInArray + (i*cols + j)) << ", "; 
				else
					cout << ' ' << *(pInArray + (i*cols + j));  
			}
			cout << " }\n";
		}
		break;
	default:
		cout << "i: Указанно недопустимое значение размерности массива\n\a";
	};
}