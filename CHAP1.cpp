// CHAP1.cpp : 
/*
	Программа №1
*/
#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"My first excellent program!"<<endl;
	int iVal = 4;
	iVal = 'a'; // получили ASCII код символа
	iVal = 5.0f;
	iVal = reinterpret_cast<int>("string");
	return 0;
}




