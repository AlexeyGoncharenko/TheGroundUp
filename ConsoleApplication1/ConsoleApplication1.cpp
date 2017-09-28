// ConsoleApplication1.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <string>
#include <stdlib.h>

int main(){
	std::string answer = "This is ";
	answer.append((sizeof(char) == sizeof('c')) ? "C++ program!\n" : "C program!\n");
	std::cout << answer << std::endl;
	std::cout << "Compiler's version: " << __cplusplus << std::endl;
	return EXIT_SUCCESS;
}

