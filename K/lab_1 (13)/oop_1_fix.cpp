#include <iostream>
#include <Windows.h>
#include "Money.h"

using namespace std;

int main() {

    int arg;

    do {
        cin >> arg;

        switch (arg)
        {
        case 0: {
            cout << "Ctors:" << endl;
            auto m1 = Money(2587, 254);
            cout << "m1 = " << m1.ToString() << endl;
            
            auto m2 = Money(999, 100);
            cout << "m2 = " << m2.ToString() << endl;

            auto m3 = Money(0, 134);
            cout << "m3 = " << m3.ToString() << endl;

            break;
        }
        case 1: {
            cout << "Sum:" << endl;
            auto m1 = Money(749, 64);
            auto m2 = Money(5, 36);

            cout << "m1 = " << m1.ToString() << endl;
            cout << "m2 = " << m2.ToString() << endl;
            cout << "m1 + m2 = " << (m1 + m2).ToString() << endl;
            break;
        }
        case 2: {
            cout << "Sub:" << endl;
            auto m1 = Money(749, 64);
            auto m2 = Money(4, 14);

            cout << "m1 = " << m1.ToString() << endl;
            cout << "m2 = " << m2.ToString() << endl;
            cout << "m1 - m2 = " << (m1 - m2).ToString() << endl;
            break;
        }
        case 3: {
            cout << "Mult:" << endl;

            auto m1 = Money(1000, 25);
            auto m2 = Money(4, 25);

            cout << "m1 = " << m1.ToString() << endl;
            cout << "m2 = " << m2.ToString() << endl;
            cout << "m1 * m2 = " << (m1 * m2).ToString() << endl;
            break;
        }
        case 4: {
            cout << "Div:" << endl;

            auto m1 = Money(1000);
            auto m2 = Money(4, 25);

            cout << "m1 = " << m1.ToString() << endl;
            cout << "m2 = " << m2.ToString() << endl;
            cout << "m1 / m2 = " << (m1 / m2).ToString() << endl;
            break;
        }
        case 5: {
            cout << "Mult 2:" << endl;

            auto m1 = Money(1000);
            auto m2 = Money(0, 325);

            cout << "m1 = " << m1.ToString() << endl;
            cout << "m2 = " << m2.ToString() << endl;
            cout << "m1 * m2 = " << m1.Multiply(m2.GetRubles(), m2.GetKopecks()).ToString() << endl;
            break;
        }
        case 6: {
            cout << "Div 2:" << endl;

            auto m1 = Money(1000);
            auto m2 = Money(0, 325);

            cout << "m1 = " << m1.ToString() << endl;
            cout << "m2 = " << m2.ToString() << endl;
            cout << "m1 / m2 = " << m1.Division(m2.GetRubles(), m2.GetKopecks()).ToString() << endl;
            break;
        }
        case 7: {
            auto m1 = Money(5376, 1254);

            cout << "m1 = " << m1.ToString() << endl;
            cout << "m1 rubs = " << m1.GetRubles() << endl;
            cout << "m2 kops = " << m1.GetKopecks() << endl;
            break;
        }
        case 8: {
            auto m1 = Money(5000, 49);
            auto m2 = Money(723, 49);

            cout << "m1 = " << m1.ToString() << endl;
            cout << "m2 = " << m2.ToString() << endl;
            cout << "m1 == m2: " << (m1 == m2) << endl;
            break;
        }
        case 9: {
            auto m1 = Money(5000, 49);
            auto m2 = Money(5000, 49);

            cout << "m1 = " << m1.ToString() << endl;
            cout << "m2 = " << m2.ToString() << endl;
            cout << "m1 == m2: " << (m1 == m2) << endl;
            break;
        }
        case 10: {
            auto m = Money(5374, 52);
            
            cout << "m = " << m.ToString() << endl << endl;

            cout << "5000: " << m[RubleNominal::R5000] << endl;
            cout << "100: " << m[RubleNominal::R100] << endl;
            cout << "50: " << m[RubleNominal::R50] << endl;
            cout << "2: " << m[RubleNominal::R2] << endl;
            cout << "1: " << m[RubleNominal::R1] << endl << endl;

            cout << "0,50: " << m[KopeckNominal::K50] << endl;
            cout << "0,01: " << m[KopeckNominal::K1] << endl;
            break;
        }
        default:
            break;
        }

    } while (arg != -1);

    return 0;
}
