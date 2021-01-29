#include <Tree.h>
#include <iostream>

Tree::Tree(char d, int m)
	: depth(d), splitLim(m), leaf(true), lowerBound{127,127,127}
{
	left = NULL;
	right = NULL;
	parent = NULL;
}

Tree::Tree(char d, int m, std::array<unsigned char,3> lb, std::function<unsigned char(unsigned char)> fn, Tree* parent)
	: depth(d), splitLim(m), leaf(true), lowerBound{lb}, parent(parent)
{
	left = NULL;
	right = NULL;
	
	lowerBound[d%3] = fn(lb[d%3]);
}

Tree::~Tree()
{
	if(!leaf){
		delete left;
		delete right;
	}
	else{
		points.clear();
	}
}

void Tree::add(unsigned char* point){
	if(leaf){
		points.emplace_back(std::tuple<unsigned char*, int>(point,-1));
		if (points.size() > splitLim && depth < 72){
			split();
		}
	}
	else{
		if(point[depth%3] < lowerBound[depth%3]){
			left->add(point);
		}
		else{
			right->add(point);
		}
	}

}

void Tree::split(){
	leaf  = false;
	left  = new Tree(depth + 1, splitLim, lowerBound, goLeft, this);
	right = new Tree(depth + 1, splitLim, lowerBound, goRight, this);

	for (int i = 0; i < points.size(); i++){
		if(std::get<0>(points[i])[depth%3] < lowerBound[depth%3]){
			left->add(std::get<0>(points[i]));
		}
		else{
			right->add(std::get<0>(points[i]));
		}
	}
	points.clear();
}

Tree& Tree::find(unsigned char* point){
	if(leaf){
		if (!points.size()){
			//std::cout << "here" << parent->points.size() << parent->left->points.size() << parent->rightI std::endl;

			return parent->other(point);
		}
		return *this;
	}
	if(point[depth%3] < lowerBound[depth%3]){
		return left->find(point);
	}
	else{
		return right->find(point);
	}
}

Tree& Tree::other(unsigned char* point){
	if(point[depth%3] >= lowerBound[depth%3]){
		return left->find(point);
	}
	else{
		return right->find(point);
	}
}

std::vector<std::tuple<unsigned char*,int>>& Tree::get_points(){
	return points;
}
