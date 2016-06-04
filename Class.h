#ifndef CLASS_H    // если имя  CLASS_H ещё не определено
#define  CLASS_H   // определить имя  CLASS_H
#include <SFML/Graphics.hpp>
#include <SFML\System.hpp> 
#include <SFML\Window.hpp>
#include <string>

class Player { // класс Игрока
public:

	Player(String F, float X, float Y, float W, float H);  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
	FloatRect getRect() ; //возвращает квадрат спрайта игрока
	void update(float time); //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
	float getplayercoordinateX(); 	//этим методом будем забирать координату Х	
	float getplayercoordinateY() ;	//этим методом будем забирать координату Y 	
};
class Map {
public:
	Map(String F, float X, float Y, float W, float H);  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту

};
class Box
{
public:
	Box(String F, float W, float H); //конструктор с параметрами(формальными) для класса Box.При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
	FloatRect getRect(); //возвращает квадрат спрайта ящика
	void rand_box(float a); //рандомно заполняет дорогу ящиком

};
class Sounds
{
public:
	Sounds(String F); //конструктор для музыки
};
class Bot {
public:
	Bot(String F, float X, float Y, float W, float H); //Конструктор с параметрами(формальными) для класса Bot. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
	void Rand_Bot(float a, int k); //рандомно расставляе тмашины на дороге
	FloatRect getRect(); //возвращает квадрат спрайта ботов
	void Update(int d);  //обновляет координаты
	void Rand_Color(); //Рандомит цвет
};
class Racket
{
public:
	Racket(String F, float W, float H); //Конструктор с параметрами(формальными) для класса Racket. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
	FloatRect getRect(); //возвращает квадрат спрайта ботов
	void rand_Racket(float a); //Рандомит координаты для ракет
};
#endif CLASS_H     // если  имя CLASS_H уже определено, повторно не определять
