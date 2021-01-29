#include <iostream>
#include <Image.h>

int main(int argc, char* argv[]){
	std::cout << "main" << std::endl;
	fflush(stdout);
	Image ref("ref2.png");
	Image input("input3.png");
	input.rearrange(ref);
	input.encode("out.png");
	return 0;
}
