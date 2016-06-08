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
		Menu(window,lvl);//вызов меню
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
	Bot Bot1("Car.png", 2000, 1000, 66.0, 130.0),
		Bot2("Car.png", 2000, 1000, 66.0, 130.0),
		Bot3("Car.png", 2000, 1000, 66.0, 130.0),
		Bot4("Car.png", 2000, 1000, 66.0, 130.0),
	    r("Racket1.png", 2000, 1000, 60.0, 110.0);
	r.dy = 250.0/ 170.0;
	Sounds bip("bip.wav");
	Texture Bg;
	Bg.loadFromFile("images/Menu/lvl.jpg");
	//Текст
	Font font;
	font.loadFromFile("nfs_font.ttf");
	Text 
		Money("", font, 20),
		Speed("", font, 20),
		Ttime("", font, 30);
	
	Money.setStyle(Text::Bold);
	Speed.setStyle(Text::Bold);
	Ttime.setStyle(Text::Bold);
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
		d, RNum = 0, BNum = 1, pusk = 0,
		kn[4],check = 0;
	num[0] = 1;
	num[1] = 1;
	num[2] = 1;
	num[3] = 1;
	float BoxTime = 0, pr = 0.0;
	float CostTime;
	long long Sch = 20;
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
				p.Dir = 1;
				p.SpeedG = 0.1;
				p.Update(time);

			}

			if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
			{
				p.Dir = 0; 
				p.SpeedG = 0.1;
				p.Update(time);
			}

			if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) 
			{
				p.Dir = 2;
				k = 1;
				p.Update(time);
				check = 1;
			}

			if (((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) && check == 0)
			{
				p.Dir = 3;
				k = 1;
				p.Update(time);
			}
			check = 0;
			

			if (k == 0)
			{
				p.Dir = 4;
				p.Update(time);

			}
			GetPlayerCoordinateForView(250, p.GetPlayerCoordinateY());
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
		Money.setString("Money\n" + Score.str());
		Money.setPosition(view.getCenter().x - 300 , view.getCenter().y - 340);
		//text speed
		std::ostringstream Speed;
		Speed <<(int) (-p.dy*170);
		speed.setString("  Speed\n" + Speed.str()+" km /h");
		speed.setPosition(view.getCenter().x + 200, view.getCenter().y - 340);
		//text time
		std::ostringstream TimeS;
		TimeS << 90 - gameClock;
		Ttime.setString("       Time\n" + TimeS.str() + " seconds");
		Ttime.setPosition(view.getCenter().x - 105, view.getCenter().y - 360);
		//bip
		if (pusk == 0)
			r.sprite.setPosition(p.GetPlayerCoordinateX()+ 5, p.GetPlayerCoordinateY()+ 10);
		if ((Keyboard::isKeyPressed(Keyboard::Space)) && (racket.life == true))
		{
			pusk = 1;
			racket.life = false;
			racket.sprite.setPosition(1000, 1000);
			r.x = p.GetPlayerCoordinateX() + 5;
			r.y = p.GetPlayerCoordinateY() + 10;
		}
		if (pusk == 1)
		{
			r.Update(1);
			if (r.getRect().intersects(Bot1.getRect()))
			{
				Bot1.y = 1000;
				r.sprite.setPosition(1000, 1000);
				p.PlayerScore += 50;
				pusk = 0;
			}
			if (r.getRect().intersects(Bot2.getRect()))
			{
				Bot2.y = 1000;
				r.sprite.setPosition(1000, 1000);
				p.PlayerScore += 50;
				pusk = 0;
			}
			if (r.getRect().intersects(Bot3.getRect()))
			{
				Bot3.y = 1000;
				r.sprite.setPosition(1000, 1000);
				p.PlayerScore += 50;
				pusk = 0;
			}
			if (r.getRect().intersects(Bot4.getRect()))
			{
				Bot4.y = 1000;
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
		if (p.GetPlayerCoordinateY() <= n)
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
			if (p.GetPlayerCoordinateY() / 5000 <= -r_num)
		{
		racket.rand_Racket(p.GetPlayerCoordinateY());
		RNum++;
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
			if ((p.GetPlayerCoordinateY() / 3000 <= -num[0]))
			{
				if ((bot1.y > p.GetPlayerCoordinateY() - 600) && (bot1.y < p.GetPlayerCoordinateY() + 250))
					num[0]++;
				else
				{
					bot1.RandbBot(p.GetPlayerCoordinateY(), 1);
					bot1.RandColor();
					num[0]++;
					kn[0] = 1;
				}
			}
			if (kn[0] == 1)
				Bot1.Update(1);
			if (Bot1.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
			if ((p.GetPlayerCoordinateY() / 2000 <= -num[1]))
			{
				if ((Bot2.y > p.GetPlayerCoordinateY() - 600) && (Bot2.y < p.GetPlayerCoordinateY() + 250))
					num[1]++;
				else
				{
					Bot2.RandBot(p.getplayercoordinateY(), 2);
					Bot2.RandColor();
					num[1]++;
					kn[1] = 1;
				}
			}
			if (kn[1] == 1)
				Bot2.Update(1);
			if (Bot2.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
			if ((p.GetPlayerCoordinateY() / 2500 <= -num[2]))
			{
				if ((Bot3.y > p.GetPlayerCoordinateY() - 600) && (Bot3.y < p.GetPlayerCoordinateY() + 250))
					num[2]++;
				else
				{
					Bot3.RandBot(p.GetPlayerCoordinateY(), 3);
					Bot3.RandColor();
					num[2]++;
					kn[2] = 1;
				}
			}
			if (kn[2] == 1)
				Bot3.Update(1);
			if (Bot3.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
			if ((p.GetPlayerCoordinateY() / 4000 <= -num[3]))
			{
				if ((Bot4.y > p.GetPlayerCoordinateY() - 600) && (Bot4.y < p.GetPlayerCoordinateY() + 250))
					num[3]++;
				else
				{
					Bot4.RandBot(p.GetPlayerCoordinateY(), 4);
					Bot4.RandColor();
					num[3]++;
					kn[3] = 1;
				}
			}
			if (kn[3] == 1)
				Bot4.Update(1);
			if (Bot4.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
		}
		if (*lvl == 2)
		{
			if ((p.GetPlayerCoordinateY() / 3000 <= -num[0]))
			{
				if ((Bot1.y > p.GetPlayerCoordinateY() - 600) && (Bot1.y < p.GetPlayerCoordinateY() + 250))
					num[0]++;
				else
				{
					Bot1.RandBot(p.GetPlayerCoordinateY(), 1);
					Bot1.RandColor();
					num[0]++;
					kn[0] = 1;
				}
			}
			if (kn[0] == 1)
				Bot1.Update(-1);
			if (Bot1.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
			if ((p.GetPlayerCoordinateY() / 2000 <= -num[1]))
			{
				if ((Bot2.y > p.GetPlayerCoordinateY() - 600) && (Bot2.y < p.GetPlayerCoordinateY() + 250))
					num[1]++;
				else
				{
					Bot2.RandBot(p.GetPlayerCoordinateY(), 2);
					Bot2.RandColor();
					num[1]++;
					kn[1] = 1;
				}
			}
			if (kn[1] == 1)
				Bot2.Update(-1);
			if (Bot2.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
			if ((p.GetPlayerCoordinateY() / 2500 <= -num[2]))
			{
				if ((Bot3.y > p.GetPlayerCoordinateY() - 600) && (Bot3.y < p.GetPlayerCoordinateY() + 250))
					num[2]++;
				else
				{
					Bot3.Rand_Bot(p.GetPlayerCoordinateY(), 3);
					Bot3.Rand_Color();
					num[2]++;
					kn[2] = 1;
				}
			}
			if (kn[2] == 1)
				Bot3.Update(1);
			if (Bot3.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
			if ((p.GetPlayerCoordinateY() / 4000 <= -num[3]))
			{
				if ((Bot4.y > p.GetPlayerCoordinateY() - 600) && (Bot4.y < p.GetPlayerCoordinateY() + 250))
					num[3]++;
				else
				{
					Bot4.RandBot(p.GetPlayerCoordinateY(), 4);
					Bot4.RandColor();
					num[3]++;
					kn[3] = 1;
				}
			}
			if (kn[3] == 1)
				Bot4.Update(1);
			if (Bot4.getRect().intersects(p.getRect()))
			{
				p.dx = 0;
				p.dy = 0;
				p.life = false;

			}
		}
		// Алгоритм отрисовки box
		if (*lvl == 3)
		{
			if (p.GetPlayerCoordinateY() / 1000 <= -b_num)
			{
				b.RandBox(p.GetPlayerCoordinateY());
				BNum++;
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
			window.draw(Bot1.sprite);
			window.draw(Bot2.sprite);
			window.draw(Bot3.sprite);
			window.draw(Bot4.sprite);
		}
		window.draw(racket.sprite);
		window.draw(rectangle);
		window.draw(Circle1);
		window.draw(Circle2);
		window.draw(Money);
		window.draw(Speed);
		window.draw(Ttime);
		

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
			fprintf(file, "%d", Suma);
			fclose(file);
			
			if (Game_over(window,z,p.PlayerScore,p.PlayerScore*pr))
				return true;

		}
		

	}
}

