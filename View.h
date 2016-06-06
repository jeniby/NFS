#pragma once
#include <SFML/Graphics.hpp>

sf::View view; //объявили sfml объект "вид", который и является камерой

void GetPlayerCoordinateForView(float x, float y); //функция для считывания координат игрока
