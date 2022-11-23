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
void iostream_cleaner();// ������� ��� ������� ������ �����

//	global variable NB! �����, � ��� ����� � ����.���������� �.�. ���������� �� �� ������� �������������.
int icount; /*	���������� ���������� ���������������� ������ � ������ ���������, 
				��� ����.���������� ���������������� ������� ���������, ���� �� ������� ������� ������ ��������������.
				��������� ����������, ���������������� ������ ��� ��� ����� � �������, ��� ��� ����������.
				�������������������� �����.���������� ����� ����� ����������� ��������.
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
		int mm_ans = 455;	//	��������� ������� �� ������� ������. 
		mm_ans = t%3;	//	��� ��� �� 3, �������. � ���, ��� ���� 3, �������. 
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
		NB: �������� >> << ����� ����� ������� ��������� ����� ����������� �����������, 
		# cout << "Resul = "<< (a&&b) << endl; - ���������� �������� ������ � ��� ���������� ���������� ��������� � ������ ()
	*/
	{
		bool a = false, b = false;
		
		cout << "Input bool value A: "; cin >> a; // � ������ ������ ��� ����� 1, ����� ����������������� � �������� false
		iostream_cleaner();
		cout << "Input bool value B: "; cin >> b;
		iostream_cleaner();

		cout << " A || B = " << (a||b) << endl;
		cout << " A && B = " << (a&&b) << endl;
		bool ans = XOR(a,b);
		cout << "XOR(A,B) = " << ans << endl;


		a = 45; b = -34; // � ������ ������ ����� ��������� ����� ����� ����������������� � true
		cout << "A = " << a << " B = " << b << endl;
	}
	//

	// �������������� ����� � ����������
	{
		char chVal = 2; 
		int iVal = 5;
		double dblRes1 = iVal/chVal + 5.0;	//	� ������ ������ �������������� ����� ���������� ����� �������� ������� (int/char) -> double  => double � ����� 7.0 , ��������� ���� �������� ������� ������������� �����.
		double dblRes2 = (double)iVal/chVal + 5.0;	//	��, ��� � ������ ������ �� ������� � �������� ���������� ���������� ���������� 7.5, ��������� ������� int -> double, ��� � ���� ������� �������� � �������������� char -> double => ���� �������� ������� ������������ �����.
	}
	//

	// ���������� �����
	{
		float res1 = (float)5/2;	// ����� ���� ��������� ���������� ����.
		float res2 = 5/2.0F;	//	����� �������� ��� ������ �� ���������, �� ���� ������� ������������� � ��� ����� ���������������� �������������� ���������� ���� � ��������� (�������������� � ���������������)
	}
	return 0;
}

// ���������� ��������� ����������������� ���
bool XOR(bool a, bool b)
{
	return (a||b)&&!(a&&b);
}

int mul(int x, int y)
{
	icount += x*y;
	return icount;
}

// �������, � ������� ������� ����������� ������� ������ � ����. � �����. �����������
void printVGV()
{
	int icount = 1; //	����������� � ���������� ��������� ����������
	
	cout << ::icount; //	�������� ������ � ���������� ���������...
	for( ; icount < 4; icount++) 
		cout << "."; // ...
	cout << endl;
}

// ������� ��� ������� ������ ����� (cin) 
void iostream_cleaner()
{
	//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
}