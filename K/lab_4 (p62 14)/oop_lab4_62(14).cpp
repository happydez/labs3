#include <iostream>

#include "Date.h"

using namespace std;

int main() {

    int arg;

    do {
        cin >> arg;

        switch (arg)
        {
        case 1: {
            cout << "ctor:" << endl;
            Date date = Date("2023:10:20");
            cout << date << endl;
            break;
        }
        case 2: {
            cout << "in:" << endl;
            Date date;
            cin >> date;
            cout << date << endl;
            break;
        }
        case 3: {
            cout << "++ --" << endl;
            Date date = Date("2023:10:20");
            date++;
            cout << "++: " << date << endl;
            date--;
            cout << "--: " << date << endl;
            break;
        }
        case 4: {
            cout << "add, sub days" << endl;
            Date date = Date("2023:10:20");
            cout << date << endl;
            date.SubDays(20);
            cout << "after sub days: " << date << endl;
            date.AddDays(25);
            cout << "after add days: " << date << endl;
            break;
        }
        case 5: {
            cout << "date +- date" << endl;
            Date d1 = Date(2022, 9, 23);
            Date d2 = Date(1, 1, 2);

            cout << "date 1: " << d1 << endl;
            cout << "date 2: " << d2 << endl;

            Date* temp = d1 - d2;
            cout << "date 1 - date 2: " << *temp << endl;

            temp = d1 + d2;
            cout << "date 1 + date 2: " << *temp << endl;

            delete temp;

            break;
        }
        default:
            arg = -1;
            break;
        }

    } while (arg != -1);

    return 0;
}