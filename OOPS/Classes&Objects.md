### Concept Explanation

In C++, a class is a blueprint for creating objects. It defines the attributes (data members) and behaviors (member functions) that the objects of the class will have. An object is an instance of a class, meaning it is a specific realization of that class with its own set of data members and behaviors.

Here's a simple example to illustrate the concept:

```cpp
#include <iostream>
using namespace std;

// Define a class named 'Car'
class Car {
    // Data members
    string brand;
    string model;
    int year;

public:
    // Constructor
    Car(string brand, string model, int year) {
        this->brand = brand;
        this->model = model;
        this->year = year;
    }

    // Member function to display car information
    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    // Create an object of class 'Car'
    Car myCar("Toyota", "Camry", 2020);

    // Call member function to display car information
    myCar.displayInfo();

    return 0;
}
```
In this code, we define a class named `Car`. Inside the class, we have data members `brand`, `model`, and `year`, representing attributes of a car. We also have a constructor `Car` which initializes the data members when an object is created. The member function `displayInfo()` displays the details of the car. In the `main()` function, we create an object `myCar` of class `Car` and initialize it with values "Toyota", "Camry", and 2020. Finally, we call the `displayInfo()` function on the `myCar` object to print its details.

### Questions

1. What is a class in C++?
2. What is an object in C++?
3. What is the purpose of a constructor in a class?
4. How do you access the data members and member functions of a class?
5. Can you have multiple objects of the same class? If yes, how do they differ?

### Answers

1. A class in C++ is a blueprint for creating objects. It defines the structure and behavior of objects.
2. An object in C++ is an instance of a class. It represents a specific realization of that class with its own set of data members and member functions.
3. The purpose of a constructor in a class is to initialize the data members of objects when they are created. It ensures that objects start with valid initial values.
4. Data members and member functions of a class can be accessed using the member access operator `.` (dot) with the object name.
5. Yes, you can have multiple objects of the same class. Each object has its own set of data members, meaning they can have different values. However, they share the same member functions defined in the class.
