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
    Product()
    {
        cout << "Inside Constructor" << endl;
    }

    Product(int id, char *name, int mrp, int selling_price)
    {
        this->id = id;
        strcpy(this->name, name); // copy contents
        this->mrp = mrp;
        this->selling_price = selling_price;
    }

    // Copy Constructor
    Product(Product &X)
    {
        // Copying Values
        this->id = X.id;
        strcpy(this->name, X.name);
        this->mrp = X.mrp;
        this->selling_price = X.selling_price;
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

    // Prints details
    void showDetails()
    {
        cout << "----------" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Selling Price: " << selling_price << endl;
        cout << "MRP: " << mrp << endl;
    }
};

int main()
{
    Product camera1(100, "GoPro", 2000, 3000);

    // The values of camera1 are copied into camera2
    // Using Special Constructor - Copy Constructor
    Product camera2(camera1);

    // Another way of calling copy constructor
    Product camera3 = camera1;

    camera1.showDetails();
    camera2.showDetails();
    camera3.showDetails();

    return 0;
}
