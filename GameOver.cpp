#include "GameOver.h"
bool GameOver(RenderWindow & window,int *z,int m, int pr)
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
