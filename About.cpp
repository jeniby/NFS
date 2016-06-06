#include "About.h"
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
