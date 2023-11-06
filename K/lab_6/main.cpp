#include <iostream>

#include "SortedSet.h"

#include <Windows.h>

using namespace std;

int main() {
    
    function<int(int, int)> integersComparator = [](int x, int y) -> int {
        if (x < y) {
            return -1;
        }
        else if (x > y) {
            return 1;
        }

        return 0;
    };

    bool f = true;
    do {

        int arg;
        cin >> arg;

        switch (arg)
        {
        case 1: {
            system("cls");
            cout << "ctor, insert, remove, contains, count:" << endl << endl;
            
            SortedSet<int> s = SortedSet<int>(integersComparator);
            
            for (auto vl : { 1, 2, 3, 4, 5 }) {
                s.Insert(vl);
            }

            cout << "after inserted: " << s << endl;
            cout << "elements in set: " << s.Count() << endl << endl;

            s.Remove(2);
            s.Remove(4);

            cout << "after removed 2 & 4: " << s << endl;
            cout << "elements in set: " << s.Count() << endl << endl;

            s.Insert(10);
            s.Insert(25);

            cout << "after inserted 10 & 25: " << s << endl;
            cout << "elements in set: " << s.Count() << endl << endl;

            bool inSet25 = s.Contains(25);

            cout << "does the set contain 25?: " << (inSet25 ? "true" : "false") << endl << endl;

            bool inSet100 = s.Contains(100);

            cout << "does the set contain 100?: " << (inSet100 ? "true" : "false") << endl << endl;

            break;
        }
        case 2: {
            system("cls");
            cout << "union, intersect, except:" << endl << endl;


            SortedSet<int> s1 = SortedSet<int>(integersComparator);

            for (auto vl : { 1, 2, 3, 4, 5 }) {
                s1.Insert(vl);
            }

            SortedSet<int> s2 = SortedSet<int>(integersComparator);

            for (auto vl : { 3, 4, 5, 10, 12, 15 }) {
                s2.Insert(vl);
            }

            cout << "s1: " << s1 << endl;
            cout << "s2: " << s2 << endl;
            cout << endl;

            cout << "s1.Union(s2): " << s1.Union(s2) << endl << endl;

            cout << "s1.Intersect(s2): " << s1.Intersect(s2) << endl << endl;

            cout << "s1.Except(s2): " << s1.Except(s2) << endl << endl;

            break;
        }
        case 3: {
            system("cls");
            cout << "copy operator:" << endl << endl;

            SortedSet<int> s1 = SortedSet<int>(integersComparator);

            for (auto vl : { 1, 2, 3, 4, 5 }) {
                s1.Insert(vl);
            }

            cout << "s2 = s1" << endl << endl;
            SortedSet<int> s2 = s1;

            cout << "s1: " << s1 << endl;
            cout << "s2: " << s2 << endl;
            cout << endl;

            s2.Remove(3);
            s2.Remove(1);
            
            cout << "after removed 3 & 1 in s2:" << endl;
            cout << "s1: " << s1 << endl;
            cout << "s2: " << s2 << endl;
            cout << endl;

            break;
        }
        default:
            f = false;
            break;
        }

    } while (f);

    return 0;
}