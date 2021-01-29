#include <Image.h>
#include <iostream>


Image::Image(std::string&& fn)
{
	unsigned error = lodepng::decode(image, width, height, fn);
	std::vector<Point> points;
	for(int i = 0; i < width * height; i++){
		unsigned char x = image[(i<<2)];
		unsigned char y = image[(i<<2)+1];
		unsigned char z = image[(i<<2)+2];
		points.emplace_back(x,y,z,i);
	}
	
	buckets = Bucket::build(128,std::move(points));
}

Image::~Image()
{
}

void Image::set_point(unsigned char* point1, unsigned char* point2){
	point2[0] = point1[0]; 
	point2[1] = point1[1]; 
	point2[2] = point1[2]; 
}

void Image::rearrange(Image& other){
	std::vector<unsigned char> temp(width * 4 * height * 4, 255);
	for(int i = 0; i < buckets.size(); i++){
		Bucket& b = buckets[i];
		for(int p = 0; p < b.points.size(); p++){
			set_point(image.data() + (b.points[p].location << 2), temp.data() + (other.buckets[i].points[p].location << 2));
		}
	}
	image = std::move(temp);
}

void Image::encode(std::string&& fn){
	lodepng::encode(fn, image, width, height);
}
