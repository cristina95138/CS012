#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {
    while (!empty()) {
        pop_front();
    }
}

IntList::IntList(const IntList &cpy) {
    IntNode* copy = cpy.head;
    
    head = nullptr;
    tail = nullptr;
    
    while (copy != nullptr) {
        push_back(copy->data);
        copy = copy->next;
    }
    
    return;
}

void IntList::display() const {
    IntNode* tempNode = nullptr;
    if (!empty()) {
        tempNode = head->next;
        cout << head->data;
        
        while (tempNode != nullptr) {
            cout << " " << tempNode->data;
            tempNode = tempNode->next;
        }
    }
    delete tempNode;
}

void IntList::push_front(int value) {
    IntNode* tempNode = new IntNode(value);
    if (empty()) {
        head = tempNode;
        tail = tempNode;
    }
    else {
        tempNode->next = head;
        head = tempNode;
    }
}

void IntList::pop_front() {
    IntNode* tempNode = nullptr;
    if (empty()) {
        return;
    }
    else {
        tempNode = head;
        head = head->next;
        delete tempNode;
    }
}

bool IntList::empty() const {
    if (head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

const int & IntList::front() const {
   return head->data;
}

const int & IntList::back() const {
   return tail->data;
}

void IntList::push_back(int value) {
    IntNode* tempNode = new IntNode(value);
    if (empty()) {
        head = tempNode;
        tail = tempNode;
    }
    else {
        tail->next = tempNode;
        tail = tempNode;
    }
}

void IntList::clear() {
    while (!empty()) {
        pop_front();
    }
    head = nullptr;
    tail = nullptr;
    
    return;
}

void IntList::selection_sort() {
    IntNode* currNode = nullptr;
    IntNode* itNode = nullptr;
    IntNode* min = nullptr;
    
    if (empty()) {
        return;
    }
    
    if (head == tail) {
        return;
    }
    
    for (currNode = head; currNode != NULL; currNode = currNode->next) {
        min = currNode;
        for (itNode = currNode->next; itNode != NULL; itNode = itNode->next) {
            if (min->data > itNode->data) {
                min = itNode;
            }
        }
        swap (min->data, currNode->data);
    }
    
}

void IntList::insert_ordered(int value) {
    IntNode* newNode = new IntNode(value);
    IntNode* currNode = nullptr;
    IntNode* nextNode = nullptr;
    
    if (empty()) {
        push_front(value);
        return;
    }
    
    if (newNode->data <= head->data) {
        push_front(value);
        delete newNode;
        return;
    }
    
    if (newNode->data >= tail-> data) {
        push_back(value);
        delete newNode;
        return;
    }
    
    for (currNode = head; currNode != NULL; currNode = currNode->next) {
        nextNode = currNode->next;
        if (newNode->data <= nextNode->data) {
            currNode->next = newNode;
            newNode->next = nextNode;
            return;
        }
    }
    
    return;
}

void IntList::remove_duplicates() {
    IntNode* currNode = nullptr;
    IntNode* itNode = nullptr;
    IntNode* previous = nullptr;
    IntNode* tempNode = nullptr;
    
    for (currNode = head; currNode != NULL; currNode = currNode->next) {
        previous = currNode;
        for (itNode = currNode->next; itNode != NULL; itNode = previous->next) {
            if (currNode->data == itNode->data) {
                if (itNode == tail) {
                    tempNode = itNode;
                    previous->next = NULL;
                    tail = previous;
                    delete tempNode;
                }
                else {
                    tempNode = itNode;
                    previous->next = itNode->next;
                    delete tempNode;
                }
            }
            else {
                previous = previous->next;
            }
        }
     }
}

    

IntList & IntList::operator=(const IntList &rhs) {
    IntNode* tempNode = rhs.head;
    
    if (this == &rhs) {
        return *this;
    }
    
    clear();
    
    while (tempNode != nullptr) {
        push_back(tempNode->data);
        tempNode = tempNode->next;
    }
    
    return *this;
}

ostream & operator<<(ostream &out, const IntList &rhs) {
   IntNode* outNode = rhs.head;
    
    while (outNode != nullptr) {
        if (outNode->next != nullptr) {
            out << outNode->data << " ";
            
        }
        else {
            out << outNode->data;
        }
        outNode = outNode->next;
    }
    
    return out;
}