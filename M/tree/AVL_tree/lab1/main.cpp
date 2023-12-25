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
