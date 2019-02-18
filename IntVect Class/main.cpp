// g++ -std=c++11 IntVector.cpp main.cpp -Wall -Werror -Wuninitialized -o a.out
// ./a.out

#include <iostream>

using namespace std;

#include "IntVector.h"

int main() {
    IntVector* myPtr = nullptr;
    int arrSize = 0;
    int val;
    string userInp = "";
    int index;
    int userType = 0;
    int pushVal;
    int resNum;
    
    cout << "Select vector type :" << endl;
    cout << "1 - Empty" << endl << "2 - Enter parameters" << endl;
    cin >> userType;
    
    if (userType == 1) {
        myPtr = new IntVector();
    }
    else if (userType == 2) {
        cout << "Vector Size: ";
        cin >> arrSize;
    
        cout << "Set vector value number: ";
        cin >> val;
        
        myPtr = new IntVector(arrSize, val);
    }
    
    cout << "Function call (at, front, back, push_back, pop_back, clear, resize, reserve, <<): ";
    
    while (cin >> userInp && userInp != "q") {
        if (userInp == "at") {
            cout << "Index: ";
            cin >> index;
            cout << myPtr->at(index) << endl;
            cout << "Function call (at, front, back, push_back, pop_back, clear, resize, reserve): ";
        }
        else if (userInp == "front") {
            cout << myPtr->front() << endl;
            cout << "Function call (at, front, back, push_back, pop_back, clear, resize, reserve): ";
        }
        else if (userInp == "back") {
            cout << myPtr->back() << endl;
            cout << "Function call (at, front, back, push_back, pop_back, clear, resize, reserve): ";
        }
        else if (userInp == "push_back") {
            cout << "Value: ";
            cin >> pushVal;
            myPtr->push_back(pushVal);
            ++arrSize;
            cout << "Function call (at, front, back, push_back, pop_back, clear, resize, reserve): ";
        } 
        else if (userInp == "pop_back") {
            myPtr->pop_back();
            cout << "Function call (at, front, back, push_back, pop_back, clear, resize, reserve): ";
        }
        else if (userInp == "clear") {
            myPtr->clear();
            arrSize = 0;
            cout << "Function call (at, front, back, push_back, pop_back, clear, resize, reserve): ";
        }
        else if (userInp == "resize") {
            cout << "Size: ";
            cin >> arrSize;
            cout << "Value: ";
            cin >> val;
            myPtr->resize(arrSize, val);
            cout << "Function call (at, front, back, push_back, pop_back, clear, resize, reserve): ";
        }
        else if (userInp == "reserve") {
            cout << "Reserve num: ";
            cin >> resNum;
            myPtr->reserve(resNum);
            cout << "Function call (at, front, back, push_back, pop_back, clear, resize, reserve): ";
        }
        else if (userInp == "<<") {
            //Test Case Function
            myPtr->output();
            cout << "Function call (at, front, back, push_back, pop_back, clear, resize, reserve): ";
        }
    }

    return 0;
}