#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

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
    int rooms = 0;
    int height = 0;
    int lounge = 0;
    int kitchen = 0;
    int bedroom = 0;
    int kids = 0;
};

struct house {//План дома
    std::vector<flr> f;
    int floors = 0;
    int square = 0;
    bool furnace = false;
};

struct landscape {
    std::vector<house> h;
    std::vector<sauna> s;
    std::vector<garage> g;
    std::vector<barn> b;
    int squareOfBuildings = 0;
    int number = 0;
    int houses = 0;
    int sauna = 0;
    int barn = 0;
    int garage = 0;
};

int main() {
    int totalSquareOfBuildings = 0;
    std::vector<landscape> land;
    std::cout << "Enter number of landscapes: ";
    int n;
    std::cin >> n;
    std::ofstream file("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);

    char t[80];
    time_t seconds = time(NULL);
    tm timeinfo;
    localtime_s(&timeinfo, &seconds);
    const char* format = "%A, %B %d, %Y %H:%M:%S";
    strftime(t, 80, format, &timeinfo);

    char buff[] = "Количестов участков: ";
    file << t << std::endl << buff << n << std::endl;
    file.close();

    for (int i = 0; i < n; ++i) {
        land.push_back(landscape());
        land[i].number = i + 1;
        std::cout << "Landscape #" << land[i].number << std::endl;
        file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
        char l[] = "Участок №";
        file << l << land[i].number << std::endl;
        file.close();
        do {
            std::cout << "Enter number of houses on this landscape: ";
            std::cin >> land[i].houses;
            if (land[i].houses <= 0) std::cout << "The number of houses must be greater than zero";
        } while (land[i].houses <= 0);
        file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
        char h[] = "Количество жилых домов: ";
        file << h << land[i].houses << std::endl;
        file.close();
        for (int j = 0; j < land[i].houses; ++j) {
            land[i].h.push_back(house());
            std::cout << "House #" << j + 1 << std::endl;
            file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
            char hn[] = "Дом №";
            file << hn << j + 1 << std::endl;
            file.close();
            do {
                std::cout << "Enter number of floors: ";
                std::cin >> land[i].h[j].floors;
                if (land[i].h[j].floors <= 0) std::cout << "The number of floors must be greater than zero";
            } while (land[i].h[j].floors <= 0);
            file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
            char f[] = "Количество этажей: ";
            file << f << land[i].h[j].floors << std::endl;
            file.close();
            std::cout << "Enter total square of this house: ";
            std::cin >> land[i].h[j].square;
            land[i].squareOfBuildings += land[i].h[j].square;
            file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
            char hs[] = "Площадь дома: ";
            file << hs << land[i].h[j].square << std::endl;
            file.close();
            std::cout << "Is there a furnace in this house? (1/0): ";
            std::cin >> land[i].h[j].furnace;
            file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
            char hf[] = "Печь: ";
            file << hf << land[i].h[j].furnace << std::endl;
            file.close();
            for (int k = 0; k < land[i].h[j].floors; ++k) {
                land[i].h[j].f.push_back(flr());
                std::cout << "Floor #" << k + 1 << std::endl;
                file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
                char fn[] = "Этаж №";
                file << fn << k + 1 << std::endl;
                file.close();
                do {
                    std::cout << "Enter height of this floor: ";
                    std::cin >> land[i].h[j].f[k].height;
                    if (land[i].h[j].f[k].height <= 0) std::cout << "Height must be greater than zero";
                } while (land[i].h[j].f[k].height <= 0);
                file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
                char fh[] = "Высота этажа: ";
                file << fh << land[i].h[j].f[k].height << std::endl;
                file.close();
                do {
                    std::cout << "Enter number of rooms on this floor: ";
                    std::cin >> land[i].h[j].f[k].rooms;
                    if (land[i].h[j].floors <= 0) std::cout << "The number of rooms must be greater than zero";
                } while (land[i].h[j].f[k].rooms <= 0);
                file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
                char fr[] = "Количество комнат на этаже: ";
                file << fr << land[i].h[j].f[k].rooms << std::endl;
                file.close();
                int r = land[i].h[j].f[k].rooms;
                do {

                    if (r > 0) {
                        std::cout << "Enter number of lounge: ";
                        std::cin >> land[i].h[j].f[k].lounge;
                        file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
                        char lounge[] = "Гостинная: ";
                        file << lounge << land[i].h[j].f[k].lounge << std::endl;
                        file.close();
                        r -= land[i].h[j].f[k].lounge;
                    }

                    if (r > 0) {
                        std::cout << "Enter number of kid's room: ";
                        std::cin >> land[i].h[j].f[k].kids;
                        file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
                        char kids[] = "Детская: ";
                        file << kids << land[i].h[j].f[k].kids << std::endl;
                        file.close();
                        r -= land[i].h[j].f[k].kids;
                    }

                    if (r > 0) {
                        std::cout << "Enter number of kitchen: ";
                        std::cin >> land[i].h[j].f[k].kitchen;
                        file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
                        char kitchen[] = "Кухня: ";
                        file << kitchen << land[i].h[j].f[k].kitchen << std::endl;
                        file.close();
                        r -= land[i].h[j].f[k].kitchen;
                    }

                    if (r > 0) {
                        std::cout << "Enter number of bedroom: ";
                        std::cin >> land[i].h[j].f[k].bedroom;
                        file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
                        char bedroom[] = "Спальня: ";
                        file << bedroom << land[i].h[j].f[k].bedroom << std::endl;
                        file.close();
                        r -= land[i].h[j].f[k].bedroom;
                    }

                    if (r > 0) std::cout << "You can accommodate " << r << " more rooms";
                } while (r > 0);
            }
        }
        std::cout << "Enter number of sauna on this landscape: ";
        std::cin >> land[i].sauna;
        file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
        char saunas[] = "Количество бань: ";
        file << saunas << land[i].sauna << std::endl;
        file.close();
        for (int j = 0; j < land[i].sauna; ++j) {
            land[i].s.push_back(sauna());
            std::cout << "Sauna #" << j + 1 << std::endl;
            file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
            char saunaNumber[] = "Баня №";
            file << saunaNumber << j + 1 << std::endl;
            file.close();
            std::cout << "Is there a furnace with tube in this sauna? (1/0): ";
            std::cin >> land[i].s[j].furnace;
            file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
            char saunaFurnace[] = "Печка в бане: ";
            file << saunaFurnace << land[i].s[j].furnace << std::endl;
            file.close();
            std::cout << "Enter total square of this sauna: ";
            std::cin >> land[i].s[j].square;
            file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
            char saunaSquare[] = "Площадь бани: ";
            file << saunaSquare << land[i].s[j].square << std::endl;
            file.close();
            land[i].squareOfBuildings += land[i].s[j].square;
        }

        std::cout << "Enter number of garage on this landscape: ";
        std::cin >> land[i].garage;
        file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
        char garages[] = "Количество гаражей: ";
        file << garages << land[i].garage << std::endl;
        file.close();
        for (int j = 0; j < land[i].garage; ++j) {
            land[i].g.push_back(garage());
            std::cout << "Garage #" << j + 1 << std::endl;
            file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
            char garageNumber[] = "Гараж №";
            file << garageNumber << j + 1 << std::endl;
            file.close();
            std::cout << "Enter total square of this garage: ";
            std::cin >> land[i].g[j].square;
            file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
            char garageSquare[] = "Площадь гаража: ";
            file << garageSquare << land[i].garage << std::endl;
            file.close();
            land[i].squareOfBuildings += land[i].g[j].square;
        }

        std::cout << "Enter number of barn on this landscape: ";
        std::cin >> land[i].barn;
        file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
        char barns[] = "Количество сараев: ";
        file << barns << land[i].barn << std::endl;
        file.close();
        for (int j = 0; j < land[i].barn; ++j) {
            land[i].b.push_back(barn());
            std::cout << "Barn #" << j + 1 << std::endl;
            file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
            char barnNumber[] = "Сарай №";
            file << barnNumber << j + 1 << std::endl;
            file.close();
            std::cout << "Enter total square of this barn: ";
            std::cin >> land[i].b[j].square;
            file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
            char barnSquare[] = "Площадь сарая: ";
            file << barnSquare << land[i].b[j].square << std::endl;
            file.close();
            land[i].squareOfBuildings += land[i].b[j].square;
        }

        totalSquareOfBuildings += land[i].squareOfBuildings;
        file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
        char landbs[] = "Общая площадь построек на участке: ";
        file << landbs << land[i].squareOfBuildings << std::endl;
        file.close();
    }

    std::cout << "Total square of all buildings: " << totalSquareOfBuildings << std::endl;
    file.open("C:\\Users\\Public\\Documents\\village.txt", std::ios::app);
    char totalSquare[] = "Общая площадь построек в поселке: ";
    file << totalSquare << totalSquareOfBuildings << std::endl;
    file.close();

    return 0;
}