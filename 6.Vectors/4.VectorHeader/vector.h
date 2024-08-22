template <typename T> // defining a template
                      // It tells that all the data types will be of type T in the following class or function
                      // The data type will be provided by the place which uses this class
class Vector
{
    // Data Members - private
    T *arr;           // to store the dynamic array
    int current_size; // to return size
    int max_size;     // to return capacity and perform check for growing vector

    // Constructor, Destructor, Methods - public
public:
    Vector(int ms = 1) // Constructor
    {
        current_size = 0;
        max_size = ms;
        arr = new T[max_size];
    }

    void push_back(const T data)
    {
        // If vector is full
        if (current_size == max_size)
        {
            // create new array with double the capacity and delete previous one
            T *old_arr = arr;
            max_size = 2 * max_size;

            arr = new T[max_size];

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

    T front() const
    {
        return arr[0];
    }

    T back() const
    {
        return arr[current_size - 1];
    }

    T at(int i) const
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
    T operator[](const int i) const
    {
        return arr[i];
    }
};
