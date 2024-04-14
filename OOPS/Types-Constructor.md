1. Default Constructor
2. Parameterized Constructor
3. Copy Constructor

Let's explore each type with sample code:

**1. Default Constructor:**
A default constructor is a constructor with no parameters. If you don't define any constructor for a class, the compiler automatically generates a default constructor.

```cpp
#include <iostream>
using namespace std;

// Define a class with a default constructor
class MyClass {
public:
    // Default constructor
    MyClass() {
        cout << "Default constructor called." << endl;
    }
};

int main() {
    // Create an object of class MyClass
    MyClass obj;

    return 0;
}
```

**2. Parameterized Constructor:**
A parameterized constructor is a constructor with parameters. It allows you to initialize the object's data members with specific values at the time of object creation.

```cpp
#include <iostream>
using namespace std;

// Define a class with a parameterized constructor
class Car {
    string brand;
    string model;
    int year;

public:
    // Parameterized constructor
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
        cout << "Parameterized constructor called." << endl;
    }

    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    // Create an object of class Car with parameters
    Car myCar("Toyota", "Camry", 2020);

    // Call member function to display car information
    myCar.displayInfo();

    return 0;
}
```

**3. Copy Constructor:**
A copy constructor is a constructor that initializes an object using another object of the same class. It is used to create a copy of an existing object.

```cpp
#include <iostream>
using namespace std;

// Define a class with a copy constructor
class Person {
    string name;
    int age;

public:
    // Parameterized constructor
    Person(string n, int a) {
        name = n;
        age = a;
        cout << "Parameterized constructor called." << endl;
    }

    // Copy constructor
    Person(const Person &p) {
        name = p.name;
        age = p.age;
        cout << "Copy constructor called." << endl;
    }

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    // Create an object of class Person
    Person person1("John", 30);

    // Create another object and initialize it using the copy constructor
    Person person2 = person1;

    // Call member function to display person information
    person2.displayInfo();

    return 0;
}
```

**Note:** 
- In the copy constructor, the parameter is passed as a reference to const to prevent modifications to the original object.
- Copy constructors are invoked when an object is passed by value, returned by value, or initialized with another object of the same class.