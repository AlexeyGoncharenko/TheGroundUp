#include "main.h"
using namespace std;

#define SIZE_IARRAY 10

int main(int argv, char* argc[])
{
	// ��������� ���������� locale(������� ���������)
	{
		cout << "Current locale: " << ::setlocale(LC_ALL, NULL) << endl;
		cout << "Set locale: " << ::setlocale(LC_ALL, ".1251") << endl;
	}
	/* 
		������������ ��������� ����������� ���������� 
	*/
	//int iArr[SIZE_IARRAY];
	//srand((unsigned int) time(NULL)); // ������������� ���������� �������� ��� ���������� ��������� �����
	//// ��������� ������ iArr ����������� �������
	//while(!_kbhit()) {
	//	for(int i = 0; i < SIZE_IARRAY; i++) iArr[i] = rand();
	//	bubble_sort_algorithm(iArr, SIZE_IARRAY);
	//	::Sleep(1500);
	//}
	demonstartion_array();
	system("pause");

	// ������ ������������� ������� �����, �� ������� ������� ��������� ������� �� ��������
	liteVerDB();
	system("pause");
	return EXIT_SUCCESS;

}
// ���������� ��������� ����������� ����������
void bubble_sort_algorithm(int* pInArr, unsigned int sizeArr)
{
	cout << "\ni: ��������� �������� �������: ������ = " << sizeArr << '\n';
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

	cout << "i: ��������� ���������������� �������:\n";
	for(unsigned int i = 0; i < sizeArr; i++) cout << pInArr[i] << ' ';
	cout << endl;
}
// ������������ ������������� ������� �� ��������� <cstring>
void use_cstring_function()
{
	// use strcpy()
	{
		char dst[11], 
		src[10] = "Test str";

		cout << "i: [������������� �. strcpy()]" << endl;
		cout << "src = " << src << endl;
		strcpy(dst, src);
		cout << "dst = " << dst << endl;
	}
	
	// use strcat()
	{
		///< NB!: ��� �������� ����� ���������� ������������ ����������� ����.��� wchar_t, ��������� ����� ���������� ��������   != 10, � ����� 17 >///
		char s1[30] = "������,", 
			 s2[20] = "��� ����!";

		cout << "i: [������������� �. strcat()]" << endl;
		cout << "��������� ������������ �� ���������� �������\ns1 = " << s1 << endl;
		cout << "s2 = " << s2 << endl;
		strcat(s1, s2);
		cout << "��������� ������������ ����� ���������� �������\ns1 = " << s1 << endl;
		cout << "s2 = " << s2 << endl;
	}
	
	// use strcmp()
	{
		char strToPSWD[20] = {'\0'};
		char strPSWD[20] = "password";
		
		cout << "i: [������������� �. strcmp()]" << endl;
		cout << "������� ������: ";
		gets(strToPSWD);
		// �����������: true - ������ ������, false - ������ ��������
		if(!strcmp(strPSWD, strToPSWD)) {
			cout << "i: ������ ������������. ������ ��������.\n";
		}
		else
			cout << "i: ������ �� ������������. �������� � �������.\n\a";
	}
	
	// use strlen() - ��������� ����� ������ ��� ����� �������� �������(�������� ����� ������)
	{
		char chArr[20];
		
		cout << "i: [������������� �. strlen()]" << endl;
		cout << "������� ������: "; 
		gets(chArr);
		for(int i = strlen(chArr) - 1; i >= 0; i--)
			cout << chArr[i];
		cout << endl;
	}

	// use toupper()
	{
		char inputString[30];
		cout << "i: [������������� �. toupper()]" << endl;
		cout << "������� ������: "; 
		gets(inputString);
					   // ���������� ������� ����� ������ ��� ������ �� ����� 
		for(int i = 0; inputString[i]; i++) 
			inputString[i] = toupper(inputString[i]);

		cout << "���� ������ ���������� �������: " << inputString << endl;
	}
}
// ������������ ������������� ��������
void demonstartion_array()
{
	/*
		������ � 3D and more ���������
	*/
	const unsigned int sizeMultiArray = 3;
	int multidim[sizeMultiArray][sizeMultiArray][sizeMultiArray] = {0}; // 3D array

	// ��������� �������� ��������� �������
	for(unsigned int i = 0; i < sizeMultiArray; i++) {
		for(unsigned int j = 0; j < sizeMultiArray; j++) {
			for(unsigned int k = 0; k < sizeMultiArray; k++) {
				cout << multidim[i][j][k] << ' ';	// ***(multidim + (i*sizeMultiArray*sizeMultiArray) + (j*sizeMultiArray + k)) - ������������ ��������� � ������
			}
			cout << "  ";
		}
		cout << '\n';
	}
	cout << '\n';

	// ���������������� � ���������� � ������������ ������ ��� 3D ��������
	int *address_array3d = multidim[0][0]; //	������� 2D ��� 3D [] [][] [][][] - ��� ������ ��� ������� ����������� ��������������/�����������������(� ���������) ��������� ������ ������� (��� �������� ������� ����������� ��������������� � ������� ������� ������), ��� ������ *(address_array3d+4) = 4 - ����� ��� ��������� � �������� ������ ����������
	*(address_array3d+0) = 1;
	*(address_array3d+1) = 2;
	*(address_array3d+2) = 3;
	*(address_array3d+3) = 4;	// ������� � �������� �������� ������� ����� ����������
	unsigned int size3D = sizeof(multidim);	// ������������������� � ��� ��� ����������/������������ ������ ��� ����������� ��������. sizeof(multidim) = 108 ����, sizeof(multidim[0]) = 36 ����, sizeof(multidim[0][0]) = 12 ����
	
	// ��������� ���������� ��������� �������
	for(unsigned int i = 0; i < sizeMultiArray; i++) {
		for(unsigned int j = 0; j < sizeMultiArray; j++) {
			for(unsigned int k = 0; k < sizeMultiArray; k++) {
				cout << multidim[i][j][k] << ' ';	// ***(multidim + (i*sizeMultiArray*sizeMultiArray) + (j*sizeMultiArray + k)) - ������������ ��������� � ������
			}
			cout << "  ";
		}
		cout << '\n';
	}
	cout << '\n';

	/* 
		������ � 2D ���������
	*/
	// ������������� ����������� ��������, ����������� ����� � ������ ��������������(�������������) ����� �������� �������� ����������
	int iArr1[3][3] = {1, 2, 3,
					   4, 5, 6,
					   7/*, 8, 9*/};

	// ��� ���������� ������ ��������������� ��� ������ ����������� ������� �� ��������� � �������������� {}
	//int iArr2[3][3] = {{1, 2, 3},
	//				     {4, 5, 6},
	//				     {7, 8, 9}};
	
	/// <char *myCharExp[3] = {"test1", "test2", "test3"};> ///


	// �������� ������������ ������������� �������
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
	// ���������� ������(��� �����) ������ �������
	unsigned int size1 = (sizeof(iArr2)/sizeof(int))/SIZE2;
	unsigned int inputNumber = 0;

	cout << "������� �� 1 �� 10: "; cin >> inputNumber;
	
	if(inputNumber < 1 && inputNumber > 10) {
		cout << "��������� ���� ����� �� ������ � ���������� ��������\n\a";
	}
	else {
		for(int i = 0; i < size1; i++) {
			if(iArr2[i][0] == inputNumber)
				cout << "���������� ������ ���������� ���� ����� = " << iArr2[i][1] << endl;
		}
	}


	// ����� ��������� ����� 2D �������
	cout << "��������� ������� �������� ��������� ��� ����� �� 0 �� 10\n";
	show_array(iArr2[0], 2, size1, SIZE2); 
}
// ������������ ������ �������
void show_array(int *pInArray, unsigned int dims, unsigned int rows, unsigned int cols)
{
	switch(dims){
	case 1:
		cout << "�������� 1D ������" << endl;
		for(int i = 0; i < cols; i++) {
			cout << *(pInArray + i) << ' ' << endl;
		}
		break;
	case 2:
		cout << "�������� 2D ������" << endl;
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
		cout << "i: �������� ������������ �������� ����������� �������\n\a";
	};
}