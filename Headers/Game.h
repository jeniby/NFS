#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML\System.hpp> 
#include <SFML\Window.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "View.h"
#include "Menu.h"
#include "File.h"
#include "Class.h"
#include "Music.h"
#include "GameOver.h"
#include "Escape.h"
bool StartGame(int* z,int * lvl); //ф-ция запускает игру lvl передает один из 3 уровней (ящики, встречка, попутка)
void GameRunning(int *z,int *lvl); //ф-ция перезагружает игру , если это необходимо
bool StartGame(int *z,int* lvl); // сам игровой процесс
