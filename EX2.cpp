#include <iostream>
#include <vector>
#include <string>

struct sauna {
    bool furnace = false;
    int square = 0;
};

struct garage {
    int square = 0;
};

struct barn {
    int square = 0;
};

struct flr { //План этажа
    int height;
    int rooms = 0;
    int lounge = 0;
    int kitchen = 0;
    int bedroom = 0;
    int kids = 0;
};

struct house {//План дома
    std::vector<flr> f;
    int floors;
    int square;
    bool furnace = false;
};

struct landscape {
    std::vector<house> h;
    std::vector<sauna> s;
    std::vector<garage> g;
    std::vector<barn> b;
    int number;
    int houses = 0;
    int sauna = 0;
    int barn = 0;
    int garage = 0;
};

int main() {
    std::vector<landscape> land;
    std::cout << "Enter number of landscapes: ";
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        land.push_back(landscape());
        land[i].number = i + 1;
        --n;
        std::cout << "Landscape #" << land[i].number << std::endl;
        std::cout << "Enter number of houses on this landscape: ";
        std::cin >> n;
        for (n; n > 0; --n) {
            land[0].h.push_back(house());
        }
    }
    return 0;
}
