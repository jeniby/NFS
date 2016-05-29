#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#ifndef FILE_H    // если имя FILE_H ещё не определено
#define  FILE_H   // определить имя  FILE_H
int sum(FILE * file) //считывает файл и возвращает сумму цифр
#endif FILE_H     // если  имя FILE_H уже определено, повторно не определять
