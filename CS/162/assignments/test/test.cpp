#include <iostream>
#include <ctime>

int main() {
	srand(time(NULL));
	std::cout << time(NULL) << std::endl;
	std::cout << rand() % 5 << std::endl;
}
