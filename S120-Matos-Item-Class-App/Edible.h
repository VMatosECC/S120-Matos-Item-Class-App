#pragma once
#include <exception>
#include "Item.h"
class Edible : public Item
{
private:
    ////Data Members
    int     calories;
    string* description;
    
    static int count;

public:
    //Mutators
    void setCalories(int calories) {
        if (calories >= 5000) throw runtime_error("Too many calories!!!");
        this->calories = calories;
    }

    void setDescription(string description) {
        *(this->description) = description;
    }
    //Accessors
    int getCalories()  const { return calories; }
    string getDescription() const { return *description; }

    //Constructors
    Edible(string id, string name, double price, string supplier,
        int calories = 0, string description = "None")
        : Item(id, name, price, supplier)
    {
        setCalories(calories);

        this->description = new string();
        setDescription(description);

        count++;
    }

    //Copy Constructor
    Edible(const Edible& other) {
        *this = other;
    }

    //Destructor
    ~Edible() {
        cout << "+++ Edible destructor " << getName() << endl;
        delete description;
    }
     
    //User-defined methods

    //Overloaded Operators
    void operator= (const Edible& other) {
        setCalories(other.getCalories());
        this->description = new string;
        *description = *(other.description);
    }

};
//----------------------------------------------
int Edible::count = 0;
