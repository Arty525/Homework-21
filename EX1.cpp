#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

struct statement {
	std::string name;
	std::string date;
	int payment;
};

void add(std::ofstream& file, statement& entry) {
	std::cout << "Enter name: ";

	std::getline(std::cin, entry.name);

	std::cout << "Enter date: ";

	std::getline(std::cin, entry.date);

	std::cout << "Enter payment: ";

	std::cin >> entry.payment;

	int lenName = entry.name.length();

	int lenDate = entry.date.length();

	file.write((char*)&lenName, sizeof(lenName));
	file.write(entry.name.c_str(), lenName);
	file.write((char*)&lenDate, sizeof(lenDate));
	file.write(entry.date.c_str(), lenDate);
	file.write((char*)&entry.payment, sizeof(entry.payment));
}

void read(std::ifstream& file, statement& entry) {
	while (!file.eof()) {
		int lenName;
		int lenDate;
		file.read((char*)&lenName, sizeof(lenName));
		entry.name.resize(lenName);
		file.read((char*)entry.name.c_str(), lenName);
		file.read((char*)&lenDate, sizeof(lenDate));
		entry.date.resize(lenDate);
		file.read((char*)entry.date.c_str(), lenDate);
		file.read((char*)&entry.payment, sizeof(entry.payment));
		std::cout << entry.name << " " << entry.date << " " << entry.payment << std::endl;
	}
}

int main() {
	statement entry;

	std::ofstream fileWrite("D:\\RTY\\GITHUB\\Repositories\\homework-21\\EX1\\statement.bin", std::ios::app);
	std::ifstream fileRead("D:\\RTY\\GITHUB\\Repositories\\homework-21\\EX1\\statement.bin", std::ios::binary);
	std::string command;

	std::cout << "Enter command: ";
	std::getline(std::cin, command);

	if (command == "add") {
		add(fileWrite, entry);
	}

	if (command == "read") {
		read(fileRead, entry);
	}

	return 0;
}