#include <SFML/Graphics.hpp>
#include <SFML\System.hpp> 
#include <SFML\Window.hpp>
#include <iostream>
#include "view.h"
using namespace sf;
class Player { // ����� ������
private:
	float x, y;
public:
	float  w, h, dx = 0, dy = 0.000005, speed_g = 0,speed_v = 0.00006,n; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
	int dir = 0; //����������� (direction) �������� ������
	String File; //���� � �����������
	Image image;//���� �����������
	Texture texture;//���� ��������
	Sprite sprite;//���� ������

	Player(String F, float X, float Y, float W, float H) {  //����������� � �����������(�����������) ��� ������ Player. ��� �������� ������� ������ �� ����� �������� ��� �����, ���������� � � �, ������ � ������
		File = F;//��� �����+����������
		w = W; h = H;//������ � ������
		image.loadFromFile("Images/" + File);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������. � ����� ������ "hero.png" � ��������� ������ ���������� 	image.loadFromFile("images/hero/png");
		image.createMaskFromColor(Color(255, 0, 0));
		texture.loadFromImage(image);//���������� ���� ����������� � ��������
		sprite.setTexture(texture);//�������� ������ ���������
		x = X; y = Y;//���������� ��������� �������
	}



	void update(float time) //������� "���������" ������� ������. update - ����������. ��������� � ���� ����� SFML , ���������� ���� �������� ����������, ����� ��������� ��������.
	{
		switch (dir)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
		{
		case 0: dx = speed_g; x += dx*time; if (x > 405) x -= dx*time; break;
		case 1: dx = -speed_g; x += dx*time; if (x < 20) x -= dx*time;break;//�� ���� ������ ������������� ��������, �� ������ ��������. ����������, ��� �������� ���� ������ �����
		case 2: dx = 0; if (dy < 0.11)  dy += 2 * speed_v; y += dy*time; n = 1; break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ ����
		case 3: dx = 0; if (dy > -0.1) dy += -speed_v; y += dy*time; n = 1;break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ �����
		case 4: n = n*0.9999; dx = 0; y += n*dy*time; break;
			}

			
			sprite.setPosition(x, y); //������� ������ � ������� x y , ����������. ���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����.
		
	}
	float getplayercoordinateX() {	//���� ������� ����� �������� ���������� �	
		return x;
	}
	float getplayercoordinateY() {	//���� ������� ����� �������� ���������� Y 	
		return y;
	}
};
class Map {
	public:
		float x, y, w, h;
		String File; //���� � �����������
		Image image;//���� �����������
		Texture texture;//���� ��������
		Sprite sprite;//���� ������
		Map(String F, float X, float Y, float W, float H) {  //����������� � �����������(�����������) ��� ������ Player. ��� �������� ������� ������ �� ����� �������� ��� �����, ���������� � � �, ������ � ������
			File = F;//��� �����+����������
			w = W; h = H;//������ � ������
			image.loadFromFile("Images/" + File);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������. � ����� ������ "hero.png" � ��������� ������ ���������� 	image.loadFromFile("images/hero/png");
			texture.loadFromImage(image);//���������� ���� ����������� � ��������
			sprite.setTexture(texture);//�������� ������ ���������
			x = X; y = Y;//���������� ��������� �������
			sprite.setPosition(x, y);
		}

};
int main()
{
	RenderWindow window(sf::VideoMode(640, 720), "Need for Speed");
	Clock clock;
	view.reset(sf::FloatRect(0, 700, 640, 720)); 
	Player p("Car.pbm", 250, 10, 96.0, 96.0);
	Map m1("Map.jpg", -70, -255, 640.0, 865.0);
	Map	m2("Map.jpg", -70, 610, 640.0, 865.0);
	int k, n = 340, s = 0;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		k = 0;
		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
			p.dir = 1; p.speed_g = 0.1;
			p.update(time);//dir =1 - ����������� �����, speed =0.1 - �������� ��������. �������� - ����� �� ��� ����� �� �� ��� �� �������� � ����� �� ���������� ������ ���

		}

		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			p.dir = 0; p.speed_g = 0.1;//����������� ������, �� ����
			p.update(time);
		}

		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
			p.dir = 3; k = 1; //p.speed_v = 0.1;//����������� ����, �� ����
			p.update(time);
			getplayercoordinateforview(250, p.getplayercoordinateY());
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //���� ������ ������� ������� ����� ��� ���� ����� �
			p.dir = 2; k = 1; //p.speed_v = 0.1;//����������� �����, �� ����
			p.update(time);
			getplayercoordinateforview(250, p.getplayercoordinateY());
		}
		if (k == 0)
		{
			p.dir = 4;
			p.update(time);
			getplayercoordinateforview(250, p.getplayercoordinateY());
		}
		// �������� ��������� �����
		if (p.getplayercoordinateY() <= n)
			if (s == 1)
			{
				m1.sprite.setPosition(-70, m1.y - 2*m1.h);
				m1.y += -2 * m1.h;
				s = 0;
				n -= 865;
			}
			else 
			{
				m2.sprite.setPosition(-70, m2.y - 2* m2.h);
				m2.y += -2 * m2.h;
				s = 1;
				n -= 865;
			}
		printf("%f\n", p.dy);
		window.clear();
		window.draw(m1.sprite);
		window.draw(m2.sprite);
		window.draw(p.sprite);
		window.setView(view);
		window.display();
	}

	return 0;
}