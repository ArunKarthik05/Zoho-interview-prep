### **Static Binding vs Dynamic Binding in Java**  

**Binding** refers to the process of connecting a **method call** to its **method definition**. This occurs during either **compile-time (static binding)** or **runtime (dynamic binding)**.

---

## **1. Static Binding (Early Binding)**
### **Definition**
- **Method call is resolved at compile-time.**
- Uses **method overloading** (same method name, different parameters).
- Uses **final, static, or private** methods.
- Faster execution since the method is known **before runtime**.

### **Example (Method Overloading)**
```java
class MathUtil {
    static int add(int a, int b) {  // Overloaded method 1
        return a + b;
    }

    static double add(double a, double b) {  // Overloaded method 2
        return a + b;
    }

    public static void main(String[] args) {
        System.out.println(MathUtil.add(5, 10));      // Calls int version
        System.out.println(MathUtil.add(5.5, 10.5));  // Calls double version
    }
}
```
### **How it Works Internally?**
1. **Compiler checks method signatures** (`add(int, int)` and `add(double, double)`).
2. It **binds the method call** (`add(5,10) → `add(int, int)`) at compile-time.
3. **No runtime decision needed**.

### **Static Binding in Final/Static Methods**
```java
class Parent {
    static void show() {  // Static method
        System.out.println("Parent class");
    }
}

class Child extends Parent {
    static void show() {  // Static method (Hides Parent's show())
        System.out.println("Child class");
    }
}

public class Main {
    public static void main(String[] args) {
        Parent obj = new Child();
        obj.show();  // Output: Parent class (Static binding)
    }
}
```
- Since `show()` is **static**, method resolution happens at **compile-time**.
- `obj.show();` **binds to Parent's show()**, not Child’s.

---

## **2. Dynamic Binding (Late Binding)**
### **Definition**
- **Method call is resolved at runtime.**
- Used in **method overriding**.
- Uses **polymorphism** (Base class reference, Child class object).
- Slower execution than static binding (involves **virtual method table (VMT)** lookup).

### **Example (Method Overriding)**
```java
class Animal {
    void sound() {  // Overridden method
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal {
    @Override
    void sound() {
        System.out.println("Dog barks");
    }
}

public class Main {
    public static void main(String[] args) {
        Animal a = new Dog();  // Parent reference, Child object
        a.sound();  // Output: Dog barks (Dynamic binding)
    }
}
```
### **How it Works Internally?**
1. At **compile-time**, `a.sound()` is linked to `Animal` class.
2. At **runtime**, JVM checks the actual object (`Dog`).
3. Uses **VMT (Virtual Method Table)** to dynamically bind `sound()` to `Dog`.

---

## **3. Static vs Dynamic Binding (Comparison Table)**

| Feature            | Static Binding (Early Binding) | Dynamic Binding (Late Binding) |
|--------------------|--------------------------------|---------------------------------|
| **Resolved at**    | Compile-time                  | Runtime                        |
| **Used in**        | Method Overloading, Static Methods | Method Overriding             |
| **Performance**    | Faster                        | Slower (Runtime lookup)        |
| **Keywords Used**  | `static`, `final`, `private`  | `override` (Polymorphism)      |
| **Example Methods** | Static methods, Final methods | Overridden methods             |

---

## **4. Key Takeaways**
✅ **Static binding** is used for **method overloading, static, final, and private methods**.  
✅ **Dynamic binding** is used for **method overriding and polymorphism**.  
✅ **Performance:** Static binding is **faster** than dynamic binding.  
✅ JVM resolves **dynamic binding using Virtual Method Table (VMT)** at runtime.  

Would you like an in-depth explanation of **VMT (Virtual Method Table) in JVM**?
