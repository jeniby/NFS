#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML\System.hpp> 
#include <SFML\Window.hpp>

bool GameOver(RenderWindow & window,int *z,int m, int pr); // По оканчании игры выводит на экран окно с результирующими очками и предлаегает заново начать игру
