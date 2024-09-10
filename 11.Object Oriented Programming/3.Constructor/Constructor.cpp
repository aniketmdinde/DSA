#include <iostream>
#include <string.h>
using namespace std;

// Product (Shopping Website)
class Product
{
    int id;
    char name[100];
    int mrp;
    int selling_price;

public:
    // Constructor
    Product() // Called automatically when object created
    {
        cout << "Inside Constructor" << endl;
    }

    // Parameterized Constructor - Constructor overloading
    Product(int id, char *name, int mrp, int selling_price)
    {
        this->id = id;
        strcpy(this->name, name); // copy contents
        this->mrp = mrp;
        this->selling_price = selling_price;
    }

    void setMrp(int price)
    {
        mrp = price;
    }

    void setSellingPrice(int price)
    {
        if (price > mrp)
            selling_price = price;
        else
            selling_price = mrp;
    }

    int getMrp()
    {
        return mrp;
    }

    int getSellingPrice()
    {
        return selling_price;
    }
};

int main()
{
    Product camera; // constructor called automatically
    Product phone(101, "sony 12", 28000, 26000);

    cout << phone.getMrp() << endl;
    cout << phone.getSellingPrice() << endl;

    return 0;
}
