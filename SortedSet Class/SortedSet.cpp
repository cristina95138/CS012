#include <ostream>
using namespace std;

#include "SortedSet.h"
#include "IntList.h"

SortedSet::SortedSet() {
//     head = nullptr;
//     tail = nullptr;
}

SortedSet::SortedSet(const SortedSet &cpy) : IntList(cpy) {}

SortedSet::SortedSet(const IntList &cpy) : IntList(cpy) {
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet() {
    while (!empty()) {
        pop_front();
    }
}

bool SortedSet::in(int data) {
    IntNode* temp = head;
    
    while (temp != nullptr) {
        if (data == temp->data) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

SortedSet SortedSet::operator|(const SortedSet &rhs) {
    SortedSet temp(*this);
    IntNode* tempNode = rhs.head;
    
    while (tempNode != nullptr) {
        temp.add(tempNode->data);
        tempNode = tempNode->next;
    }
    return temp;
}

SortedSet SortedSet::operator&(const SortedSet &rhs) {
    SortedSet temp;
    IntNode* tempNode = rhs.head;
    
    while (tempNode != nullptr) {
        if (in(tempNode->data)) {
            temp.add(tempNode->data);
        }
        tempNode = tempNode->next;
    }
    return temp;
}

void SortedSet::add(int data) {
    if(!in(data)) {
        IntList::insert_ordered(data);
    }
}

void SortedSet::push_front(int data) {
    add(data);
}

void SortedSet::push_back(int data) {
    add(data);
}

void SortedSet::insert_ordered(int data) {
    add(data);
}

SortedSet & SortedSet::operator|=(const SortedSet &rhs) {
    *this = *this | rhs;
    return *this;
}

SortedSet & SortedSet::operator&=(const SortedSet &rhs) {
    *this = *this & rhs;
    return *this;
}