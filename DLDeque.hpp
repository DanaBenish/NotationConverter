#ifndef DLDEQUE_HPP
#define DLDEQUE_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <stdexcept>

class Deque { // Doubly linked list node
private:
    struct DNode{
        DNode* prev; // Prev node in list
        DNode* next; // Next node in list
        std::string data; 
        DNode(std::string c) : prev(nullptr), next(nullptr), data(c) {}
    };
    
    DNode* front;
    DNode* back;

public:
    Deque();
    ~Deque();

    void pushFront(const std::string& val);
    void pushBack(const std::string& val);
    std::string popFront();
    std::string popBack();
    std::string getBack(); 
    bool isEmpty() const;


    friend class NotationConverte; // Alow NotationConverter access
};

#endif