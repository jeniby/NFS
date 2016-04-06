#include <SFML/Graphics.hpp>
#include <SFML\System.hpp> 
#include <SFML\Window.hpp>
#include <iostream>
#include "view.h"
using namespace sf;
class Player { // класс Игрока
private:
	float x, y;
public:
	float  w, h, dx = 0.0, dy = 0.0, speed_g = 0.0,speed_v = 0.0006,n; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
	int dir = 0; //направление (direction) движения и
	String File; //файл с расширением
	Image image;//сфмл изображение
	Texture texture;//сфмл текстура
	Sprite sprite;//сфмл спрайт

	Player(String F, float X, float Y, float W, float H) {  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
		File = F;//имя файла+расширение
		w = W; h = H;//высота и ширина
		image.loadFromFile("Images/" + File);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. В нашем случае "hero.png" и получится запись идентичная 	image.loadFromFile("images/hero/png");
		image.createMaskFromColor(Color(255, 0, 0));
		texture.loadFromImage(image);//закидываем наше изображение в текстуру
		sprite.setTexture(texture);//заливаем спрайт текстурой
		x = X; y = Y;//координата появления спрайта
		sprite.setPosition(x, y);
		
		}
	

	FloatRect getRect() {
	return FloatRect(x, y, w, h);
	}

	void update(float time) //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
	{
		switch (dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
			{
		case 0: dx = -5*speed_g*dy; x += dx*time; if (x > 405) x -= dx*time; break;
		case 1: dx = 5*speed_g*dy; x += dx*time; if (x < 20) x -= dx*time;break;
		case 2: dx = 0; if (dy < -0.001)  dy += 2 * speed_v; else dy = 0; y += dy*time; n = 1; break;
		case 3: dx = 0; if (dy > -0.3) dy += -speed_v; y += dy*time; n = 1;break;
		case 4: if (dy <=- 0.0001) n = n*0.9989; else dy = 0; dx = 0; y += n*dy*time;  break;
			}

			
			sprite.setPosition(x, y); //выводим спрайт в позицию x y . бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.
		
	}
	float getplayercoordinateX() {	//этим методом будем забирать координату Х	
		return x;
	}
	float getplayercoordinateY() {	//этим методом будем забирать координату Y 	
		return y;
	}
};
class Map {
	public:
		float x, y, w, h;
		String File; //файл с расширением
		Image image;//сфмл изображение
		Texture texture;//сфмл текстура
		Sprite sprite;//сфмл спрайт
		Map(String F, float X, float Y, float W, float H) {  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
			File = F;//имя файла+расширение
			w = W; h = H;//высота и ширина
			image.loadFromFile("Images/" + File);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. В нашем случае "hero.png" и получится запись идентичная 	image.loadFromFile("images/hero/png");
			texture.loadFromImage(image);//закидываем наше изображение в текстуру
			sprite.setTexture(texture);//заливаем спрайт текстурой
			x = X; y = Y;//координата появления спрайта
			sprite.setPosition(x, y);
		}

};

class Box {
public:
	float x, y, w, h;
	String File; 
	Image image;
	Texture texture;
	Sprite sprite;
	Box(String F, float W, float H) { 
		File = F;
		w = W; h = H;
		image.loadFromFile("Images/" + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		
	}
	FloatRect getRect() {
		return FloatRect(x, y, w, h);
	}

	void rand_box(float a)
	{
		int k = rand() % 4 + 1;
		switch (k) {
		case 1: sprite.setPosition(45, a - 600); x = 45; y = a - 600; break;
		case 2: sprite.setPosition(150, a - 600); x = 150; y = a - 600; break;
		case 3: sprite.setPosition(280, a - 600); x = 280; y = a - 600; break;
		case 4: sprite.setPosition(380, a - 600); x = 380; y = a - 600; break;
		
		}
		
	}
};
int main()
{
	ContextSettings settings(0, 0, 8, 1, 1, 0);
	RenderWindow window(sf::VideoMode(640, 720), "Need for Speed", 7U, settings);
	window.setVerticalSyncEnabled(true);
	Clock clock;
	view.reset(sf::FloatRect(0, 700, 640, 720)); 
	Player p("Car.jpg", 250, 10, 66.0, 130.0);
	Map m1("Map.jpg", -70, -255, 640.0, 865.0);
	Map	m2("Map.jpg", -70, 610, 640.0, 865.0);
	Box b("Box.jpg", 69, 68);
	
	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 50);
	text.setColor(Color::Black);
	text.setStyle(Text::Bold);

	int k,num = 1, n = 340, s = 0,t = 1;
	float box_time = 0;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 1000;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		k = 0;
		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
			p.dir = 1; p.speed_g = 0.1;
			p.update(time);

		}

		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			p.dir = 0; p.speed_g = 0.1;
			p.update(time);
		}

		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
			p.dir = 3; k = 1; 
			p.update(time);
			
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
			p.dir = 2; k = 1; 
			p.update(time);
		
		}
		if (k == 0)
		{
			p.dir = 4;
			p.update(time);
			
		}
		getplayercoordinateforview(250, p.getplayercoordinateY());

		// Алгоритм отрисовки карты
		if (p.getplayercoordinateY() <= n)
			if (s == 1)
			{
				m1.sprite.setPosition(-70, m1.y - 2*m1.h);
				m1.y += -2 * m1.h;
				s = 0;
				n -= 865;
			}
			else 
			{
				m2.sprite.setPosition(-70, m2.y - 2* m2.h);
				m2.y += -2 * m2.h;
				s = 1;
				n -= 865;
			}
		// Алгоритм отрисовки box
		if (p.getplayercoordinateY() / 1000 <= -num)
			{
				b.rand_box(p.getplayercoordinateY());
				num++;
			}
		if (b.getRect().intersects(p.getRect()))
		{
			p.dx = 0;
			p.dy = 0;
			text.setString("GAME OVER");

			text.setPosition(view.getCenter().x - 100, view.getCenter().y);
		}

	
		window.clear();
		window.setView(view);
		window.draw(m1.sprite);
		window.draw(m2.sprite);
		window.draw(p.sprite);
		window.draw(b.sprite);
		window.draw(text);
		window.display();
	}

	return 0;
}
