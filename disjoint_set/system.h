#pragma once
/*
************ This is an example application to show the usefulness of disjoint set ******************
*/

#include <string>
#include <functional>
/*
// -----------------------------------------------------------------------------------------------------------------------------------
// SYSTEM.H
// -----------------------------------------------------------------------------------------------------------------------------------
// Each instance of class System, represents a computer system (or network device) with an IP
// ----------------------------------------------------------------------------------------------------------------------------------- 
// Author : arjun25064
// -----------------------------------------------------------------------------------------------------------------------------------
*/
class System {
private:
    // ----ip-----
    // it represents the IP address of the system 
    std::string ip;

public:
    // ---- constructor ------
    // default constructor
    System() {}

    // ----constructor-------
    // explicit constructor
    // Arguments: ip is the string which represents the IP address of the system
    // Post Calling: sets the ip address variable
    System(const std::string& ip) : ip(ip) {}

    // ---- destructor -----
    ~System() {}

    // ---- getIP ------
    // returns the IP of system
    // Arguments: None
    // Post Calling: returns the ip
    const std :: string getIP() const { return ip; }

    // ------- operator== -------
    // overloading == operator
    // (Needed for union operation ie adding two system under the same network)
    bool operator==(const System& other) const { return ip == other.ip; }
    
    // ----- operator!= -----
    // overloading != operator
    // (Needed to for path compression in disjoint set)
    bool operator!=(const System& other) const { return !(*this == other); }

    // ----- operator<< ------
    // overloading the << operator to print the IP of the system
    friend std::ostream& operator<<(std::ostream& os, const System& sys) {
        os << sys.ip;
        return os;
    }
};

// generate hash value for object type T
// (to be used in unordered_map)
namespace std {
    template <>
    struct hash<System> {
        std::size_t operator()(const System& sys) const noexcept {
            return hash<std::string>()(sys.getIP());
        }
    };
}

