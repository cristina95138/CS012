#include <iostream>
#include <stdexcept>

using namespace std;

#include "IntVector.h"

IntVector::IntVector() {
    sz = 0;
    cap = 0;        
    data = nullptr;
}

IntVector::IntVector(unsigned size, int value) {
    sz = size;
    cap = size;
    data = new int[cap];
    for (unsigned i = 0; i < sz; ++i) {
        data[i] = value;
    }
}

IntVector::~IntVector() {
    delete[] data;
}

unsigned IntVector::size() const {
    return sz;
}

unsigned IntVector::capacity() const{
    return cap;
}

bool IntVector::empty() const{
            
    if (sz == 0) {
        return true;
    }
    else {
        return false;
    }
    
}

const int & IntVector::at(unsigned index) const {
    if (index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return data[index];
    }
}

int & IntVector::at(unsigned index) {
    if (index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return data[index];
    }
}

const int & IntVector::front() const {
    return data[0];
}

int & IntVector::front() {
     return data[0];   
}

const int & IntVector::back() const {
    return data[sz - 1];
}

int & IntVector::back() {
    return data[sz - 1];
}

void IntVector::insert(unsigned index, int value) {
    if (index > sz) {
        throw out_of_range("IntVector::insert_range_check");
    }
    
    ++sz;
    
    if (cap < sz) {
        expand();
    }
    
    for (unsigned i = sz - 1; i > index; --i) {
        data[i] = data[i - 1];
    }
    
    data[index] = value;
}
    
void IntVector::erase(unsigned index) {
    if (index >= sz) {
        throw out_of_range("IntVector::erase_range_check");
    }
    
    for (unsigned i = index; i + 1 < sz; ++i) {
        data[i] = data[i + 1];
    }
    
    --sz;
    
}
    
void IntVector::assign(unsigned n, int value) {
    if (n <= cap) {
        sz = n;
        for (unsigned i = 0; i < sz; ++i) {
            data[i] = value;
        }
    }
    else if (n > (2 * cap)) {
        expand(n);
        sz = n;
        for (unsigned j = 0; j < sz; ++j) {
            data[j] = value;
        }
    }
    else if (n > cap) {
        expand();
        sz = n;
        for (unsigned k = 0; k < sz; ++k) {
            data[k] = value;
        }
    }
}
    
void IntVector::push_back(int value) {
    if (sz >= cap) {
        expand();
    }
    ++sz;
    data[sz - 1] = value;
}
    
void IntVector::pop_back() {
   if (sz > 0) {
       --sz;
   }
}
    
void IntVector::clear() {
    sz = 0;
}
    
void IntVector::resize(unsigned size, int value) {
    if (sz > size) {
        sz = size;
    }
    else if (sz < size) {
        unsigned tempSZ = sz;
        sz = size;
        if (sz > (2 * cap)) {
            expand(sz);
        }
        else if (size > cap) {
            expand();
        }
        for (unsigned i = tempSZ; i < sz; ++i) {
            data[i] = value;
        }
    }
}
    
void IntVector::reserve(unsigned n) {
    if (n > cap) {
        expand(n);
    }
}

void IntVector::expand() {
    int* expandPtr = data;
    
    cap *= 2;
    
    if (cap == 0) {
        cap = 1;
        data = new int[cap];
    }
    else {
        data = new int[cap];
        for (unsigned i = 0; i < sz; ++i) {
            data[i] = expandPtr[i];
        }
    }
}

void IntVector::expand(unsigned amount) {
    int* expandPtr = nullptr;
    
    if (cap == 0) {
        cap = amount;
        expandPtr = new int[cap];
    }
    else {
        cap = amount;
        expandPtr = new int[cap];
        for (unsigned i = 0; i < sz; ++i) {
            expandPtr[i] = data[i];
        }
    }
    
    delete[] data;
    
    data = expandPtr;
    
}

//Test Case Function

void IntVector::output() {
    for (unsigned i = 0; i < sz; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}