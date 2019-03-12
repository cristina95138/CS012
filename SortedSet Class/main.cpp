#include <iostream>
using namespace std;

#include "SortedSet.h"

int main() {
   
    cout << "\nlist1 constructor called" << endl;
    SortedSet list1;
    cout << "\nadd 10 " << endl;
    list1.add(10);
    list1.display();
    cout << "\nadd 20 " << endl;
    list1.add(20);
    list1.display();
    cout << "\nadd 90 " << endl;
    list1.add(90);
    list1.display();
    cout << endl;

    cout << "\nlist2 constructor called" << endl;
    SortedSet list2;
    cout << "\nadd 20 " << endl;
    list2.add(20);
    list2.display();
    cout << "\nadd 40 " << endl;
    list2.add(40);
    list2.display();
    cout << "\nadd 10" << endl;
    list2.add(10);
    list2.display();
    cout << endl;

    cout << "Union (|) test" << endl;
    SortedSet list3;
    list3 = list1 | list2;
    cout << "List3: Expect 10 20 40 90" << endl;
    list3.display();
    cout << endl;

    cout << "List1 display " << endl;
    list1.display();
    cout << "List2 display " << endl;
    list2.display();
    cout << endl;

    cout << "Intersection (&) test " << endl;
    SortedSet list4;
    list4 = list1 & list2;
    cout << "List4: Expect 10 20 " << endl;
    list4.display();
    cout << endl;
    
    SortedSet list5;
    SortedSet list6;
    SortedSet list7;
    SortedSet list8;
    SortedSet list9;

    list5.add(10);
    list5.add(30);
    list5.add(40);
    list5.add(50);
    list5.add(90);

    list6.add(10);
    list6.add(30);
    list6.add(50);
    list6.add(60);
    list6.add(70);

    cout << "List5: ";
    list5.display();
    cout << endl;
    cout << "List6: ";
    list6.display();
    cout << endl;

    list7 = list5 & list6;
    cout << endl << "Expect: 10 30 50 " << endl << "List7: ";
    list7.display();
    cout << endl;

    list8.add(10);
    list8.add(50);
    cout << endl << "Expect: 10 50 " << endl << "List8: ";
    list8.display();
    cout << endl;

    list8 &= list9;
    list8.display();
    cout << endl;
    
    return 0;
}