#include <iostream>

#include "Array.h"

void case1() {
    Array* a1 = new SortArray(4);

    a1->Add(7);
    a1->Add(4);
    a1->Add(1);
    a1->Add(1);
    a1->Add(12);
    a1->Add(8);
    a1->Add(5);

    a1->Foreach();
    cout << *a1;

    Array* a2 = new SortArray(4);

    a2->Add(2);
    a2->Add(2);
    a2->Add(2);
    a2->Add(2);
    a2->Add(2);

    a1->Addition(*a2);
    a1->Foreach();
    cout << *a1;

    delete a1;
    delete a2;
}

void case2() {
    Array* a1 = new XorArray(2);
    
    a1->Add(1);
    a1->Add(2);

    a1->Foreach();
    cout << *a1;

    Array* a2 = new XorArray(4);
    
    a2->Add(1);
    a2->Add(2);
    a2->Add(3);
    a2->Add(4);
    a2->Add(-12);
    
    a1->Addition(*a2);
    a1->Foreach();
    cout << *a1;

    delete a1;
    delete a2;
}

int main() {

    //case1();
    //case2();

    return 0;
}