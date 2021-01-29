#ifndef Bucket_H
#define Bucket_H

#include<vector>
#include<Point.h>
#include<algorithm>

class Bucket{
	public:
		Bucket(std::vector<Point>&& in);
		Bucket();
		~Bucket();

		static std::vector<Bucket> build(int num, std::vector<Point>&& points);
		std::vector<Point> points;
	private:

		inline static unsigned int rmz(unsigned int in){
			return ~in & (in + 1);
		}

		inline static unsigned int goLeft(unsigned int in){
			int z = ~rmz(in);
			in &= z & (z>>1);
			return in;
		}

		inline static unsigned char goRight(unsigned int in){
			unsigned int z = rmz(in);
			in |= z;
			in &= ~(z>>1);
			return in;
		}
		
		inline static int ilog2(int x) {

			int u = x;

			int s = u;
			int a = s;

			x = 0;

			a = !(a>>16)+~0;   //all 1s if theres anything left after you shift by 16
			x += a & 16;      //if there is something left then add 16 to the running total
			a = (~a & s) | (a & s >> 16); // if there is something left get rid of the first 16 bits and keep looking

			s = a;  //s, the previous a is set to the new a so we we can keep taking bits off if we changed a

			a = !(a>>8)+~0;
			x += a & 8;
			a = (~a & s) | (a & s >> 8);

			s = a;

			a = !(a>>4)+~0;
			x += a & 4;
			a = (~a & s) | (a & s >> 4);

			s = a;

			a = !(a>>2)+~0;
			x += a & 2;
			a = (~a & s) | (a & s >> 2);

			a = !(a>>1)+~0;
			x += a & 1; // same logic all the way to 1 exept you dont need to reset a
				//this process is like counting the most significant bit in binary
			return x ;
		}

		static void build_helper(int r, int index, std::vector<Bucket>& ret, std::vector<Point>&& points);

};

#endif
