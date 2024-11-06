#include "DLDeque.hpp"

// Deque methods implementation

// Deque list
Deque::Deque() : front(nullptr), back(nullptr) {}

Deque::~Deque(){
    while(!isEmpty()){
        popFront();
    }
}

// Push new node to the front of the deque
void Deque::pushFront(const std::string& val){

    DNode* node = new DNode(val); // Create new node

    if(isEmpty()){
        back = front = node;
    } else{
        // Link to front
        node -> next = front;
        front -> prev = node;
        front = node;
    }
}

// Push new node to the back of the deque
void Deque::pushBack(const std::string& val){

    DNode* node = new DNode(val); // Create new node

    if(isEmpty()){
        back = front = node;
    } else{
        // Link to back
        node -> prev = back;
        back -> next = node;
        back = node;
    }
}

// Pop front node and return data
std::string Deque::popFront(){

    // Throw if empty
    if (isEmpty())
    {
        throw std::out_of_range("Deque is empty");
    }

    std::string val = front -> data; // store data
    DNode* temp = front; // store front node to allocate

    if(front == back){
        // if there is only one node in the list, link back and front
        front = back = nullptr;
    } else{
        // Unlink front
        front = front -> next;
        front -> prev = nullptr;
    }

    delete temp;
    return val;
}

// Pop back node and return data
std::string Deque::popBack(){

    // Throw if empty
    if (isEmpty())
    {
        throw std::out_of_range("Deque is empty");
    }
    std::string val = back -> data; // store data
    DNode* temp = back; // store front node to allocate

     if(front == back){
        // if there is only one node in the list, link back and front
        front = back = nullptr;
     } else{
        // Unlink back
        back = back -> prev;
        back ->next = nullptr;
     }

     delete temp;
     return val;
}

// Get the data of the back node without popping it
std::string Deque::getBack(){

    if (back == nullptr) {
        // Handle case when deque is empty
        return ""; // Return an empty string
    }
    
    return back->data;
}

// Is the deque empty
bool Deque::isEmpty() const {
    return front == nullptr && back == nullptr;
}
