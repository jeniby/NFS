#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <sstream>
#ifndef MENU_H    // если имяMENU_H  ещё не определено
#define  MENU_H   // определить имя  MENU_H 
int sum(FILE * file);
bool About(RenderWindow & window)// Выводит информацию о игре на экран
bool LVL(RenderWindow & window,int *lvl)// Выводит выбор уровней после нажатия Play
void menu(RenderWindow & window, int * lvl)// Выводит все меню на экран
#endif MENU_H    // если  имя MENU_H уже определено, повторно не определять
