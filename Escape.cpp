#include "Escape.h"
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
	bool IsMenu = 1;
	int MenuNum = 0;
	//перемещаем центр тяжести:)
	M1.setOrigin(115, 30);
	M2.setOrigin(115, 30);
	M3.setOrigin(115, 30);
	//фон
	RectangleShape Rectangle(Vector2f(300, 300));
	//обводочка
	Rectangle.setOutlineThickness(10);
	Rectangle.setTexture(&Bg);
	Rectangle.setTextureRect(IntRect(0, 200, 520, 520));
	while (IsMenu)
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
		Rectangle.setPosition(view.getCenter().x - 150, view.getCenter().y - 150);
		MenuNum = 0;
		M1.setScale(1.f, 1.f);
		M2.setScale(1.f, 1.f);
		M3.setScale(1.f, 1.f);
		int n = view.getCenter().x,
			m = view.getCenter().y;
			if (IntRect(200, 330, 230, 60).contains(Mouse::getPosition(window)))
		{
			M1.setScale(1.05f, 1.05f);
			MenuNum = 1;
		}

		if (IntRect( 200,  430, 230, 60).contains(Mouse::getPosition(window)))
		{
			M2.setScale(1.05f, 1.05f);
			MenuNum = 2;
		}

		if (IntRect(200, 230, 230, 60).contains(Mouse::getPosition(window)))
		{
			M3.setScale(1.05f, 1.05f);
			MenuNum = 3;
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (MenuNum == 3)
				return false;//если нажали первую кнопку, то выходим из меню 
			if (MenuNum == 2)
				return true;
			if (MenuNum == 1)
			{
				*z = 1;
				return true;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			return false;
		window.draw(Rectangle);
		window.draw(M1);
		window.draw(M2);
		window.draw(M3);

		window.display();
	}
	////////////////////////////////////////////////////
}
