#include <iostream>
#include <string.h>
using namespace std;

// Product (Shopping Website)
class Product
{
    int id;
    char *name; // Dynamic array for name
    int mrp;
    int selling_price;

public:
    Product()
    {
        cout << "Inside Constructor" << endl;
    }

    Product(int id, char *name, int mrp, int selling_price)
    {
        this->id = id;
        this->mrp = mrp;
        this->selling_price = selling_price;

        // Dynamically allocating space
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Product(Product &X)
    {
        this->id = X.id;
        this->mrp = X.mrp;
        this->selling_price = X.selling_price;

        this->name = new char[strlen(X.name) + 1];
        strcpy(this->name, X.name);
    }

    void operator=(Product &X)
    {
        cout << "Inside Copy Assignment Operator" << endl;
        this->id = X.id;
        this->mrp = X.mrp;
        this->selling_price = X.selling_price;

        // Create deep copy
        this->name = new char[strlen(X.name) + 1];
        strcpy(this->name, X.name);
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

    void setName(char *name)
    {
        strcpy(this->name, name);
    }

    void showDetails()
    {
        cout << "----------" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Selling Price: " << selling_price << endl;
        cout << "MRP: " << mrp << endl;
    }

    // Called automatically when object is destroyed
    ~Product()
    {
        cout << "Deleting " << this->name << endl;

        // Deleting Dynamic memory and preventing memory leak
        if (name != NULL)
        {
            delete[] name;
            name = NULL;
        }
    }
};

int main()
{
    Product camera1(100, "GoPro9", 2000, 3000);
    Product camera2(101, "Canon", 2200, 3900);

    // Deleted automatically

    return 0;
}
