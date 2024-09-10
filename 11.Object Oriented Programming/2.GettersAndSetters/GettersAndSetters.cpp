#include <iostream>
using namespace std;

// Product (Shopping Website)
class Product
{
    int id;
    char name[100];
    // Restrict access - private
    int mrp;
    int selling_price;

public:
    // Setters - used to set properties
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

    // Getters - used to get those set properties since private
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
    Product camera;
    camera.setMrp(100);
    camera.setSellingPrice(200);
    cout << "----- Camera -----" << endl;
    cout << "MRP: " << camera.getMrp() << endl;
    cout << "Selling Price: " << camera.getSellingPrice() << endl;

    cout << endl;

    Product lens;
    lens.setMrp(200);
    lens.setSellingPrice(100);
    cout << "----- Lens -----" << endl;
    cout << "MRP: " << lens.getMrp() << endl;
    cout << "Selling Price: " << lens.getSellingPrice() << endl;

    return 0;
}
