#include <iostream>

void Log(const char* message) {
	std::cout << message << std::endl;
}

int Multipy (int a, int b) {
	Log("Multipy");
	return a * b;
}

int main() {
	std::cout << Multipy(5, 8) << std::endl;
	std::cin.get();
}