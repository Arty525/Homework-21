#include <iostream>
#include <cmath>
#include <string>
#include <vector>

struct  vec {
	std::string name;
	int ax;
	int ay;
	int bx;
	int by;
};

struct field {
	char py[40];
};

void view(field px[]) {
	for (int i = 0; i < 40; ++i) {
		for (int j = 0; j < 40; ++j) {
			std::cout << px[i].py[j] << " ";
		}
		std::cout << std::endl;
	}
}

void add(vec& v, field px[]) {
	std::cout << "Enter name of first point: ";
	char pfname;
	std::cin >> pfname;
	std::cout << "Enter X coordinate: ";
	int x;
	std::cin >> x;
	std::cout << "Enter Y coordinate: ";
	int y;
	std::cin >> y;

	px[x].py[y] = pfname;
	v.ax = x;
	v.ay = y;

	std::cout << "Enter name of second point: ";
	char psname;
	std::cin >> psname;
	std::cout << "Enter X coordinate: ";
	std::cin >> x;
	std::cout << "Enter Y coordinate: ";
	std::cin >> y;

	px[x].py[y] = psname;
	v.name += pfname;
	v.name += psname;
	v.bx = x;
	v.by = y;

	std::cout << "Vector " << v.name << " " << pfname << "(" << v.ax << ";" << v.ay << ")" 
			<< " " << psname << "(" << v.bx << ";" << v.by << ")" << " written." << std::endl;
}

void subtract(vec v1, vec v2) {
	int firstPoint = (v1.bx - v1.ax) - (v2.bx - v2.ax);
	int secondPoint = (v1.by - v1.ay) - (v2.by - v2.ay);
	std::cout << "The vector difference is {" << firstPoint << ";" << secondPoint << "}" << std::endl;
}

//AB = { Bx - Ax; By - Ay } = { 5 - 2; 5 - 2 } = { 3; 3 }
//
//CD = { Dx - Cx; Dy - Cy } = { 4 - 3; 4 - 3 } = { 1; 1 }
//
//Найдем значение суммы(разности) векторов:
//
//AB - CD = { ABx - CDx; ABy - CDy } = { 3 - 1; 3 - 1 } = { 2; 2 }

void scale() {

}

void length(vec v) {
	double length = sqrt(pow((v.bx-v.ax),2) + pow((v.by-v.ay),2));
	std::cout << "The length of the vector AB is " << fabs(length) << std::endl;
}

void normalize() {

}

int main() {
	field px[40];
	std::vector<vec> v;
	std::string command;
	int counter = 0;

	for (int i = 0; i < 40; ++i) {
		for (int j = 0; j < 40; ++j) {
			px[i].py[j] = '.';
		}
	}

	std::cout << "COMMAND LIST:" << std::endl << "add - add new vector" << std::endl << "subtract - subtraction of two vectors" << std::endl
		<< "scale - multiplication of a vector by a scalar" << std::endl << "length - find the length of a vector" << std::endl
		<< "normalize - vector normalization" << std::endl;
	do {
		std::cout << "Enter command: ";
		std::cin >> command;

		if (command == "add") {
			v.push_back(vec());
			add(v[counter], px);
			++counter;
			view(px);
		}
		else if (command == "subtract") {
			std::string v1name;
			std::string v2name;
			std::cout << "Enter name of first vector: ";
			std::cin >> v1name;
			std::cin.ignore(1024, '\n');
			std::cout << "Enter name of second vector: ";
			getline(std::cin,v2name);
			
			std::cout << v1name << std::endl << v2name << std::endl;

			for (int i = 0; i < v.size(); ++i) {
				std::cout << v[i].name << std::endl;
				if (v1name == v[i].name) {
					for (int j = 0; j < v.size(); ++j) {
						std::cout << v[j].name << std::endl;
						if (v2name == v[j].name) {
							subtract(v[i], v[j]);
						}
						else {
							std::cout << "Vector not found2.";
							break;
						}
						break;
					}
					break;
				}
				else {
					std::cout << "Vector not found1.";
					break;
				}
			}
		}
		else if (command == "scale") {
			scale();
		}
		else if (command == "length") {
			std::string vname;
			std::cout << "Enter vector's name: ";
			std::cin >> vname;
			for (int i = 0; i < v.size(); ++i) {
				if (vname == v[i].name) {
					length(v[i]);
					break;
				}
				else {
					std::cout << "Vector not found" << std::endl;
				}
			}
		}
		else if (command == "normalize") {
			normalize();
		}
		else if(command != "exit") {
			std::cout << "Unknown command! Try again." << std::endl;
		}
	} while (command != "exit");
	return 0;
}