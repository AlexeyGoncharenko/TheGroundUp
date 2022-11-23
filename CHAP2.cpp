/*
	This program include many functions
*/
#include <cstdlib>
#include <iostream>
using namespace std;

//	functions prototypes
int mul(int x, int y); 
void printVGV(void);
bool XOR(bool a, bool b);
void iostream_cleaner();// функция для очистки потока ввода

//	global variable NB! Любые, в том числе и глоб.переменные д.б. объявленны до их первого использования.
int icount; /*	Глобальные переменные инициализируются только в начале программы, 
				все глоб.переменные инициализируются нулевым значением, если не указаны никакие другие инициализаторы.
				Локальные переменные, инициализируются каждый раз при входе в функцию, где они определены.
				Неинициализированные локал.переменные будут иметь НЕИЗВЕСТНОЕ ЗНАЧЕНИЕ.
			*/
int main()
{	
	/*
		test global variable in the end declaration the main code
	*/
	for(int i = 0; i < 3; i++){
		mul(i, i*2);
		printVGV();
	}
	system("pause");
	//

	// type char is digit value
	char letter = (char)0;
	for(letter = 'A'; letter <= 'Z'; letter++){
		cout << letter << ' ';
	}
	cout << endl;
	//
		
	// That operator ++ in use
		long long int lli = 1; 
		long int li = 2;
		int i = 3;
		cout<< "Size of type long long int = " << sizeof(lli) << endl;
		cout<< "Size of type long int = " << sizeof(li) << endl;
		cout<< "Size of type int = " << sizeof(i) << endl;
		int acceptVal = ++i;
		cout << "Test operator ++\n 1)\ni = " << i <<endl;
		cout << "acceptVal  = " << acceptVal <<endl;
		acceptVal = i++;
		cout << "Test operator ++\n 2)\ni = " << i <<endl;
		cout << "acceptVal  = " << acceptVal <<endl;
	//

	//	That operator % in use
	/// <NB> operator % cannot use with double,float type ///
	{
		enum mm {
			zero,
			one,
			two,
			three,
			four
		};
		mm t = mm::four;
		int mm_ans = 455;	//	возращает остаток от деления нацело. 
		mm_ans = t%3;	//	все что до 3, остаток. И все, что выше 3, остаток. 
	}
	//
		
	// Operator ++ can use with double & float type
	{
		long double ldbl = 123.45L;
		cout << "ldbl = " << ldbl << endl;
		cout << "++ldbl = " << ++ldbl << endl;
	}
	//

	// Use operators comparison
	/*
		NB: Оператор >> << имеет более высокий приоритет перед логическими операторами, 
		# cout << "Resul = "<< (a&&b) << endl; - логический оператор вместе с его операндами необходимо заключать в скобки ()
	*/
	{
		bool a = false, b = false;
		
		cout << "Input bool value A: "; cin >> a; // в данном случае все кроме 1, будет преобразовываться в значение false
		iostream_cleaner();
		cout << "Input bool value B: "; cin >> b;
		iostream_cleaner();

		cout << " A || B = " << (a||b) << endl;
		cout << " A && B = " << (a&&b) << endl;
		bool ans = XOR(a,b);
		cout << "XOR(A,B) = " << ans << endl;


		a = 45; b = -34; // в данном случае ЛЮБОЕ НЕНУЛЕВОЕ число будет преобразовываться в true
		cout << "A = " << a << " B = " << b << endl;
	}
	//

	// Преобразование типов в выражениях
	{
		char chVal = 2; 
		int iVal = 5;
		double dblRes1 = iVal/chVal + 5.0;	//	в данном случае преобразование типов происходит после операции деления (int/char) -> double  => double в итоге 7.0 , поскольку итог операции деления целочисленное число.
		double dblRes2 = (double)iVal/chVal + 5.0;	//	но, уже в данном случае мы получим в качестве результата выполнения выражеиния 7.5, поскольку сначала int -> double, что в свою очередь приводит к преобразованию char -> double => итог операции деления вещественное число.
	}
	//

	// Приведение типов
	{
		float res1 = (float)5/2;	// можно либо выполнить приведение типа.
		float res2 = 5/2.0F;	//	можно изменить тип одного из литералов, за счет способа представления и тем самым инициализировать автоматическое приведение типа в выражении (преобразование с типорасширением)
	}
	return 0;
}

// Реализация оператора взаимоисключающее ИЛИ
bool XOR(bool a, bool b)
{
	return (a||b)&&!(a&&b);
}

int mul(int x, int y)
{
	icount += x*y;
	return icount;
}

// функция, с помощью которой объясняется принцип работы с глоб. и локал. переменными
void printVGV()
{
	int icount = 1; //	одноименная с глобальной локальная переменная
	
	cout << ::icount; //	получаем доступ к глобальной перменной...
	for( ; icount < 4; icount++) 
		cout << "."; // ...
	cout << endl;
}

// функция для очистки потока ввода (cin) 
void iostream_cleaner()
{
	//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
}