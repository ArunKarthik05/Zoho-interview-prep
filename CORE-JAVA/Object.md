### **`Object` Class in Java – The Root of All Classes**

In Java, the `Object` class is the **parent class of all classes**. If a class does not explicitly extend another class, it **implicitly extends `Object`**.

```java
class MyClass {  // Implicitly extends Object
    // Class body
}
```

---

## **1. Key Features of the `Object` Class**

- **Root class** → Every class in Java **inherits** from `Object` (directly or indirectly).
- **Universal methods** → Provides essential methods like `equals()`, `hashCode()`, `toString()`, etc.
- **Supports runtime polymorphism** → Since every object is an `Object`, it enables **generic programming**.
- **Used for synchronization** → The `wait()`, `notify()`, and `notifyAll()` methods are crucial for multithreading.

---

## **2. Important Methods of the `Object` Class**

### **a) `equals(Object obj)`**

- Compares two objects for **logical equality**.
- Default implementation in `Object` checks **reference equality** (`==`).

```java
class Person {
    String name;
    
    Person(String name) {
        this.name = name;
    }
}

public class EqualsExample {
    public static void main(String[] args) {
        Person p1 = new Person("Alice");
        Person p2 = new Person("Alice");

        System.out.println(p1.equals(p2));  // false (default: checks references)
        System.out.println(p1 == p2);       // false
    }
}
```

To compare based on content, override `equals()`:

```java
@Override
public boolean equals(Object obj) {
    if (this == obj) return true;
    if (obj == null || getClass() != obj.getClass()) return false;
    Person person = (Person) obj;
    return name.equals(person.name);
}
```

---

### **b) `hashCode()`**

- Generates a **hash value** for an object.
- Used in **hash-based collections** (`HashMap`, `HashSet`).
- **Contract**: If `equals()` returns `true`, `hashCode()` must be the same.

Example:

```java
@Override
public int hashCode() {
    return name.hashCode();
}
```

---

### **c) `toString()`**

- Returns a **string representation** of an object.
- Default implementation:
    
    ```java
    getClass().getName() + "@" + Integer.toHexString(hashCode())
    ```
    
- Override it to provide meaningful output.

```java
@Override
public String toString() {
    return "Person{name='" + name + "'}";
}
```

Example usage:

```java
Person p = new Person("Alice");
System.out.println(p);  // Output: Person{name='Alice'}
```

---

### **d) `clone()`**

- Creates a **shallow copy** of an object.
- Must **implement `Cloneable`** to avoid `CloneNotSupportedException`.

```java
class Person implements Cloneable {
    String name;

    Person(String name) {
        this.name = name;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}
```

---

### **e) `finalize()` (Deprecated)**

- Called **before garbage collection**.
- Used for cleanup but **not recommended**.

```java
@Override
protected void finalize() throws Throwable {
    System.out.println("Object is being garbage collected");
}
```

---

### **f) `wait()`, `notify()`, `notifyAll()`**

- Used for **thread synchronization**.
- Must be called inside a `synchronized` block.

Example:

```java
synchronized (obj) {
    obj.wait();   // Waits for notification
}

synchronized (obj) {
    obj.notify(); // Wakes up one waiting thread
}
```

---

## **3. Summary of Important Methods**

|Method|Purpose|
|---|---|
|`equals(Object)`|Checks if two objects are logically equal|
|`hashCode()`|Returns a hash value for the object|
|`toString()`|Provides a string representation of the object|
|`clone()`|Creates a shallow copy of an object|
|`finalize()`|Called before garbage collection (deprecated)|
|`wait()`, `notify()`, `notifyAll()`|Thread synchronization methods|
