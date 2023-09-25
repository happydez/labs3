#include <iostream>

#include "List.h"

using namespace std;

int main() {

    auto list = new List({ 1, 0, 4, 2, 0, 5, 9 });

    list->Print();

    auto it = list->Find(0);
    if (it != nullptr) it = it->Next;
    while (it != nullptr) {
        if (it->Data == 0) {
            break;
        }
        cout << it->Data << " ";
        it = it->Next;
    }
    it = nullptr;
    cout << endl;

    list->Print();

    it = list->Iterator();
    while (it != nullptr) {
        if (it->Data == 0) {
            list->Remove(it->Data);
        }
        it = it->Next;
    }
    it = nullptr;

    list->Print();


    return 0;
}
