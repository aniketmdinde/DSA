#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Car
{
public:
    string id;
    int x, y;

    Car(string id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int dist() const
    {
        return x * x + y * y; // square of distance
    }
};

class CarCompare
{
public:
    bool operator()(const Car A, const Car B)
    {
        return A.dist() < B.dist(); // Max Heap
    }
};

void printNearestCars(vector<Car> cars, int k)
{
    // Create max heap of size K
    priority_queue<Car, vector<Car>, CarCompare> max_heap(cars.begin(), cars.begin() + k); // inserting K elements in heap

    // Iterate over remaining cars
    for (int i = k; i < cars.size(); i++)
    {
        Car car = cars[i];

        if (car.dist() < max_heap.top().dist())
        {
            max_heap.pop(); // remove the root node i.e. largest
            max_heap.push(car);
        }
    }

    // Print K cars
    vector<Car> output;

    while (!max_heap.empty())
    {
        output.push_back(max_heap.top());
        max_heap.pop();
    }

    // Sorting vector of K nearest cars
    reverse(output.begin(), output.end());

    cout << "Printing K Nearest Cars: ";
    for (Car c : output)
    {
        cout << c.id << " ";
    }
    cout << endl;
}

int main()
{
    int N, K;
    cin >> N >> K;

    string id;
    int x, y;

    vector<Car> cars;

    for (int i = 0; i < N; i++)
    {
        cin >> id >> x >> y;

        Car car(id, x, y);

        cars.push_back(car);
    }

    printNearestCars(cars, K);

    return 0;
}

// C1 1 1
// C2 2 1
// C3 3 2
// C4 0 1
// C5 2 3