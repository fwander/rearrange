#include <Point.h>

Point::Point(unsigned char x, unsigned char y, unsigned char z, int l)
	: location(l)
{
	value[0] = x;
	value[1] = y;
	value[2] = z;
}
