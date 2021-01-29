#ifndef Tree_H
#define Tree_H

#include <vector>
#include <array>
#include <tuple>
#include <functional>

class Tree{
	public:
		Tree(char d, int m, std::array<unsigned char, 3> lb,std::function<unsigned char(unsigned char)> fn,  Tree* parent);
		Tree(char d, int m);
		~Tree();
		Tree(Tree& rhs) = delete;
		Tree& operator=(Tree& rhs) = delete;

		void add(unsigned char* point);
		Tree& find(unsigned char* point);
		Tree& other(unsigned char* point);

		std::vector<std::tuple<unsigned char*,int>>& get_points();

	private:
		std::vector<std::tuple<unsigned char*, int>> points;
		Tree* left;
		Tree* right;
		Tree* parent;
		char depth;
		int splitLim;
		std::array<unsigned char, 3> lowerBound;
		bool leaf;

		void split();

		inline static unsigned char rmz(unsigned char in){
			return ~in & (in + 1);
		}

		inline static unsigned char goLeft(unsigned char in){
			char z = ~rmz(in);
			in &= z & (z>>1);
			return in;
		}

		inline static unsigned char goRight(unsigned char in){
			unsigned char z = rmz(in);
			in |= z;
			in &= ~(z>>1);
			return in;
		}
};

#endif
