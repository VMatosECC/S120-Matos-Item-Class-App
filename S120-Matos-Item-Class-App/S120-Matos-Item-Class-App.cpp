// S120-Matos-Item-Class-App.cpp

#include <iostream>
#include "Item.h"
#include "Edible.h"

void experiment01();
void experiment02();
void experiment03();

int main()
{
    //experiment01();
    //experiment02();
    experiment03();

    cout << "All done!\n";
}
//-------------------------------------------------------------
void experiment03() {
 
    try
    {
        Edible e1("E1234", "Romaine Salad", 3.50, "Green Hills",
            800, "Organic Lettuce and Khale");

        cout << "e1 " << e1.getName() << endl;
    }
    catch (const std::exception& e)
    {
        cout << "ERROR - Edible object not made - " << e.what() << endl;
    }
 
}

//-------------------------------------------------------------
void experiment02() {
    Item i1("T0001", "Barbie Doll", 20.00, "Mattel");
    cout << "i1 " << i1.toString() << endl;

    showData(i1);

    Item i2;
    cin >> i2;

    cout << "\nEnter data to make an Item\n";
    cout << "i2 " << i2.toString() << endl;


}

//--------------------------------------------------
void experiment01() {

}