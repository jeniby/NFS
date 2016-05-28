#include "File.h"
int sum(FILE * file)
{
	int c, x = 0, s = 0, k = 1, n;
	while ((c = fgetc(file)) != EOF) {
		n = 1;
		if ((c >= (int)'0') && (c <= (int)'9')) {
			if (k == 1) {
				x += c - (int)'0';
				k = 0;
			}
			else {
				x *= 10;
				x += c - (int)'0';
			}

		}
		else if ((c == (int)'\n') || (c == (int)' ')) {
			s += x;
			x = 0;
			k = 1;
		}
		else

			while ((c = fgetc(file)) != EOF) {
				n = 1;
				if ((c == (int)'\n') || (c == (int)' ')) {
					k = 1;
					x = 0;
					n = 1;
					break;
				}
			}

	}
	if ((k == 0) && (n == 1))
		s += x;
	return s;
}
