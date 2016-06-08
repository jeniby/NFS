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
	Sprite Menu1(menuTexture1), Menu2(menuTexture2), Menu3(menuTexture3),
		Menu4(menuTexture4), Menu5(menuTexture5), MenuBg(menuBackground), m(M);

	Menu1.setTextureRect(IntRect(205, 202, 230, 60));
	Menu2.setTextureRect(IntRect(205, 202, 230, 60));
	Menu3.setTextureRect(IntRect(205, 202, 230, 60));
	Menu4.setTextureRect(IntRect(205, 202, 230, 60));
	Menu5.setTextureRect(IntRect(205, 202, 230, 60));
	bool IsMenu = 1;
	int MenuNum = 0, Suma;
	//Размещаем на экране меню
	Menu1.setPosition(315, 180);
	Menu2.setPosition(315, 280);
	Menu3.setPosition(315, 380);
	Menu4.setPosition(315, 480);
	Menu5.setPosition(315, 580);
	//позиция фона
	MenuBg.setPosition(0, 0);
	//Перемещения центра
	Menu1.setOrigin(115, 30);
	Menu2.setOrigin(115, 30);
	Menu3.setOrigin(115, 30);
	Menu4.setOrigin(115, 30);
	Menu5.setOrigin(115, 30);
	FILE *file;
	file = fopen("text/Money.txt", "r");
	Suma = Sum(file);
	fclose(file);
	Font font;
	font.loadFromFile("nfs_font.ttf");
	Text text("", font, 43),

		Money("", font, 30);
	Money.setColor(Color(104, 183, 0));
	Money.setStyle(Text::Bold);
	std::ostringstream Moneystr;
	Moneystr << (int)Suma;
	Money.setString(Moneystr.str());
	Money.setPosition(30, 680);
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
		Menu1.setScale(1.f, 1.f);
		Menu2.setScale(1.f, 1.f);
		Menu3.setScale(1.f, 1.f);
		Menu4.setScale(1.f, 1.f);
		Menu5.setScale(1.f, 1.f);
		if (IntRect(200, 150, 230, 60).contains(Mouse::getPosition(window)))
		{
			Menu1.setScale(1.05f, 1.05f);
			//click.play();
			menuNum = 1;
		}
		if (IntRect(200, 250, 230, 60).contains(Mouse::getPosition(window)))
		{
			Menu2.setScale(1.05f, 1.05f);
			//click.play();
			menuNum = 2;
		}
		if (IntRect(200, 350, 230, 60).contains(Mouse::getPosition(window)))
		{
			Menu3.setScale(1.05f, 1.05f);
			//click.play();
			menuNum = 3;
		}
		if (IntRect(200, 450, 230, 60).contains(Mouse::getPosition(window)))
		{
			Menu4.setScale(1.05f, 1.05f);
			//click.play();
			menuNum = 4;
		}
		if (IntRect(200, 550, 230, 60).contains(Mouse::getPosition(window)))
		{
			Menu5.setScale(1.05f, 1.05f);
			//click.play();
			menuNum = 5;
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1)
			{
				if (Lvl(window, lvl))
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

			window.draw(MenuBg);
			window.draw(Menu1);
			window.draw(Menu2);
			window.draw(Menu3);
			window.draw(Menu4);
			window.draw(Menu5);
			window.draw(rectangle);
			window.draw(Money);
			window.draw(m);

			window.display();
		}
		////////////////////////////////////////////////////
	}
