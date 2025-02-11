### **Why Do We Need a `main` Method in Java?**  
The `main` method serves as the **entry point** of a Java application. When you execute a Java program, the **JVM searches for the `main` method** and starts execution from there.  

---

## **1. Why is the `main` Method Required?**
1. **Standard Entry Point**: JVM needs a fixed starting method to begin execution.
2. **Avoids Ambiguity**: Having a standard method ensures a consistent execution flow.
3. **Static Context**: It can be called without creating an object of the class.

---

## **2. Syntax of `main` Method**
```java
public class Main {
    public static void main(String[] args) {
        System.out.println("Hello, Java!");
    }
}
```
### **Explanation of Each Keyword**
| Keyword        | Purpose |
|---------------|---------|
| `public`      | JVM needs to access it from outside the class. |
| `static`      | Allows JVM to call it without creating an object. |
| `void`        | Does not return any value. |
| `main`        | Standard method name recognized by JVM. |
| `String[] args` | Used for command-line arguments. |

---

## **3. Internal Working of `main` Method**
### **Step-by-Step Execution in JVM**
1. **Class Loading** (`ClassLoader` loads `Main.class` into memory).
2. **Memory Allocation** (`Method Area` stores class methods, including `main`).
3. **JVM Calls `main` Method** using the **Execution Engine**.
4. **Program Execution Begins** (Runs `main` method line by line).
5. **Program Terminates** (JVM shuts down after execution is complete).

---

## **4. What Happens If We Omit `main` Method?**
- **Compilation succeeds**, but execution fails.
- JVM throws a **`NoSuchMethodError`**.

### **Example**
```java
public class Test {
    // No main method
}
```
**Execution Output:**
```sh
Error: Main method not found in class Test
```

---

## **5. Alternative Forms of `main`**
The following variations are **valid** since JVM only looks for **`public static void main(String[] args)`**:
```java
public static void main(String args[]) { }  // Valid
public static void main(String... args) { } // Valid (Varargs)
```
But **invalid forms** will not work:
```java
static void main(String[] args) { }  // Invalid (not public)
public void main(String[] args) { }  // Invalid (not static)
```

---

## **6. Why Is `main` Static?**
✅ **Avoids Object Creation**: Calling `main` without `static` requires an object, causing recursion.  
✅ **Saves Memory**: No need to allocate an object in heap memory.  
✅ **JVM Independence**: `main` can be called without knowing the class instance.

---

## **7. Key Takeaways**
✅ The `main` method is the **entry point** of execution.  
✅ It must be **public, static, void**, and take a `String[] args` parameter.  
✅ JVM **calls the `main` method** after class loading.  
✅ Without `main`, JVM throws a **`NoSuchMethodError`**.  

Would you like to see how JVM **calls `main` internally** in bytecode?
