#include <iostream>
#include <string>

class Food {
public:
    std::string name;
    int price;

    Food(const std::string& name, int price) : name(name), price(price) {}

    void print() const {
        std::cout << name << " costs " << price << " RON" << std::endl;
    }

    bool operator<(const Food& other) const {
        return price < other.price;
    }
};
