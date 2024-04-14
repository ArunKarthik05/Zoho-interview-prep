Friend functions in C++ are non-member functions that are granted access to the private and protected members of a class. They are declared inside the class with the `friend` keyword and are defined outside the class like regular functions. Friend functions are not members of the class, but they have the same access rights as the member functions.

Let's look at an example to understand how friend functions work:

```cpp
#include <iostream>
using namespace std;

// Forward declaration of class
class MyClass;

// Friend function declaration
void display(const MyClass &obj);

// Class definition
class MyClass {
private:
    int num;

public:
    // Constructor
    MyClass(int n) : num(n) {}

    // Friend declaration
    friend void display(const MyClass &obj);
};

// Friend function definition
void display(const MyClass &obj) {
    cout << "Value of num: " << obj.num << endl;
}

int main() {
    MyClass obj(10);

    // Call friend function to access private member
    display(obj);

    return 0;
}
```

**Explanation:**
- In this example, we have a class `MyClass` with a private member `num`.
- The function `display()` is declared as a friend of the class `MyClass`. This means `display()` has access to the private members of `MyClass`.
- Inside the `main()` function, we create an object `obj` of class `MyClass` and pass it to the `display()` function. Even though `num` is private, `display()` can access it due to being a friend function.

**Questions:**
1. What is a friend function in C++?
2. How is a friend function declared inside a class?
3. What access rights does a friend function have?
4. Can a friend function access private members of a class?
5. Why would you use a friend function instead of a member function?

**Answers:**
1. A friend function in C++ is a non-member function that is granted access to the private and protected members of a class.
2. A friend function is declared inside a class with the `friend` keyword followed by the function prototype.
3. A friend function has the same access rights as the member functions of the class, allowing it to access private and protected members.
4. Yes, a friend function can access private members of a class because it is declared as a friend inside the class.
5. Friend functions are useful when you need to allow external functions to access the private members of a class without making those members public. They can enhance encapsulation by restricting access to selected functions rather than exposing all members as public.