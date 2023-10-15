#include <iostream>

#include "Money.h"

using namespace std;

int main() {

    int arg;

    do {
        cin >> arg;

        switch (arg) {
        case 1: {
            cout << "Ctor:\n";
            Money m = Money(500, 25);
            cout << m.ToString() << endl;
            break;
        }
        case 2: {
            cout << "istream && ostream:\n";
            Money m;
            cin >> m;
            cout << m << endl;
            break;
        }
        case 3: {
            cout << "Sum:\n";
            Money m1 = Money(100, 57);
            Money m2 = Money(100, 43);
            cout << m1 + m2 << endl;
            break;
        }
        case 4: {
            cout << "Sub\n";
            Money m1 = Money(100, 74);
            Money m2 = Money(50, 24);
            cout << m1 - m2 << endl;
            break;
        }
        case 5: {
            cout << "Mult\n";
            Money m1 = Money(100, 25);
            cout << m1 * 5 << endl;
            break;
        }
        case 6: {
            cout << "Div\n";
            Money m1 = Money(501, 25);
            cout << m1 / 5 << endl;
            break;
        }
        default: {
            arg = -1;
        }
        }

    } while (arg != -1);

    return 0;
}