#ifndef Point_H
#define Point_H

#include <vector>

struct Point{
	public:
		constexpr Point(unsigned char r, unsigned char g, unsigned char b, size_t l)
			: value{r,g,b}, location(l) {}

		unsigned char value[3];
		size_t location;

};

#endif
