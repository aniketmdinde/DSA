#include <iostream>
using namespace std;

// Product (Shopping Website)
class Product
{
    int id;         // 4 bytes
    char name[100]; // 100 bytes

public:
    int mrp;           // 4 bytes
    int selling_price; // 4 bytes
};

int main()
{
    Product camera; // object
    // cout << sizeof(camera) << endl;

    camera.mrp = 100;
    camera.selling_price = 500;
    cout << "MRP: " << camera.mrp << endl;
    cout << "Selling Price: " << camera.selling_price << endl;

    return 0;
}
