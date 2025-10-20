/*
************ This is an example application to show the usefulness of disjoint set ******************
*/

#include "disjoint_set.h"
#include "system.h"
#include <string>
#include <iostream>
#include <vector>

int main() {
    // creating a system with the following topology
    /*
    
                    sys1 -------------- sys3
                 /                          
                /
               /
            sys2

                            sys4 ----------- sys5 ----------- sys6

    
    */

    // Idea is:
    // 1. Create systems with IP addresses
    // 2. Create a disjoint set with the above system instances as elements (using .makeSet method)
    // 3. Join systems using union (using .unionSet method)
    // 4. Find if two systems are connected to each other (using .connected method)
    // 5. Prints all connected networks

    System sys1("192.168.57.24"); 
    System sys2("10.45.103.89");
    System sys3("172.20.7.250");
    System sys4("25.110.7.11");
    System sys5("11.1.9.11");
    System sys6("101.101.7.11");
    

    
    try {
        DisjointSet<System> ds; // disjoint set object
        
        ds.makeSet(sys1);
        ds.makeSet(sys2);
        ds.makeSet(sys3);
        ds.makeSet(sys4);
        ds.makeSet(sys5);
        ds.makeSet(sys6);

        ds.unionSet(sys1,sys2);
        ds.unionSet(sys2,sys3);

        ds.unionSet(sys4,sys5);
        ds.unionSet(sys5,sys6);
        

        std :: vector<
                std :: pair<System,System>
                > checkConnections = {
            {sys1,sys2} , {sys3,sys6}
        }; // pair of systems to be checked if they are connected or not (indirectly or directly)

        // iterate and check each pair of systems if they are connected or not
        for (auto pr : checkConnections) {
            if (ds.connected(pr.first , pr.second)) {
                std :: cout << pr.first << " is connected to " << pr.second << std :: endl; 
            } else {
                std :: cout << pr.first << " is NOT connected to " << pr.second << std :: endl;
            }
        }

        ds.seeAllSets(); // print all systems in a connected network

    } catch (const std :: invalid_argument &e) {
        std :: cerr << "ERROR : " << e.what() << std :: endl;
    } catch (const std :: out_of_range &e) {
        std :: cerr << "ERROR : " << e.what() << std :: endl;
    }
    return 0;
} 