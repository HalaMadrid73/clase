#include <iostream>
#include <string>

class Food {
protected:
    std::string name;
    int price;

public:
    Food(const std::string& foodName, int foodPrice) : name(foodName), price(foodPrice) {}

    virtual void print() const {
        std::cout << "The food " << name << " costs " << price << " units" << std::endl;
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

int main() {
    int price;
    std::string name;
    int data;

    std::cin >> name >> price >> data;
    Dessert a{name, price, data};

    std::cin >> name >> price >> data;
    Pizza b{name, price, data};

    Food* f;
    f = &a;
    f->print();

    f = &b;
    f->print();

    return 0;
}
