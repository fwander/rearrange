#include <Bucket.h>
#include <algorithm>

Bucket::Bucket(std::vector<Point>&& in)
	: points(in)
{
}

std::vector<Bucket> Bucket::build(int num, std::vector<Point>&& points){
	std::vector<Bucket> ret(num,Bucket());

	int index = num/2 - 1;

	build_helper(ilog2(num),index,ret,std::move(points));
	return ret;
}

void Bucket::build_helper(int r, int index,std::vector<Bucket>& ret, std::vector<Point>&& points){
	if (r == 0){
		ret[index] = std::move(Bucket(std::move(points)));
		return;
	}
	std::nth_element(points.begin(), points.begin() + points.size()/2, points.end(), 
		[r](const Point & a, const Point & b) -> bool
		{ 
			return a.value[r%3] > b.value[r%3]; 
		});
	
	auto middle = std::next(points.begin(), points.size() / 2);
	std::vector<Point> lpoints(points.begin(),middle);
	std::vector<Point> rpoints(middle,points.end());

	build_helper(r-1,goLeft(index),ret,std::move(lpoints));
	build_helper(r-1,goRight(index),ret,std::move(rpoints));
}
