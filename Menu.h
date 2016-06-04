#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <sstream>
int sum(FILE * file);
bool About(RenderWindow & window)// Выводит информацию о игре на экран
bool LVL(RenderWindow & window,int *lvl)// Выводит выбор уровней после нажатия Play
void menu(RenderWindow & window, int * lvl)// Выводит все меню на экран
