// ConsoleApplication1.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <string>
#include <stdlib.h>

int main(){
	std::string Ans = "This is ";
	Ans.append((sizeof(char) == sizeof('c')) ? "C++ program!\n" : "C program!\n");
	std::cout << Ans << std::endl;
	std::cout << "Compiler's version: " << __cplusplus << std::endl;
	return EXIT_SUCCESS;
}

