#ifndef SORTEDSET_H
#define SORTEDSET_H

#include <ostream>
#include "IntList.h"

using namespace std;

class SortedSet : public IntList {

 public:
    
    SortedSet();
    SortedSet(const SortedSet &);
    SortedSet(const IntList &);
    ~SortedSet();
    bool in(int data);
    SortedSet operator|(const SortedSet &);
    SortedSet operator&(const SortedSet &);
    void add(int);
    void push_front(int);
    void push_back(int);
    void insert_ordered(int);
    SortedSet & operator|=(const SortedSet &);
    SortedSet & operator&=(const SortedSet &);

};

#endif

