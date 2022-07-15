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

void scale(vec v, int n) {
	int firstPoint = 5 * (v.bx - v.ax);
	int secondPoint = 5 * (v.by - v.ay);
	std::cout << "Result: {" << firstPoint << ";" << secondPoint << "}" << std::endl;
}

void length(vec v) {
	double length = sqrt(pow((v.bx-v.ax),2) + pow((v.by-v.ay),2));
	std::cout << "The length of the vector AB is " << fabs(length) << std::endl;
}

void normalize(vec v) {
	double length = sqrt(pow((v.bx - v.ax), 2) + pow((v.by - v.ay), 2));
	double firstPoint = v.ax / fabs(length);
	double secondPoint = v.bx / fabs(length);
	std::cout << "Result: {" << firstPoint << ";" << secondPoint << "}" << std::endl;
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
			std::cout << "Vector list:" << std::endl;
			for (int i = 0; i < v.size(); ++i) {
				std::cout << v[i].name << std::endl;
			}
		}
		else if (command == "subtract") {
			std::string v1name;
			std::string v2name;
			std::cout << "Enter name of first vector: ";
			std::cin >> v1name;
			std::cin.ignore(1024, '\n');
			std::cout << "Enter name of second vector: ";
			getline(std::cin,v2name);
			for (int i = 0; i < v.size(); ++i) {
				bool vecFound1 = false;
				bool vecFound2 = false;
				if (v[i].name == v1name) {
					vecFound1 = true;
					for (int j = 0; j <= v.size(); ++j) {
						if (v[j].name == v2name) {
							vecFound2 = true;
							subtract(v[i], v[j]);
							break;
						}
						else if (!vecFound2 && j >= v.size() - 1) {
							std::cerr << "Error code: VS0002. Vector not found.";
						}
					}
					break;
				}
				else if (!vecFound1 && i >= v.size() - 1) {
					std::cerr << "Error code: VS0001. Vector not found.";
					break;
				}
			}
		}
		else if (command == "scale") {
			std::string vname;
			int n;
			std::cout << "Enter name of vector: ";
			std::cin >> vname;
			std::cin.ignore(1024, '\n');
			std::cout << "Enter number: ";
			std::cin >> n;
			for (int i = 0; i < v.size(); ++i) {
				bool vecFound = false;
				if (v[i].name == vname) {
					vecFound = true;
					scale(v[i], n);
				}
				else if (!vecFound && i >= v.size() - 1) {
					std::cerr << "Error code: VS0003. Vector not found.";
					break;
				}
			}
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
					std::cerr << "Error code: VS0004. Vector not found." << std::endl;
				}
			}
		}
		else if (command == "normalize") {
			std::string vname;
			std::cout << "Enter vector name: ";
			std::cin >> vname;
			bool vecFound = false;
			for (int i = 0; i < v.size(); ++i) {
				if (v[i].name == vname) {
					vecFound = true;
					normalize(v[i]);
				}
				else if (!vecFound && i >= v.size() - 1) {
					std::cerr << "Error code: VS0005. Vector not found.";
					break;
				}
			}
		}
		else if(command != "exit") {
			std::cerr << "Error code: C0001. Unknown command! Try again." << std::endl;
		}
	} while (command != "exit");
	return 0;
}