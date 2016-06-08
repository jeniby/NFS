#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML\System.hpp> 
#include <SFML\Window.hpp>

bool Escape(RenderWindow & window, int *z); //При нажатии клавиши Escape появляется окно с выбором действий: рестарт, выход в меню.
