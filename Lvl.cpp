#include "Lvl.h"
bool Lvl(RenderWindow & window,int *lvl)
{
	// создаю текстуры
	Texture LvlBg, Lvl1, lvl2,lvlR1,lvlR2,Money,Money2,Bk,BkR,Lvl3,lvlR3;
	Bk.loadFromFile("images/Menu/Bk.jpg");
	BkR.loadFromFile("images/Menu/Bkr.jpg");
	LvlBg.loadFromFile("images/Menu/lvl.jpg");
	Lvl1.loadFromFile("images/Menu/lvl_1.jpg");
	Lvl2.loadFromFile("images/Menu/lvl_2.jpg");
	LvlR1.loadFromFile("images/Menu/lvl_1r.png");
	LvlR2.loadFromFile("images/Menu/lvl_2r.png");
	Lvl3.loadFromFile("images/Menu/box.png");
	Lvl3R.loadFromFile("images/Menu/boxr.png");
	Money.loadFromFile("images/Menu/Money2.png");
	Money.setSmooth(true);
	Money2.loadFromFile("images/Menu/Money2.png");
	Money2.setSmooth(true);
	// создаю спрайты
	Sprite SLvlB(lvlBg), SLvl1(lvl1), SLvl2(lvl2),SLvl1R(lvlR1), 
		Slvl2R(lvlR2),SMoney(Money),SMoney2(Money2),SBk(Bk),SBkR(BkR),
		SLvl3(lvl3),SLvl3r(lvlR3);
	// позиция спрайта
	SBk.setPosition(0, 0);
	SBkr.setPosition(0, 0);
	SLvl_b.setPosition(0, 0);
	SLvl1.setPosition(130, 400);
	SLvl2.setPosition(370, 400);
	SLvl1r.setPosition(130, 400);
	SLvl2r.setPosition(370, 400);
	SLvl3.setPosition(250,200);
	SLvl3r.setPosition(250, 200);
	SMoney.setPosition(210,535);
	SMoney2.setPosition(450, 535);
	//текст
	Font font;
	font.loadFromFile("times.ttf");
	Text m1("+15%",font ,22),
		m2("+30%", font, 22);
	m1.setPosition(150, 530);
	m1.setColor(Color(104, 183, 0));
	m2.setPosition(390, 530);
	m2.setColor(Color(104, 183, 0));
	bool IsMenu = 1;
	int MenuNum,n =0, k = 0, l = 0,b = 0;
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
		n = 0;
		k = 0;
		l = 0;
		b = 0;
		if (IntRect(130, 400, 139, 135).contains(Mouse::getPosition(window)))
		{
			MenuNum = 1;
			n = 1;
		}
		if (IntRect(370, 400, 139, 135).contains(Mouse::getPosition(window)))
		{
			MenuNum = 2;
			k = 1;
		}
		if (IntRect(0, 0, 87, 50).contains(Mouse::getPosition(window)))
		{
			MenuNum = 3;
			l = 1;
		}
		if (IntRect(250,200, 139, 135).contains(Mouse::getPosition(window)))
		{
			MenuNum = 4;
			b = 1;
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (MenuNum == 1)
			{
				*lvl = 1;
				return true;
			}//если нажали первую кнопку, то выходим из меню 
			if (MenuNum == 2)
			{
				*lvl = 2;
				return true;
			}
			if (MenuNum == 3)
			{
				return false;
			}
			if (MenuNum == 4)
			{
				*lvl = 3;
				return true;
			}

		}
		
		window.draw(SLvlB);
		if (n == 0)
		{
			window.draw(SLvl1);
			
		}
		else
		{
			window.draw(SLvl1R);
		}
		if (k == 0)
		{
			window.draw(SLvl2);

		}
		else
		{
			window.draw(SLvl2R);
		}
		if (l == 0)
		{
			window.draw(SBk);

		}
		else
		{
			window.draw(SBkR);
		}
		if (b == 0)
		{
			window.draw(SLvl3);

		}
		else
		{
			window.draw(SLvl3R);
		
		window.draw(m1);
		window.draw(m2);
		window.draw(SMoney);
		window.draw(SMoney2);
		window.display();
		
	}
	////////////////////////////////////////////////////
}
