#include "About.h"
bool About(RenderWindow & window)
{
	Texture About,Bk,BkRed;
	About.loadFromFile("images/Menu/about.png");
	Bk.loadFromFile("images/Menu/Bk.jpg");
	BkRed.loadFromFile("images/Menu/Bkr.jpg");
	Sprite SAbout(About), SBk(Bk), SBkRed(BkRed);
	SBk.setPosition(0, 0);
	SBkRed.setPosition(0, 0);
	SAbout.setPosition(0, 0);
	int Num, MenuNum;
	bool IsMenu = 1;
	while (IsMenu)
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
		MenuNum = 0;
		Num = 0;
		if (IntRect(0, 0, 87, 50).contains(Mouse::getPosition(window)))
		{
			Num = 1;
			MenuNum = 1;
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			
			if (MenuNum == 1)
			{
				return false;
			}
		}

		window.draw(SAbout);
		if (Num == 0)
		{
			window.draw(SBk);

		}
		else
		{
			window.draw(SBkRed);
		}
		window.display();

	}
}
