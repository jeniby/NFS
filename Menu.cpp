#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <sstream>
int sum(FILE * file);
using namespace sf;
bool About(RenderWindow & window)
{
	Texture About,Bk,Bkr;
	About.loadFromFile("images/Menu/about.png");
	Bk.loadFromFile("images/Menu/Bk.jpg");
	Bkr.loadFromFile("images/Menu/Bkr.jpg");
	Sprite about(About), bk(Bk), bkr(Bkr);
	bk.setPosition(0, 0);
	bkr.setPosition(0, 0);
	about.setPosition(0, 0);
	int b, menuNum;
	bool isMenu = 1;
	while (isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return false;
			}
		}
		menuNum = 0;
		b = 0;
		if (IntRect(0, 0, 87, 50).contains(Mouse::getPosition(window)))
		{
			b = 1;
			menuNum = 1;
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			
			if (menuNum == 1)
			{
				return false;
			}
		}

		window.draw(about);
		if (b == 0)
		{
			window.draw(bk);

		}
		else
		{
			window.draw(bkr);
		}
		window.display();

	}
}
bool LVL(RenderWindow & window,int *lvl)
{
	// создаю текстуры
	Texture lvl_Bg, lvl_1, lvl_2,lvl_1r,lvl_2r,Money,Money2,Bk,Bkr,lvl_3,lvl_3r;
	Bk.loadFromFile("images/Menu/Bk.jpg");
	Bkr.loadFromFile("images/Menu/Bkr.jpg");
	lvl_Bg.loadFromFile("images/Menu/lvl.jpg");
	lvl_1.loadFromFile("images/Menu/lvl_1.jpg");
	lvl_2.loadFromFile("images/Menu/lvl_2.jpg");
	lvl_1r.loadFromFile("images/Menu/lvl_1r.png");
	lvl_2r.loadFromFile("images/Menu/lvl_2r.png");
	lvl_3.loadFromFile("images/Menu/box.png");
	lvl_3r.loadFromFile("images/Menu/boxr.png");
	Money.loadFromFile("images/Menu/Money2.png");
	Money.setSmooth(true);
	Money2.loadFromFile("images/Menu/Money2.png");
	Money2.setSmooth(true);
	// создаю спрайты
	Sprite lvl_b(lvl_Bg), lvl1(lvl_1), lvl2(lvl_2), lvl1r(lvl_1r), 
		lvl2r(lvl_2r),money(Money),money2(Money2),bk(Bk),bkr(Bkr),
		lvl3(lvl_3),lvl3r(lvl_3r);
	// позиция спрайта
	bk.setPosition(0, 0);
	bkr.setPosition(0, 0);
	lvl_b.setPosition(0, 0);
	lvl1.setPosition(130, 400);
	lvl2.setPosition(370, 400);
	lvl1r.setPosition(130, 400);
	lvl2r.setPosition(370, 400);
	lvl3.setPosition(250,200);
	lvl3r.setPosition(250, 200);
	money.setPosition(210,535);
	money2.setPosition(450, 535);
	//текст
	Font font;
	font.loadFromFile("times.ttf");
	Text m1("+15%",font ,22),
		m2("+30%", font, 22);
	m1.setPosition(150, 530);
	m1.setColor(Color(104, 183, 0));
	m2.setPosition(390, 530);
	m2.setColor(Color(104, 183, 0));
	bool isMenu = 1;
	int menuNum,n =0, k = 0, l = 0,b = 0;
	while (isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return false;
			}
		}
		menuNum = 0;
		n = 0;
		k = 0;
		l = 0;
		b = 0;
		if (IntRect(130, 400, 139, 135).contains(Mouse::getPosition(window)))
		{
			menuNum = 1;
			n = 1;
		}
		if (IntRect(370, 400, 139, 135).contains(Mouse::getPosition(window)))
		{
			menuNum = 2;
			k = 1;
		}
		if (IntRect(0, 0, 87, 50).contains(Mouse::getPosition(window)))
		{
			menuNum = 3;
			l = 1;
		}
		if (IntRect(250,200, 139, 135).contains(Mouse::getPosition(window)))
		{
			menuNum = 4;
			b = 1;
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1)
			{
				*lvl = 1;
				return true;
			}//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2)
			{
				*lvl = 2;
				return true;
			}
			if (menuNum == 3)
			{
				return false;
			}
			if (menuNum == 4)
			{
				*lvl = 3;
				return true;
			}

		}
		
		window.draw(lvl_b);
		if (n == 0)
		{
			window.draw(lvl1);
			
		}
		else
		{
			window.draw(lvl1r);
		}
		if (k == 0)
		{
			window.draw(lvl2);

		}
		else
		{
			window.draw(lvl2r);
		}
		if (l == 0)
		{
			window.draw(bk);

		}
		else
		{
			window.draw(bkr);
		}
		if (b == 0)
		{
			window.draw(lvl3);

		}
		else
		{
			window.draw(lvl3r);
		}
		window.draw(m1);
		window.draw(m2);
		window.draw(money);
		window.draw(money2);
		window.display();
		
	}
	////////////////////////////////////////////////////
}
void menu(RenderWindow & window, int * lvl)
{
	SoundBuffer clickB;//создаём буфер для звука
	clickB.loadFromFile("Sounds/Menu.ogg");//загружаем в него звук
	Sound click(clickB);//создаем звук и загружаем в него звук из буфера
	//загружаем текстуры для меню
	click.setPlayingOffset(milliseconds(3000));
	Texture menuTexture1, menuTexture2, menuTexture3,
		menuTexture4, menuTexture5, menuBackground, Bg, M;
	Bg.loadFromFile("images/Menu/lvl.jpg");
	M.loadFromFile("images/Menu/Money2.png");
	menuTexture1.loadFromFile("images/Menu/Play.jpg");
	menuTexture2.loadFromFile("images/Menu/Cars.jpg");
	menuTexture3.loadFromFile("images/Menu/Options.jpg");
	menuTexture4.loadFromFile("images/Menu/About.jpg");
	menuTexture5.loadFromFile("images/Menu/Exit.jpg");
	menuBackground.loadFromFile("images/Menu/Back.jpg");
	menuTexture1.setSmooth(true);
	menuTexture2.setSmooth(true);
	menuTexture3.setSmooth(true);
	menuTexture4.setSmooth(true);
	menuTexture5.setSmooth(true);
	//Создаем спрайты из наших текстур
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3),
		menu4(menuTexture4), menu5(menuTexture5), menuBg(menuBackground), m(M);

	menu1.setTextureRect(IntRect(205, 202, 230, 60));
	menu2.setTextureRect(IntRect(205, 202, 230, 60));
	menu3.setTextureRect(IntRect(205, 202, 230, 60));
	menu4.setTextureRect(IntRect(205, 202, 230, 60));
	menu5.setTextureRect(IntRect(205, 202, 230, 60));
	bool isMenu = 1;
	int menuNum = 0, suma;
	//Размещаем на экране меню
	menu1.setPosition(315, 180);
	menu2.setPosition(315, 280);
	menu3.setPosition(315, 380);
	menu4.setPosition(315, 480);
	menu5.setPosition(315, 580);
	//позиция фона
	menuBg.setPosition(0, 0);
	//Перемещения центра
	menu1.setOrigin(115, 30);
	menu2.setOrigin(115, 30);
	menu3.setOrigin(115, 30);
	menu4.setOrigin(115, 30);
	menu5.setOrigin(115, 30);
	FILE *file;
	file = fopen("text/Money.txt", "r");
	suma = sum(file);
	fclose(file);
	Font font;
	font.loadFromFile("nfs_font.ttf");
	Text text("", font, 43),

		money("", font, 30);
	money.setColor(Color(104, 183, 0));
	money.setStyle(Text::Bold);
	std::ostringstream Moneystr;
	Moneystr << (int)suma;
	money.setString(Moneystr.str());
	money.setPosition(30, 680);
	//
	RectangleShape rectangle(Vector2f(175, 100));
	rectangle.setOutlineThickness(3);
	rectangle.setOutlineColor(Color(0, 0, 0));
	rectangle.setTexture(&Bg);
	rectangle.setTextureRect(IntRect(0, 300, 200, 200));
	rectangle.setPosition(0, 680);
	m.setPosition(5, 688);
	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				isMenu = false;
			}
		}
		menuNum = 0;
		//возвращаем обычный размер
		menu1.setScale(1.f, 1.f);
		menu2.setScale(1.f, 1.f);
		menu3.setScale(1.f, 1.f);
		menu4.setScale(1.f, 1.f);
		menu5.setScale(1.f, 1.f);
		if (IntRect(200, 150, 230, 60).contains(Mouse::getPosition(window)))
		{
			menu1.setScale(1.05f, 1.05f);
			//click.play();
			menuNum = 1;
		}
		if (IntRect(200, 250, 230, 60).contains(Mouse::getPosition(window)))
		{
			menu2.setScale(1.05f, 1.05f);
			//click.play();
			menuNum = 2;
		}
		if (IntRect(200, 350, 230, 60).contains(Mouse::getPosition(window)))
		{
			menu3.setScale(1.05f, 1.05f);
			//click.play();
			menuNum = 3;
		}
		if (IntRect(200, 450, 230, 60).contains(Mouse::getPosition(window)))
		{
			menu4.setScale(1.05f, 1.05f);
			//click.play();
			menuNum = 4;
		}
		if (IntRect(200, 550, 230, 60).contains(Mouse::getPosition(window)))
		{
			menu5.setScale(1.05f, 1.05f);
			//click.play();
			menuNum = 5;
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1)
			{
				if (LVL(window, lvl))
				{
					isMenu = false;
					return;
				}
			}//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 4)
				if (About(window))
				{
					isMenu = false;
					return;
				}
			if (menuNum == 5)
			{
				window.close();
				isMenu = false;
			}

		}

			window.draw(menuBg);
			window.draw(menu1);
			window.draw(menu2);
			window.draw(menu3);
			window.draw(menu4);
			window.draw(menu5);
			window.draw(rectangle);
			window.draw(money);
			window.draw(m);

			window.display();
		}
		////////////////////////////////////////////////////
	}
