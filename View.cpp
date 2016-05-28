#include 'View.h'

sf::View view;//объявили sfml объект "вид", который и является камерой

void getplayercoordinateforview(float x, float y) { //функция для считывания координат игрока

	view.setCenter(x, y-150); //следим за игроком, передавая его координаты. 

}

