### **How HashMap Works Internally in Java**

#### **1. Overview**

A `HashMap<K, V>` in Java is a key-value pair data structure that uses **hashing** to store and retrieve values efficiently. It is part of the `java.util` package and allows `null` keys and multiple `null` values. It does **not** maintain any order of elements.

---

## **2. Classes and Interfaces Implemented by HashMap**

`HashMap<K, V>` extends and implements the following:

- **`AbstractMap<K, V>`** → Provides a skeletal implementation of the `Map` interface.
- **`Map<K, V>`** → The fundamental interface defining key-value mapping.
- **`Cloneable`** → Allows the map to be cloned.
- **`Serializable`** → Allows the map to be serialized for transmission/storage.

---

## **3. Internal Structure of HashMap**

### **a) Buckets and Hashing**

Internally, `HashMap` uses an **array of `Node<K, V>` objects**, where:

```java
static class Node<K,V> implements Map.Entry<K,V> {
    final int hash;
    final K key;
    V value;
    Node<K,V> next;
}
```

- Each bucket (array index) stores a **linked list** of nodes (key-value pairs).
- The bucket index is determined using **hashing**:
    
    ```java
    index = (hashCode of key) & (capacity - 1)
    ```
    
    This ensures keys are placed efficiently across buckets.

---

### **b) Steps in `put(K key, V value)` Method**

1. **Compute the hash** of the key using `hashCode()`.
2. **Find the bucket index** using `(hash & (capacity - 1))`.
3. **Insert a new `Node<K, V>`** if no collision occurs.
4. **Handle collision** using a **linked list** or **red-black tree** (if entries exceed 8 in a bucket).
5. **Resize the HashMap** when **load factor (default 0.75)** is exceeded.

---

### **c) Steps in `get(K key)` Method**

6. Compute the **hash** of the key.
7. Locate the **bucket index**.
8. Traverse the **linked list** (or red-black tree) in that bucket.
9. Return the value if the key matches, otherwise return `null`.

---

## **4. Performance and Load Factor**

- **Best case (O(1))** → When keys are evenly distributed, accessing an element is nearly constant time.
- **Worst case (O(n))** → When all elements fall into the same bucket (poor hash function), traversal becomes `O(n)`.
- **Load factor** (`0.75` default) → When `size >= capacity * load factor`, the HashMap **doubles** its capacity.

---

## **5. Usage Examples**

```java
import java.util.*;

public class HashMapExample {
    public static void main(String[] args) {
        HashMap<Integer, String> map = new HashMap<>();

        // Insert values
        map.put(1, "Apple");
        map.put(2, "Banana");
        map.put(3, "Cherry");

        // Retrieve a value
        System.out.println(map.get(2)); // Output: Banana

        // Iterate over key-value pairs
        for (Map.Entry<Integer, String> entry : map.entrySet()) {
            System.out.println(entry.getKey() + " => " + entry.getValue());
        }
    }
}
```

---

## **6. Summary**

- **Implements:** `Map<K, V>`, `Cloneable`, `Serializable`.
- Uses **hashing** for O(1) average-time access.
- Handles **collisions** using **linked lists** (converts to red-black tree for efficiency).
- **Auto-resizes** when `size >= capacity * load factor (0.75)`.
