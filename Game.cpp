#include "Game.h"
bool StartGame(int* z,int * lvl);
void GameRunning(int *z,int *lvl) //ф-ция перезагружает игру , если это необходимо
{
	if (StartGame(z,lvl))
	{
		GameRunning(z,lvl);
	}////если startGame() == true, то вызываем занова ф-цию isGameRunning, которая в свою очередь опять вызывает startGame() 
}
bool StartGame(int *z,int*lvl)
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

