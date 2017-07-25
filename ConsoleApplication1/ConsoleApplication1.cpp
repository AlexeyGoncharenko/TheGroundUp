// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

using namespace std;
int main(){
	string Ans = "This is ";
	Ans.append((sizeof(char) == sizeof('c')) ? "C++ program!\n" : "C program!\n");
	cout << Ans << endl;
	return 0;
}

