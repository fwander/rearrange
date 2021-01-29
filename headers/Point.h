#ifndef Point_H
#define Point_H

#include <vector>

struct Point{
	public:
		Point(unsigned char r, unsigned char g, unsigned char b, int l);

		unsigned char value[3];
		int location;

};

#endif
