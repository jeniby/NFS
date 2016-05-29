#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML\System.hpp> 
#include <SFML\Window.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#ifndef GAME_H    // если имя GAME_H ещё не определено
#define  GAME_H   // определить имя  GAME_H
String music() //Данная процедура выбирает случайным образом песню и возвращает ее путь в папкеж
bool Game_over(RenderWindow & window,int *z,int m, int pr) // По оканчании игры выводит на экран окно с результирующими очками и предлаегает заново начать игру
bool Escape(RenderWindow & window, int *z) //При нажатии клавиши Escape появляется окно с выбором действий: рестарт, выход в меню.
bool startGame(int* z,int * lvl); //ф-ция запускает игру lvl передает один из 3 уровней (ящики, встречка, попутка)
void gameRunning(int *z,int *lvl) //ф-ция перезагружает игру , если это необходимо
bool startGame(int *z,int*lvl) // сам игровой процесс
#endif GAME_H   // если  имя GAME_H уже определено, повторно не определять
