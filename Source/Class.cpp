#include "../Headers/Class.h"
class Player { // класс Игрока
private:
	float x, y;
public:
	float  w, h, dx = 0.0, dy = 0.0, SpeedG = 0.0, SpeedV = 0.0021, n;//координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
	int Dir = 0, PlayerScore = 0, k = 0; //направление (direction) движения и
	bool life = true;
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
		return FloatRect(x + 5, y + 5, w - 5, h - 5);
	}

	void Update(float time) //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
	{
		switch (Dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
		{
		case 0:
			dx = -5 * SpeedG*dy;
			x += dx*time;
			if (x > 405)
				x -= dx*time;
			break;
		case 1:
			dx = 5 * SpeedG*dy;
			x += dx*time;
			if (x < 20)
				x -= dx*time;
			break;
		case 2:
			dx = 0;
			if (dy < -0.001)
				dy += 5 * SpeedV;
			else
				dy = 0;
			y += dy*time;
			n = 1;
			break;
		case 3:
			dx = 0;
			if (dy * 170 > -100)
				dy += -SpeedV;
			y += dy*time;

			n = 1;
			break;
		case 4:
			if (dy <= -0.0001)
				n = 0.9969;
			else
				dy = 0;
			dy = n*dy;
			dx = 0;
			y += dy*time;
			break;
		}
		k++;
		k += (dy * -170) / 10;
		if (k > 60)
		{
			PlayerScore++;
			k = 0;
		}
		sprite.setPosition(x, y); //выводим спрайт в позицию x y . бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.

	}
	float GetPlayerCoordinateX() {	//этим методом будем забирать координату Х	
		return x;
	}
	float GetPlayerCoordinateY() {	//этим методом будем забирать координату Y 	
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
class Box
{
public:
	float x, y, w, h;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	Box(String F, float W, float H)
	{
		File = F;
		w = W; h = H;
		image.loadFromFile("Images/" + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setPosition(1000, 1000);
	}
	FloatRect getRect()
	{
		return FloatRect(x, y, w, h);
	}

	void RandBox(float a)
	{
		srand(time(NULL));
		int k = rand() % 4 + 1;
		switch (k) {
		case 1: sprite.setPosition(45, a - 600);
			x = 45;
			y = a - 600;
			break;
		case 2: sprite.setPosition(150, a - 600);
			x = 150;
			y = a - 600;
			break;
		case 3: sprite.setPosition(280, a - 600);
			x = 280;
			y = a - 600;
			break;
		case 4: sprite.setPosition(380, a - 600);
			x = 380;
			y = a - 600;
			break;

		}

	}
};
class Sounds
{
public:
	SoundBuffer bufer;
	Sound s;
	Sounds(String F)
	{
		bufer.loadFromFile("Sounds/" + F);
		s = Sound(bufer);
		s.setPlayingOffset(milliseconds(1500));
	}
};
class Bot {
public:
	float x, y, w, h, dy;
	String File; //файл с расширением
	Image image;//сфмл изображение
	Texture texture;//сфмл текстура
	Sprite sprite;//сфмл спрайт

	Bot(String F, float X, float Y, float W, float H) {  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
		File = F;//имя файла+расширение
		w = W; h = H;//высота и ширина
		image.loadFromFile("Images/" + File);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. В нашем случае "hero.png" и получится запись идентичная 	image.loadFromFile("images/hero/png");
		image.createMaskFromColor(Color(255, 0, 0));
		texture.loadFromImage(image);//закидываем наше изображение в текстуру
		sprite.setTexture(texture);//заливаем спрайт текстурой
		x = X; y = Y;//координата появления спрайта
		sprite.setPosition(x, y);
		dy = ((float)(rand() % 20 + 40)) / 170;
	}
	void RandBot(float a, int k)
	{

		switch (k) {
		case 1: sprite.setPosition(45, a - 600);
			x = 46;
			y = a - 600;
			break;
		case 2: sprite.setPosition(150, a - 600);
			x = 156;
			y = a - 600;
			break;
		case 3: sprite.setPosition(280, a - 600);
			x = 274;
			y = a - 600;
			break;
		case 4: sprite.setPosition(380, a - 600);
			x = 374;
			y = a - 600;
			break;
		}
	}
	FloatRect getRect()
	{
		return FloatRect(x + 5, y + 5, w - 5, h - 5);
	}
	void Update(int d)
	{
		y -= d*dy * 32;
		sprite.setPosition(x, y);
	}
	void RandColor()
	{
		srand(time(NULL));
		int k = rand() % 4 + 1;
		switch (k)
		{
		case 1:
			sprite.setColor(Color(187, 53, 10));
			break;
		case 2:
			sprite.setColor(Color(107, 186, 0));
			break;
		case 3:
			sprite.setColor(Color(0, 198, 255));
			break;
		case 4:
			sprite.setColor(Color(255, 252, 0));
			break;
		}
	}
};
class Racket
{
public:
	float x, y, w, h;
	bool life;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	Racket(String F, float W, float H)
	{
		File = F;
		w = W; h = H;
		image.loadFromFile("Images/" + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setPosition(1000, 1000);
		life = false;
	}
	FloatRect getRect()
	{
		return FloatRect(x, y, w, h);
	}

	void RandRacket(float a)
	{
		int k = rand() % 4 + 1;
		switch (k) {
		case 1: sprite.setPosition(45, a - 600);
			x = 45;
			y = a - 600;
			break;
		case 2: sprite.setPosition(150, a - 600);
			x = 150;
			y = a - 600;
			break;
		case 3: sprite.setPosition(280, a - 600);
			x = 280;
			y = a - 600;
			break;
		case 4: sprite.setPosition(380, a - 600);
			x = 380;
			y = a - 600;
			break;

		}

	}
};
