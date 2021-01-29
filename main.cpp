#include <iostream>
#include <Image.h>

int main(int argc, char* argv[]){
	//useage: ./rearange [reference] [input] [out]
	if (argc != 4){
		std::cout << "useage: ./rearange [reference] [input] [out]" << std::endl;
	}
	Image ref(argv[1]);
	Image input(argv[2]);
	input.rearrange(ref);
	input.encode(argv[3]);
	return 0;
}
