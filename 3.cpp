#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Food {
protected:
    std::string name;
    int price;

public:
    Food(const std::string& foodName, int foodPrice) : name(foodName), price(foodPrice) {}

    virtual void print() const {
        std::cout << name << " costs " << price << " RON" << std::endl;
    }

    int getPrice() const {
        return price;
    }
};

class Dessert : public Food {
private:
    int calories;

public:
    Dessert(const std::string& foodName, int foodPrice, int foodCalories)
            : Food(foodName, foodPrice), calories(foodCalories) {}

    void print() const override {
        std::cout << "The dessert " << name << " has " << calories << " calories" << std::endl;
    }
};

class Pizza : public Food {
private:
    int diameter;

public:
    Pizza(const std::string& foodName, int foodPrice, int foodDiameter)
            : Food(foodName, foodPrice), diameter(foodDiameter) {}

    void print() const override {
        std::cout << "The pizza " << name << " has " << diameter << " cm" << std::endl;
    }
};

class Menu {
private:
    std::string name;
    std::vector<Food*> foodList;

public:
    Menu(const std::string& menuName) : name(menuName) {}
    void add(Food* food);
    void sort();
    void print() const;
    ~Menu();
};

void Menu::print() const {
    std::cout << name << " has the following foods:" << std::endl;
    for (const Food* food : foodList) {
        food->print();
    }
}

void Menu::sort() {
    std::sort(foodList.begin(), foodList.end(), [](const Food* a, const Food* b) {
        return a->getPrice() < b->getPrice();
    });
}

void Menu::add(Food *food) {
    foodList.push_back(food);
}

Menu::~Menu() {
    for (Food* food : foodList) {
        delete food;
    }
}

int main() {
    int price;
    std::string name;
    int numberOfItems;
    int data;

    std::cin >> name >> numberOfItems;
    Menu m{name};

    for (int i = 0; i < numberOfItems / 3; i++) {
        std::cin >> name >> price;
        m.add(new Food{name, price});

        std::cin >> name >> price >> data;
        m.add(new Dessert{name, price, data});

        std::cin >> name >> price >> data;
        m.add(new Pizza{name, price, data});
    }

    m.sort();
    m.print();

    return 0;
}
