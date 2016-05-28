#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML\System.hpp> 
#include <SFML\Window.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace sf;
String music()
{
	srand(time(NULL));
	int k = rand() % 6 + 1;
	switch (k)
	{
	case 1:
		return "Music/1.ogg";
		break;
	case 2:
		return "Music/2.ogg";
		break;
	case 3:
		return "Music/3.ogg";
		break;
	case 4:
		return "Music/4.ogg";
		break;
	case 5:
		return "Music/5.ogg";
		break;
	case 6:
		return "Music/6.ogg";
		break;
	}
}
bool Game_over(RenderWindow & window,int *z,int m, int pr)
{
	
	Font font;
	font.loadFromFile("nfs_font.ttf");
	Text text("", font, 43),
		money("", font, 30);
	money.setColor(Color(104, 183, 0));
	money.setStyle(Text::Bold);
	text.setStyle(Text::Bold | Text::Underlined);
	//texture menu
	Texture	Menu1, Menu2, Money4,Bg;
	Bg.loadFromFile("images/Menu/lvl.jpg");
	Money4.loadFromFile("images/Menu/Money2.png");
	Money4.setSmooth(true);
	Menu1.loadFromFile("images/Menu/restart.jpg");
	Menu2.loadFromFile("images/Menu/menu.jpg");
	Menu1.setSmooth(true);
	Menu2.setSmooth(true);
	//sprite menu
	Sprite M1(Menu1), M2(Menu2), money4(Money4);
	M1.setTextureRect(IntRect(205, 202, 230, 60));
	M2.setTextureRect(IntRect(205, 202, 230, 60));
	money4.setPosition(view.getCenter().x - 135, view.getCenter().y - 80);
	bool isMenu = 1;
	int menuNum = 0;
	M1.setOrigin(115, 30);
	M2.setOrigin(115, 30);
	//фон
	RectangleShape rectangle(Vector2f(300, 300));
	//обводочка
	rectangle.setOutlineThickness(10);
	rectangle.setTexture(&Bg);
	rectangle.setTextureRect(IntRect(0, 200, 520, 520));
	std::ostringstream Money1,Money2,Money3;
	Money1 << (int)(m);
	Money2 << (int)(pr);
	Money3 << (int)(m + pr);
	money.setString(Money1.str() +" + " + Money2.str() + " = " + Money3.str());
	money.setPosition(view.getCenter().x - 110, view.getCenter().y - 90);

	while (isMenu)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return false;
			}
		}
		//position
		M1.setPosition(view.getCenter().x, view.getCenter().y);
		M2.setPosition(view.getCenter().x, view.getCenter().y + 100);
		text.setString("game over");
		text.setPosition(view.getCenter().x - 145, view.getCenter().y-160);
		//фон

		rectangle.setPosition(view.getCenter().x - 150, view.getCenter().y - 150);
		menuNum = 0;
		M1.setScale(1.f, 1.f);
		M2.setScale(1.f, 1.f);
		if (IntRect(200, 330, 230, 60).contains(Mouse::getPosition(window)))
		{
			M1.setScale(1.05f, 1.05f);

			menuNum = 1;
		}

		if (IntRect(200, 430, 230, 60).contains(Mouse::getPosition(window)))
		{
			M2.setScale(1.05f, 1.05f);
			menuNum = 2;
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1)
			{
				*z = 1;
				return true;//если нажали первую кнопку, то выходим из меню 
			}
			if (menuNum == 2)
				return true;
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			return false;
		window.draw(rectangle);
		window.draw(M1);
		window.draw(M2);
		window.draw(text);
		window.draw(money);
		window.draw(money4);
		window.display();
	}
	////////////////////////////////////////////////////
}
bool Escape(RenderWindow & window, int *z)
{
	//создаем тексуры для кнопочек
	Texture	Menu1, Menu2 ,Menu3,Bg;
	Menu1.loadFromFile("images/Menu/restart.jpg");
	Menu2.loadFromFile("images/Menu/menu.jpg");
	Menu3.loadFromFile("images/Menu/resume.jpg");
	Bg.loadFromFile("images/Menu/lvl.jpg");
	Menu1.setSmooth(true);
	Menu2.setSmooth(true);
	Menu3.setSmooth(true);
	//создаем спрайты для кнопок
	Sprite M1(Menu1), M2(Menu2), M3(Menu3);
	M1.setTextureRect(IntRect(205, 202, 230, 60));
	M2.setTextureRect(IntRect(205, 202, 230, 60));
	M3.setTextureRect(IntRect(205, 202, 230, 60));
	Menu1.setSmooth(true);
	bool isMenu = 1;
	int menuNum = 0;
	//перемещаем центр тяжести:)
	M1.setOrigin(115, 30);
	M2.setOrigin(115, 30);
	M3.setOrigin(115, 30);
	//фон
	RectangleShape rectangle(Vector2f(300, 300));
	//обводочка
	rectangle.setOutlineThickness(10);
	rectangle.setTexture(&Bg);
	rectangle.setTextureRect(IntRect(0, 200, 520, 520));
	while (isMenu)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return false;
			}
		}
		//position
		M1.setPosition(view.getCenter().x, view.getCenter().y);
		M2.setPosition(view.getCenter().x, view.getCenter().y + 100);
		M3.setPosition(view.getCenter().x, view.getCenter().y - 100);
		//фон
		rectangle.setPosition(view.getCenter().x - 150, view.getCenter().y - 150);
		menuNum = 0;
		M1.setScale(1.f, 1.f);
		M2.setScale(1.f, 1.f);
		M3.setScale(1.f, 1.f);
		int n = view.getCenter().x,
			m = view.getCenter().y;
			if (IntRect(200, 330, 230, 60).contains(Mouse::getPosition(window)))
		{
			M1.setScale(1.05f, 1.05f);
			menuNum = 1;
		}

		if (IntRect( 200,  430, 230, 60).contains(Mouse::getPosition(window)))
		{
			M2.setScale(1.05f, 1.05f);
			menuNum = 2;
		}

		if (IntRect(200, 230, 230, 60).contains(Mouse::getPosition(window)))
		{
			M3.setScale(1.05f, 1.05f);
			menuNum = 3;
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 3)
				return false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2)
				return true;
			if (menuNum == 1)
			{
				*z = 1;
				return true;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			return false;
		window.draw(rectangle);
		window.draw(M1);
		window.draw(M2);
		window.draw(M3);

		window.display();
	}
	////////////////////////////////////////////////////
}
bool startGame(int* z,int * lvl);
void gameRunning(int *z,int *lvl) //ф-ция перезагружает игру , если это необходимо
{
	if (startGame(z,lvl))
	{
		gameRunning(z,lvl);
	}////если startGame() == true, то вызываем занова ф-цию isGameRunning, которая в свою очередь опять вызывает startGame() 
}
bool startGame(int *z,int*lvl)
{
	ContextSettings settings(0, 0, 8, 1, 1, 0);
	RenderWindow window(sf::VideoMode(640, 720), "Need for Speed",7U,settings);
	window.setVerticalSyncEnabled(true);
	if (*z!= 1)
		menu(window,lvl);//вызов меню
	*z = 0;
	Clock clock,
		gameTimeClock;
	int gameClock;
	//камера
	view.reset(sf::FloatRect(0, 700, 640, 720));
	//конструкторы
	Player p("Car.png", 250, 10, 66.0, 130.0);
	Map m1("Map.jpg", -70, -255, 640.0, 865.0);
	Map	m2("Map.jpg", -70, 610, 640.0, 865.0);
	Box b("Box.jpg", 69, 68);
	Racket racket("Racket.png", 66, 66);
	Bot bot1("Car.png", 2000, 1000, 66.0, 130.0),
		bot2("Car.png", 2000, 1000, 66.0, 130.0),
		bot3("Car.png", 2000, 1000, 66.0, 130.0),
		bot4("Car.png", 2000, 1000, 66.0, 130.0),
	    r("Racket1.png", 2000, 1000, 60.0, 110.0);
	r.dy = 250.0/ 170.0;
	Sounds bip("bip.wav");
	Texture Bg;
	Bg.loadFromFile("images/Menu/lvl.jpg");
	//Текст
	Font font;
	font.loadFromFile("nfs_font.ttf");
	Text 
		money("", font, 20),
		speed("", font, 20),
		ttime("", font, 30);
	
	money.setStyle(Text::Bold);
	speed.setStyle(Text::Bold);
	ttime.setStyle(Text::Bold);
	p.texture.setSmooth(true);
	RectangleShape rectangle(Vector2f(500, 100));
	//обводочка
	rectangle.setOutlineThickness(5);
	rectangle.setOutlineColor(Color(0, 0, 0));
	rectangle.setTexture(&Bg);
	//design
	CircleShape Circle1(200),
		Circle2(200);
	//obvodochaka
	Circle1.setOutlineThickness(5);
	Circle1.setOutlineColor(Color(0, 0, 0));
	Circle1.setTexture(&Bg);
	//для второго
	Circle2.setOutlineThickness(5);
	Circle2.setOutlineColor(Color(0, 0, 0));
	Circle2.setTexture(&Bg);
	int k, num[4],
		n = 340, s = 0,
		t = 1, suma,
		d, r_num = 0, b_num = 1, pusk = 0,
		kn[4],check = 0;
	num[0] = 1;
	num[1] = 1;
	num[2] = 1;
	num[3] = 1;
	float box_time = 0, pr = 0.0;
	float const_time;
	long long sch = 20;
	Music m;
	m.openFromFile(music());
	m.play();
	while (window.isOpen())
	{
		

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = 36;
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return false;
			}
		}
		k = 0;
		sch++;
		if ((Keyboard::isKeyPressed(Keyboard::Escape)) && (sch > 20))
		{
			if (Escape(window,z))
			{
				return true;
			}
			sch = 0;
			
		}
		
		if (p.life)
		{
			if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
			{
				p.dir = 1;
				p.speed_g = 0.1;
				p.update(time);

			}

			if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
			{
				p.dir = 0; 
				p.speed_g = 0.1;
				p.update(time);
			}

			if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) 
			{
				p.dir = 2;
				k = 1;
				p.update(time);
				check = 1;
			}

			if (((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) && check == 0)
			{
				p.dir = 3;
				k = 1;
				p.update(time);
			}
			check = 0;
			

			if (k == 0)
			{
				p.dir = 4;
				p.update(time);

			}
			getplayercoordinateforview(250, p.getplayercoordinateY());
			//circli
			Circle1.setPosition(view.getCenter().x - 570, view.getCenter().y - 600);
			Circle2.setPosition(view.getCenter().x + 170, view.getCenter().y - 600);
			rectangle.setPosition(view.getCenter().x -210, view.getCenter().y - 380);
		}
		//таймер
		if (p.life)
			gameClock = gameTimeClock.getElapsedTime().asSeconds();
		//text money
		std::ostringstream Score;
		Score << p.PlayerScore;
		money.setString("Money\n" + Score.str());
		money.setPosition(view.getCenter().x - 300 , view.getCenter().y - 340);
		//text speed
		std::ostringstream Speed;
		Speed <<(int) (-p.dy*170);
		speed.setString("  Speed\n" + Speed.str()+" km /h");
		speed.setPosition(view.getCenter().x + 200, view.getCenter().y - 340);
		//text time
		std::ostringstream Ttime;
		Ttime << 90 - gameClock;
		ttime.setString("       Time\n" + Ttime.str() + " seconds");
		ttime.setPosition(view.getCenter().x - 105, view.getCenter().y - 360);
		//bip
		if (pusk == 0)
			r.sprite.setPosition(p.getplayercoordinateX()+ 5, p.getplayercoordinateY()+ 10);
		if ((Keyboard::isKeyPressed(Keyboard::Space)) && (racket.life == true))
		{
			pusk = 1;
			racket.life = false;
			racket.sprite.setPosition(1000, 1000);
			r.x = p.getplayercoordinateX() + 5;
			r.y = p.getplayercoordinateY() + 10;
		}
		if (pusk == 1)
		{
			r.Update(1);
			if (r.getRect().intersects(bot1.getRect()))
			{
				bot1.y = 1000;
				r.sprite.setPosition(1000, 1000);
				p.PlayerScore += 50;
				pusk = 0;
			}
			if (r.getRect().intersects(bot2.getRect()))
			{
				bot2.y = 1000;
				r.sprite.setPosition(1000, 1000);
				p.PlayerScore += 50;
				pusk = 0;
			}
			if (r.getRect().intersects(bot3.getRect()))
			{
				bot3.y = 1000;
				r.sprite.setPosition(1000, 1000);
				p.PlayerScore += 50;
				pusk = 0;
			}
			if (r.getRect().intersects(bot4.getRect()))
			{
				bot4.y = 1000;
				r.sprite.setPosition(1000, 1000);
				p.PlayerScore += 50; 
				pusk = 0;
			}
			if (r.getRect().intersects(b.getRect()))
			{
				b.y = 1000;
				b.sprite.setPosition(b.x,b.y);
				r.sprite.setPosition(1000, 1000);
				p.PlayerScore += 50;
				pusk = 0;
			}
		}
		// Алгоритм отрисовки карты
		if (p.getplayercoordinateY() <= n)
			if (s == 1)
			{
				m1.sprite.setPosition(-70, m1.y - 2 * m1.h);
				m1.y += -2 * m1.h;
				s = 0;
				n -= 865;
			}
			else
			{
				m2.sprite.setPosition(-70, m2.y - 2 * m2.h);
				m2.y += -2 * m2.h;
				s = 1;
				n -= 865;
			}
		
		// Алгоритм отрисовки ракет
		if (!racket.life)
			if (p.getplayercoordinateY() / 5000 <= -r_num)
		{
		racket.rand_Racket(p.getplayercoordinateY());
		r_num++;
		}
		if (racket.getRect().intersects(p.getRect()))
		{
		racket.life = true;
		}
		if(racket.life)
			racket.sprite.setPosition(view.getCenter().x - 310, view.getCenter().y - 205);
		//алгорит отрисовки ботов
		if (*lvl == 1)
		{
			if ((p.getplayercoordinateY() / 3000 <= -num[0]))
			{
				if ((bot1.y > p.getplayercoordinateY() - 600) && (bot1.y < p.getplayercoordinateY() + 250))
					num[0]++;
				else
				{
					bot1.Rand_Bot(p.getplayercoordinateY(), 1);
					bot1.Rand_Color();
					num[0]++;
					kn[0] = 1;
				}
			}
			if (kn[0] == 1)
				bot1.Update(1);
			if (bot1.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
			if ((p.getplayercoordinateY() / 2000 <= -num[1]))
			{
				if ((bot2.y > p.getplayercoordinateY() - 600) && (bot2.y < p.getplayercoordinateY() + 250))
					num[1]++;
				else
				{
					bot2.Rand_Bot(p.getplayercoordinateY(), 2);
					bot2.Rand_Color();
					num[1]++;
					kn[1] = 1;
				}
			}
			if (kn[1] == 1)
				bot2.Update(1);
			if (bot2.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
			if ((p.getplayercoordinateY() / 2500 <= -num[2]))
			{
				if ((bot3.y > p.getplayercoordinateY() - 600) && (bot3.y < p.getplayercoordinateY() + 250))
					num[2]++;
				else
				{
					bot3.Rand_Bot(p.getplayercoordinateY(), 3);
					bot3.Rand_Color();
					num[2]++;
					kn[2] = 1;
				}
			}
			if (kn[2] == 1)
				bot3.Update(1);
			if (bot3.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
			if ((p.getplayercoordinateY() / 4000 <= -num[3]))
			{
				if ((bot4.y > p.getplayercoordinateY() - 600) && (bot4.y < p.getplayercoordinateY() + 250))
					num[3]++;
				else
				{
					bot4.Rand_Bot(p.getplayercoordinateY(), 4);
					bot4.Rand_Color();
					num[3]++;
					kn[3] = 1;
				}
			}
			if (kn[3] == 1)
				bot4.Update(1);
			if (bot4.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
		}
		if (*lvl == 2)
		{
			if ((p.getplayercoordinateY() / 3000 <= -num[0]))
			{
				if ((bot1.y > p.getplayercoordinateY() - 600) && (bot1.y < p.getplayercoordinateY() + 250))
					num[0]++;
				else
				{
					bot1.Rand_Bot(p.getplayercoordinateY(), 1);
					bot1.Rand_Color();
					num[0]++;
					kn[0] = 1;
				}
			}
			if (kn[0] == 1)
				bot1.Update(-1);
			if (bot1.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
			if ((p.getplayercoordinateY() / 2000 <= -num[1]))
			{
				if ((bot2.y > p.getplayercoordinateY() - 600) && (bot2.y < p.getplayercoordinateY() + 250))
					num[1]++;
				else
				{
					bot2.Rand_Bot(p.getplayercoordinateY(), 2);
					bot2.Rand_Color();
					num[1]++;
					kn[1] = 1;
				}
			}
			if (kn[1] == 1)
				bot2.Update(-1);
			if (bot2.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
			if ((p.getplayercoordinateY() / 2500 <= -num[2]))
			{
				if ((bot3.y > p.getplayercoordinateY() - 600) && (bot3.y < p.getplayercoordinateY() + 250))
					num[2]++;
				else
				{
					bot3.Rand_Bot(p.getplayercoordinateY(), 3);
					bot3.Rand_Color();
					num[2]++;
					kn[2] = 1;
				}
			}
			if (kn[2] == 1)
				bot3.Update(1);
			if (bot3.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
			if ((p.getplayercoordinateY() / 4000 <= -num[3]))
			{
				if ((bot4.y > p.getplayercoordinateY() - 600) && (bot4.y < p.getplayercoordinateY() + 250))
					num[3]++;
				else
				{
					bot4.Rand_Bot(p.getplayercoordinateY(), 4);
					bot4.Rand_Color();
					num[3]++;
					kn[3] = 1;
				}
			}
			if (kn[3] == 1)
				bot4.Update(1);
			if (bot4.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
		}
		// Алгоритм отрисовки box
		if (*lvl == 3)
		{
			if (p.getplayercoordinateY() / 1000 <= -b_num)
			{
				b.rand_box(p.getplayercoordinateY());
				b_num++;
			}
			if (b.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
		}
		if (90 - gameClock == 0)
			p.life = false;
		window.clear();
		window.setView(view);
		window.draw(m1.sprite);
		window.draw(m2.sprite);
		window.draw(r.sprite);
		window.draw(p.sprite);
		if (*lvl == 3 )
			window.draw(b.sprite);
		if ((*lvl == 2) || (*lvl == 1))
		{
			window.draw(bot1.sprite);
			window.draw(bot2.sprite);
			window.draw(bot3.sprite);
			window.draw(bot4.sprite);
		}
		window.draw(racket.sprite);
		window.draw(rectangle);
		window.draw(Circle1);
		window.draw(Circle2);
		window.draw(money);
		window.draw(speed);
		window.draw(ttime);
		

		window.display();

		if (!p.life)
		{
			if (*lvl == 1)
				pr = 0.15;
			if (*lvl == 2)
				pr = 0.3;
			if (*lvl == 3)
				pr = 0.0;
			FILE *file;
			file = fopen("text/Money.txt", "r");
			suma = sum(file) + p.PlayerScore + int(p.PlayerScore*pr);
			fclose(file);
			
			file = fopen("text/Money.txt", "w");
			fprintf(file, "%d", suma);
			fclose(file);
			
			if (Game_over(window,z,p.PlayerScore,p.PlayerScore*pr))
				return true;

		}
		

	}
}
