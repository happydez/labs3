#include <iostream>
#include <Windows.h>

#include "AVLTree.h"

using namespace std;

void Menu(int& in) {

    cout << endl << "1. Добавить элемент" << endl
        << "2. Удалить элемент" << endl
        << "3. Получить высоту дерева" << endl
        << "4. Получить минимальный элемент дерева" << endl
        << "5. Проверить дерево на балансировку" << endl
        << "6. Выйти" << endl << endl;

    cout << ">> "; cin >> in;
}

void SetRu() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

int main() {

    SetRu();

    cout << "введите корень дерева >> ";
    int root; cin >> root;

    AVLTree* tree = new AVLTree(root);

    try
    {
        while (1) {
            int flag;
            Menu(flag);

            int elem;

            switch (flag)
            {
            case 1:
            case 2:
                cout << "введите элемент >> "; cin >> elem;
                if (flag == 1) {
                    tree->Insert(elem);
                }
                else {
                    tree->Remove(elem);
                }
                break;
            case 3:
                cout << "высота дерева = " << tree->Height() << endl;
                break;
            case 4:
                cout << "минимальный элемент дерева = " << tree->Minimum() << endl;
                break;
            case 5:
                cout << "является ли дерево сбалансированным - " << (tree->IsBalanced() ? "Да" : "Нет") << endl;
                break;
            default:
                flag = 0;
                break;
            }

            if (!flag) break;

            cout << endl << "состояние дерева: " << endl << endl << endl;
            tree->Print();
            cout << endl << endl << string(32, '-') << endl;
        }
    }
    catch (const std::exception& ex)
    {
        auto result = string(ex.what());
        cout << result << endl;
    }

    delete tree;
    tree = nullptr;

    return 0;
}




//#include <iostream>
//#include <Windows.h>
//
//#include "FamilyTree.h"
//
//using namespace std;
//
//void SetRu() {
//	setlocale(LC_ALL, "Russian");
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//}
//
//int main() {
//
//	SetRu();
//
//	FamilyTree* tree = new FamilyTree(2);
//
//	tree->Init();
//	tree->Print();
//
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <chrono>
//#include <Windows.h>
//
//using namespace std;
//
//void bubbleSort(vector<int>& arr) {
//    int n = arr.size();
//    for (int i = 0; i < n - 1; ++i) {
//        for (int j = 0; j < n - i - 1; ++j) {
//            if (arr[j] > arr[j + 1]) {
//                swap(arr[j], arr[j + 1]);
//            }
//        }
//    }
//}
//
//void SetRu() {
//    setlocale(LC_ALL, "Russian");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//}
//
//int main() {
//    SetRu();
//    srand(time(0));
//
//    int N = 20000;
//    cout << "N = " << N << endl;
//    vector<int> best_case(N), average_case(N), worst_case(N);
//
//    for (int i = 1; i <= N; i++) {
//        best_case[i - 1] = i;
//        worst_case[i - 1] = N - i + 1;
//        average_case[i - 1] = rand() % N;
//    }
//
//    // Замер времени для наилучшего случая
//    auto start_best = chrono::high_resolution_clock::now();
//    bubbleSort(best_case);
//    auto end_best = chrono::high_resolution_clock::now();
//    chrono::duration<double> duration_best = end_best - start_best;
//    cout << "Лучшее время (массив уже отсортирован): " << duration_best.count() << " seconds" << endl;
//
//    // Замер времени для среднего случая
//    auto start_avg = chrono::high_resolution_clock::now();
//    bubbleSort(average_case);
//    auto end_avg = chrono::high_resolution_clock::now();
//    chrono::duration<double> duration_avg = end_avg - start_avg;
//    cout << "Среднее время (массив заполнен произвольно): " << duration_avg.count() << " seconds" << endl;
//
//    // Замер времени для худшего случая
//    auto start_worst = chrono::high_resolution_clock::now();
//    bubbleSort(worst_case);
//    auto end_worst = chrono::high_resolution_clock::now();
//    chrono::duration<double> duration_worst = end_worst - start_worst;
//    cout << "Худшее время (массив отсортирован в обратном порядке): " << duration_worst.count() << " seconds" << endl;
//
//    return 0;
//}


//#include <iostream>
//#include <Windows.h>
//
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//void SetRu() {
//    setlocale(LC_ALL, "Russian");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//}
//
//void input(string msg, int& in) {
//    cout << msg;
//    cin >> in;
//}
//
//void vinput(string msg, vector<int>& vec) {
//    cout << msg;
//    for (int& elem : vec) {
//        cin >> elem;
//    }
//}
//
//void pvec(string msg, const vector<int>& vec) {
//    cout << msg;
//    for (const auto elem : vec) {
//        cout << elem << " ";
//    }
//    cout << endl;
//}
//
//int main() {
//
//    SetRu();
//
//    /*
//    *   10
//    *   2 1 7 9 4 2 1 3 9 4
//    *   4
//    *   9
//    *   
//    *   -------------------
//    *   8
//    *   3 8 4 1 7 5 10 2
//    *   5
//    *   7
//    */
//
//    int x, y, n;
//    input("n >> ", n);
//
//    vector<int> vec(n);
//    vinput("vec >> ", vec);
//
//    input("x >> ", x);
//    input("y >> ", y);
//
//    pvec("\nисходный вектор: ", vec);
//
//    vec.erase(remove_if(vec.begin(), vec.end(), [x](int elem) { return elem < x; }), vec.end()); 
//
//    pvec("вектор после фильтрации по x: ", vec);
//    
//    int len = vec.size();
//    auto iter = find_if(vec.rbegin(), vec.rend(), [&len, y](int elem) { 
//        if (elem >= y) {
//            return true;
//        }
//
//        len--;
//        return false;
//    });
//
//    vec.erase(vec.begin() + len - 1, vec.end());
//
//    pvec("вектор после фильтрации по y: ", vec);
//
//    return 0;
//}