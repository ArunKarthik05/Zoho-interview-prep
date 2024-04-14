An abstract class in C++ is a class that cannot be instantiated on its own and is used as a base class for other classes. It may contain one or more pure virtual functions, making it incomplete. Abstract classes serve as interfaces, defining a set of methods that derived classes must implement. Let's look at an example:

```cpp
#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;

    // Non-pure virtual function
    void display() {
        cout << "Displaying shape." << endl;
    }
};

// Derived class
class Circle : public Shape {
public:
    // Implementation of pure virtual function
    void draw() {
        cout << "Drawing circle." << endl;
    }
};

// Derived class
class Rectangle : public Shape {
public:
    // Implementation of pure virtual function
    void draw() {
        cout << "Drawing rectangle." << endl;
    }
};

int main() {
    // Shape shape; // Error: Cannot instantiate an abstract class

    Circle circle;
    circle.draw();
    circle.display();

    Rectangle rectangle;
    rectangle.draw();
    rectangle.display();

    return 0;
}
```

**Explanation:**
- In this example, `Shape` is an abstract class with a pure virtual function `draw()` and a non-pure virtual function `display()`.
- The `draw()` function is declared as pure virtual by appending `= 0` to its declaration. This makes `Shape` an abstract class, and any class inheriting from it must provide an implementation for `draw()`.
- Derived classes `Circle` and `Rectangle` inherit from the `Shape` class and provide implementations for the pure virtual function `draw()`.
- We cannot create objects of the abstract class `Shape`, but we can create objects of the derived classes `Circle` and `Rectangle`.

**Questions:**
1. What is an abstract class?
2. Why can't we instantiate an abstract class?
3. What is a pure virtual function?
4. How do you declare a pure virtual function in C++?
5. Can an abstract class have non-pure virtual functions?

**Answers:**
1. An abstract class in C++ is a class that cannot be instantiated on its own and contains one or more pure virtual functions. It serves as a base class for other classes and defines an interface that derived classes must implement.
2. We cannot instantiate an abstract class because it is incomplete due to the presence of pure virtual functions. Objects of abstract classes would have undefined behavior as the pure virtual functions have no implementations.
3. A pure virtual function is a virtual function with no implementation provided in the base class. It is declared with `= 0` at the end of its declaration, indicating that derived classes must provide an implementation for it.
4. To declare a pure virtual function in C++, you append `= 0` to the end of the function declaration in the base class.
5. Yes, an abstract class can have non-pure virtual functions. These functions provide a default implementation that derived classes can optionally override.   