#ifndef Image_H
#define Image_H

#include <lodepng.h>
#include <Bucket.h>
#include <tuple>
#include <Point.h>

class Image{
	public:
		Image(const std::string& fn);
		~Image() = default;
		Image(Image& rhs) = delete;
		Image& operator=(Image& rhs) = delete;


		void rearrange(Image& other);

		void encode(const std::string& fn);
		
	private:
		std::vector<unsigned char> image;
		unsigned width, height;
		std::vector<Bucket> buckets;
		//inline int fromXY(int x, int y, int spacing){
		//	return x * spacing + y * spacing * width;
		//}
		void set_point(unsigned char* source, unsigned char* dest);
};


#endif
