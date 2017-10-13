// ConsoleApplication1.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <string>
#include <Windows.h>

int main(){
	setlocale(LC_ALL, "ru_RU.UTF-8");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	// Инициализация программы 
	std::string  answer = "Инициализация приложения... ";
	std::cout << answer.c_str() << std::endl;

	std::cout << "Compiler's version: " << __cplusplus << std::endl;

	answer = "This is ";
	answer.append((sizeof(char) == sizeof('c')) ? "C++ program!\n" : "C program!\n");
	std::cout << answer << std::endl;
		
	return EXIT_SUCCESS;
}