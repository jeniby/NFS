#include "Lvl.h"
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
