#include <iostream>
using namespace std;

class Vector
{
    // Data Members - private
    int *arr;         // to store the dynamic array
    int current_size; // to return size
    int max_size;     // to return capacity and perform check for growing vector

    // Constructor, Destructor, Methods - public
public:
    Vector(int ms = 1) // Constructor
    {
        current_size = 0;
        max_size = ms;
        arr = new int[max_size];
    }

    void push_back(const int data)
    {
        // If vector is full
        if (current_size == max_size)
        {
            // create new array with double the capacity and delete previous one
            int *old_arr = arr;
            max_size = 2 * max_size;

            arr = new int[max_size];

            // Copy elements
            for (int i = 0; i < current_size; i++)
                arr[i] = old_arr[i];

            delete[] old_arr;
        }

        // Insert element at the current size index and increment current size
        arr[current_size] = data;
        current_size++;
    }

    void pop_back()
    {
        if (current_size > 0)
            current_size--;
    }

    bool isEmpty() const
    {
        return (current_size == 0);
    }

    int front() const
    {
        return arr[0];
    }

    int back() const
    {
        return arr[current_size - 1];
    }

    int at(int i) const
    {
        return arr[i];
    }

    int size() const
    {
        return current_size;
    }

    int capacity() const
    {
        return max_size;
    }

    // operator overloading
    int operator[](const int i) const
    {
        return arr[i];
    }
};

int main()
{
    Vector v(5);

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    v.pop_back();

    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << " ";
    cout << endl;

    cout << v.size() << endl;
    cout << v.capacity() << endl;

    cout << v.front() << endl;
    cout << v.back() << endl;

    // Using overloaded operator
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
