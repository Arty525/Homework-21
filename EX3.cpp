#include <iostream>
#include <cmath>

struct vector {
	char b[40];
};

int main() {
	vector a[40];

	std::cout << "Enter name of vector: ";
	char vname;
	std::cin >> vname;
	std::cout << "Enter X coordinate: ";
	int x;
	std::cin >> x;
	std::cout << "Enter Y coordinate: ";
	int y;
	std::cin >> y;

	a[x].b[y] = vname += 'x';

}