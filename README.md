# 🔗 Disjoint Set (Union-Find) Implementation in C++

## 📘 Overview

This repository demonstrates the implementation of a **Disjoint Set (Union-Find)** data structure in C++ using **templates**, along with a real-world inspired application: **network connectivity detection between computer systems**.

The example shows how multiple systems (each represented by an IP address) can be grouped into networks, and how the disjoint set efficiently manages connectivity queries between them.

---

## 🧩 Features

- Generic **templated implementation** (`DisjointSet<T>`)
- Supports:
  - `makeSet()` — create new elements  
  - `find()` — find the representative (root) of an element’s set  
  - `unionSet()` — merge two sets  
  - `connected()` — returns true if two elements belong to the same set else false 
  - `seeAllSets()` — print all disjoint sets (connected components)
- Uses **path compression** and **union by size** for near-constant time operations.
- Real-world example with `System` class (representing computers with IP addresses).

---

## 📂 Folder Structure

📦 disjoint-set/

┣ 📜 main.cpp

┣ 📜 disjoint_set.h

┣ 📜 system.h


### File Descriptions

| File | Description |
|------|--------------|
| `disjoint_set.h` | Core implementation of the templated disjoint set data structure. |
| `system.h` | Defines the `System` class representing a computer with an IP address. Includes operator overloads for hashing, comparison, and printing. |
| `main.cpp` | Demonstrates how to use the DisjointSet with `System` objects to model computer network connectivity. |

---

## ⚙️ Example Network Topology

Network 1: sys1 --- sys2 --- sys3

Network 2: sys4 --- sys5 --- sys6


### In Code:
```cpp

ds.unionSet(sys1, sys2); // merge sys1 and sys2
ds.unionSet(sys2, sys3); // merge sys2 and sys3
// ..
ds.unionSet(sys4, sys5); // merge sys4 and sys5
ds.unionSet(sys5, sys6); // merge sys5 and sys6 
// ..
ds.connected(sys1,sys2); // returns true, if sys1 and sys2 lie in same set, else false
```
### 🖥️ Sample Output
```
Disjoint Set initiated successfully 
192.168.57.24 is connected to 10.45.103.89
172.20.7.250 is NOT connected to 101.101.7.11

set 1 (root: 10.45.103.89) : 10.45.103.89 - 172.20.7.250 - 192.168.57.24 -
set 2 (root: 11.1.9.11) : 101.101.7.11 - 11.1.9.11 - 25.110.7.11 -
```

### 🧰 Build & Run

```
g++ -std=c++17 main.cpp -o disjoint_set
```
```
./disjoint_set
```
