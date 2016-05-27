#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML\System.hpp> 
#include <SFML\Window.hpp>
#include <iostream>
#include "view.h"
#include "Menu.h"
#include <string>
#include <sstream>
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include "Class.h"
#include "Game.h"
using namespace sf;
int main()
{
	int z = 0,lvl = 0;
	gameRunning(&z,&lvl);

	return 0;
}
