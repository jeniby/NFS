#include "Menu.h"
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
