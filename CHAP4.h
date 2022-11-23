#pragma once
#include <iostream>
#include <cstdio>	/*	printf(), NULL */
#include <cstdlib>	/*	srand(), rand() */
#include <ctime>	/*	time() */
#include <cmath>	/*	sin(), cos(), tan(), sqrt(), floor(), ceil() */
#include <conio.h>	/*	getchar(), kbhit()*/ // данный заголовок не определен стандартом С++, но входит в состав расширения языка С++

// прототипы функций
void testGeneralCplusplusType();
void play(unsigned  int magic_number);
void embbeded_if(void);
void for_instruction(void);
void switch_instuction(void);
void embbeded_switch_instuction(void);
void while_instuction(void);
void find_prime_number(int start_position, int end_position);
void goto_instruction(void);
void* testVoidType(void); // тестирование типа void* 
void clear_iostream();