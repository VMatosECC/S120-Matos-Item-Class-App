#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Item
{
private:
    //Data members
    string  id;
    string  name;
    double  price;
    string* supplier;

    static int    counter;

public:
    //Mutators  (accept and validate user supplied data)
    void setId(string idValue) {
        //TODO - Validate, first char must be a letter
        id = idValue;
    }

    void setName(string nameValue)
    {
        //TODO - change nameValue to title-caps format
        name = nameValue;
    }

    void setPrice(double priceValue)
    {
        //Price is positive
        price = abs(priceValue);
    }

    void setSupplier(string supplierValue) {
        *supplier = supplierValue;
    }

    //Accessors
    string getId()       { return id; }
    string getName()     { return name; }
    double getPrice()    { return price; }
    string getSupplier() { return *supplier; }

    static int getCounter() { return counter; }

    //Constructors
    ////Zero-Arguments Constructor
    //Item()
    //{
    //    setId("N.A.");
    //    setName("N.A");
    //    setPrice(0);

    //    supplier = new string();
    //    *supplier = "N.A.";

    //    counter++;
    //}

    //All-Arguments constructor
    Item(string idValue = "X0000", string nameValue = "NA", 
         double priceValue = 0, string supplierValue = "NA")
    {
        setId(idValue);
        setName(nameValue);
        setPrice(priceValue);

        supplier = new string();
        *supplier = supplierValue;

        counter++;
    }

    ////Copy-Constructor Version1
    //Item(Item& sourceItem)
    //{
    //    setId(sourceItem.getId());
    //    setName(sourceItem.getName());
    //    setPrice(sourceItem.getPrice());

    //    this->supplier = new string();
    //    //*supplier = sourceItem.getSupplier();
    //    *supplier = *sourceItem.supplier;
    //    counter++;
    //}
    // 
    
    //Copy-Constructor Version2
    Item(Item& sourceItem)
    {
        *this = sourceItem;
        counter++;
    }





    //-----------------------------------------------
    ~Item() 
    {
        cout << "+++ " << toString() << endl;
        cout << "+++ " << supplier << " " << *supplier << endl;
        delete this->supplier;
    }

    //User-Defined Methods
    string toString()
    {
        stringstream sout;
        sout << this << " Item [ ID: " << getId()
            << ", Name: " << getName()
            << ", Price: " << getPrice()
            << ", Supplier: " << getSupplier()
            << "]";
        return sout.str();
    }

    //Overloaded Operators
    void operator= (const Item& other)
    {
        setId(other.id);
        setName(other.name);
        setPrice(other.price);
        this->supplier = new string();
        *supplier = *other.supplier;

    }

    friend void showData(Item& i) {
        cout << " FRIEND==> " << i.id << ", " << i.getName() << ", "
            << i.getPrice() << ", " << i.getSupplier() << endl;
    }

    friend istream& operator>> (istream& sin, Item& i) {
        string s;
        cout << "Enter ID:       ";
        sin >> i.id;

        sin.ignore();
        cout << "Enter Name:     ";
        getline(sin, i.name);

        cout << "Enter Price:    ";
        sin >> i.price;

        sin.ignore();
        cout << "Enter Supplier: ";
        getline(sin, s);
        i.setSupplier(s);
        return sin;
    }
};

//Initialize static variable(s)
int Item::counter = 0;

