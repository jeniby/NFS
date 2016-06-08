#include "Music.h"
String music()
{
	srand(time(NULL));
	int k = rand() % 6 + 1;
	switch (k)
	{
	case 1:
		return "Music/1.ogg";
		break;
	case 2:
		return "Music/2.ogg";
		break;
	case 3:
		return "Music/3.ogg";
		break;
	case 4:
		return "Music/4.ogg";
		break;
	case 5:
		return "Music/5.ogg";
		break;
	case 6:
		return "Music/6.ogg";
		break;
	}
}
