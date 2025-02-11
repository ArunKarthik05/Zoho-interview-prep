### **Types of Methods in Java and Their Internal Working**

Methods in Java are categorized based on their **definition, behavior, and scope**. Each type of method has specific **usages and internal workings**.

---

## **1. Classification of Methods in Java**

1. **Based on Definition**
    - **Instance Methods** (Non-static methods)
    - **Static Methods**
2. **Based on Functionality**
    - **Concrete Methods**
    - **Abstract Methods**
    - **Final Methods**
    - **Synchronized Methods**
    - **Native Methods**
3. **Special Methods**
    - **Constructor Methods**
    - **Getter and Setter Methods**
    - **Main Method**
    - **Factory Methods**

---

## **2. Instance Methods (Non-static Methods)**

### **Definition**

- Declared **without** `static` keyword.
- Requires an **object** to be invoked.
- Has access to **instance variables and methods**.

### **Usage**

Used when behavior depends on **object state**.

### **Example**

```java
class Car {
    String model;

    void setModel(String model) {  // Instance method
        this.model = model;
    }

    void display() {
        System.out.println("Car model: " + model);
    }
}

public class Main {
    public static void main(String[] args) {
        Car car = new Car();
        car.setModel("Tesla");
        car.display();  // Output: Car model: Tesla
    }
}
```

### **Internal Working**

- When an instance method is called, `this` points to the **current object**.
- JVM **resolves** the method call dynamically at runtime (**dynamic method dispatch**).

---

## **3. Static Methods**

### **Definition**

- Declared with `static` keyword.
- **Belongs to the class** rather than an object.
- Cannot access **instance variables** directly.

### **Usage**

Used for **utility functions** or when behavior is **not tied to object state**.

### **Example**

```java
class MathUtil {
    static int square(int x) {  // Static method
        return x * x;
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println(MathUtil.square(5));  // Output: 25
    }
}
```

### **Internal Working**

- **Resolved at compile-time** using **static binding**.
- **No `this` reference** because it belongs to the class.

---

## **4. Concrete Methods**

### **Definition**

- A regular method with **full implementation**.

### **Usage**

Used in **normal classes and abstract classes**.

### **Example**

```java
abstract class Vehicle {
    void start() {  // Concrete method
        System.out.println("Vehicle is starting");
    }
}
```

---

## **5. Abstract Methods**

### **Definition**

- Declared **without implementation** in an abstract class.
- Must be **overridden** in child classes.

### **Usage**

Used to enforce **method implementation** in subclasses.

### **Example**

```java
abstract class Animal {
    abstract void makeSound();  // Abstract method
}

class Dog extends Animal {
    void makeSound() {
        System.out.println("Bark");
    }
}
```

### **Internal Working**

- **Cannot be instantiated directly**.
- **Method resolution happens at runtime**.

---

## **6. Final Methods**

### **Definition**

- Declared with `final` keyword.
- **Cannot be overridden** in subclasses.

### **Usage**

Used to **prevent method modification** in inheritance.

### **Example**

```java
class Parent {
    final void show() {
        System.out.println("Final method in Parent");
    }
}

class Child extends Parent {
    // Cannot override show() method
}
```

### **Internal Working**

- **JVM applies inline optimization** to `final` methods for better performance.

---

## **7. Synchronized Methods**

### **Definition**

- Declared with `synchronized` keyword.
- Allows **one thread at a time** to execute the method.

### **Usage**

Used in **multithreading** to prevent **race conditions**.

### **Example**

```java
class Counter {
    private int count = 0;

    synchronized void increment() {  // Synchronized method
        count++;
    }
}
```

### **Internal Working**

- JVM **acquires a lock (monitor)** before executing the method.
- Only one thread **can execute at a time**.

---

## **8. Native Methods**

### **Definition**

- Declared with `native` keyword.
- Implemented in **C/C++ (JNI - Java Native Interface)**.

### **Usage**

Used for **system-level operations**.

### **Example**

```java
class NativeExample {
    native void nativeMethod();  // Implemented in C/C++
}
```

### **Internal Working**

- JVM **loads native libraries** (`.so` or `.dll`).
- Calls the **underlying OS functions**.

---

## **9. Constructor Methods**

### **Definition**

- A special method **with the same name as the class**.
- Called automatically when an **object is created**.

### **Usage**

Used for **object initialization**.

### **Example**

```java
class Student {
    String name;

    Student(String name) {  // Constructor
        this.name = name;
    }
}
```

### **Internal Working**

- JVM **allocates memory** before calling the constructor.
- Calls **default or parameterized constructor**.

---

## **10. Getter and Setter Methods**

### **Definition**

- **Getter** → Retrieves private fields.
- **Setter** → Modifies private fields.

### **Usage**

Used for **encapsulation**.

### **Example**

```java
class Person {
    private String name;

    void setName(String name) { this.name = name; }
    String getName() { return name; }
}
```

---

## **11. Main Method**

### **Definition**

- The **entry point** of a Java program.
- Defined as:
    
    ```java
    public static void main(String[] args)
    ```
    

### **Internal Working**

- JVM **calls `main()` first**.
- `args` stores **command-line arguments**.

---

## **12. Factory Methods**

### **Definition**

- Returns an **instance of a class** instead of creating it manually.

### **Usage**

Used in **design patterns** (e.g., Singleton, Factory Pattern).

### **Example**

```java
class Logger {
    private static Logger instance = new Logger();

    private Logger() {}  // Private constructor

    static Logger getInstance() {  // Factory method
        return instance;
    }
}
```

---

## **Summary Table**

|Type|Description|Static?|Overridable?|
|---|---|---|---|
|**Instance Method**|Requires object|No|Yes|
|**Static Method**|Belongs to class|Yes|No|
|**Concrete Method**|Regular method|No|Yes|
|**Abstract Method**|Declared without body|No|Yes (mandatory)|
|**Final Method**|Cannot be overridden|No|No|
|**Synchronized Method**|Thread-safe execution|No|Yes|
|**Native Method**|Implemented in C/C++|No|Yes|
|**Constructor**|Initializes object|No|No|
|**Getter/Setter**|Encapsulation|No|Yes|
|**Main Method**|Program entry point|Yes|No|
|**Factory Method**|Returns an object|Yes|No|

---

## **Conclusion**

Java provides different types of methods for various **functionalities** like **inheritance, polymorphism, multithreading, and encapsulation**. JVM optimizes method calls using **static/dynamic binding**, **synchronization**, and **native code execution**.

Would you like more details on any specific method type?
