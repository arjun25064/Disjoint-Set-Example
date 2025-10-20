#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
/*
// -----------------------------------------------------------------------------------------------------------------------------------
// DISJOINT_SET.H
// -----------------------------------------------------------------------------------------------------------------------------------
//
// ----------------------------------------------------------------------------------------------------------------------------------- 
// Author : arjun25064
// -----------------------------------------------------------------------------------------------------------------------------------
*/
template <typename T>
class DisjointSet {
    private:
        std::unordered_map<T,T> parent; // parent
        std::unordered_map<T,int>size; // size 
    public:
    // ---- constructor -----
    DisjointSet() {std::cout << "Disjoint Set initiated successfully \n";}
    
    // ---- destructor -----
    ~DisjointSet() {}
    
    // ----- makeSet -------
    // creates an element in the universe of disjoint set
    // Arguments: reference to element to be created 
    // Post calling: sets parent to itself and increments size by 1 (singleton set)
    void makeSet(T& t) {
        if (parent.find(t) != parent.end()) {
            throw std::invalid_argument("Element already exists in disjoint set !!");
            return;
        }
        parent[t]=t; // make parent of t as t
        size[t]=1; // make size of set as 1
    }


    // ----- unionSet ------
    // given two elements, join their respective sets
    // Arguments: t1,t2 are references to the two elements, whose sets, in which they are present
    // Post calling: performs a union set operation on the two sets where t1,t2 exists
    void unionSet(const T &t1 , const T &t2) {
            T root1 = find(t1);
            T root2 = find(t2);
            if (root1 == root2) {
                throw std::invalid_argument("Elements already exists in same set !!");
            }
            // attach smaller to bigger set
            if (size[root1] < size[root2]) {
                std::swap(root1,root2);
            }
            parent[root2] = root1;
            size[root1] += size[root2];
    }


    // ----- find ------
    // given reference to an element present in the disjoint set, it returns the representative of the set in which the element is present
    // Arguments: t is the reference to the element
    // Post Calling: returns the representative of the set in which the element (if exists)
    const T& find(const T& t) {
        if (parent.find(t) == parent.end()) {
            throw std::out_of_range("Element does not exist in DisjointSet.");
        }
        if (parent[t] != t)  // path compression
            parent[t] = find(parent[t]);
        return parent[t];
    }

    // ---- connected -----
    // given two elements of the set, it checks whether both are in the same set
    // Arguments: a,b are references to the two elements
    // Post Calling: returns true if a and b belong to same set, else false
    bool connected(const T& a, const T& b) {
        return find(a) == find(b);
    }   
    
    // ---- seeAllSets ----
    // prints all the sets 
    // Arguments: None
    // Post Calling: prints the representative of the set followed by the elements of the set 
    void seeAllSets() {
        std::unordered_map<T, std::vector<T>> sets;
        // group elements by their representative
        for (const auto& p : parent) {
            T root = find(p.first); // find representative
            sets[root].push_back(p.first);
        }

        // print each set
        int i=1;
        for (const auto& s : sets) {
            std::cout << "set " << i << "(root: " << s.first << ") : ";
            for (const auto& elem : s.second) {
                std::cout << elem << " - ";
            }
            std::cout << "\n";
            i++;
        }
    }

};
