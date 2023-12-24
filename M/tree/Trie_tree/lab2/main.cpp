#include <iostream>
#include <Windows.h>

#include "TrieTree.h"

using namespace std;

void Menu(int& in) {
   
    cout << endl << "1. Добавить слово" << endl
         << "2. Удалить слово" << endl
         << "3. Удалить все слова, содержащие подстроку" << endl
         << "4. Заполнить готовыми значениями" << endl
         << "5. Выйти" << endl << endl;

    cout << ">> "; cin >> in;
}

void SetRu() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

int main() {

    SetRu();

    TrieTree* tree = new TrieTree();

    while (1) {
        int flag;
        Menu(flag);

        string str;

        switch (flag)
        {
        case 1:
        case 2:
            cout << "введите слово >> "; cin >> str;
            (flag == 1) ? tree->Insert(str) : tree->Remove(str);
            break;
        case 3:
            cout << "введите подстроку >> "; cin >> str;
            tree->RemoveWithSubstr(str);
            break;
        case 4:
            tree->Insert("cat"); tree->Insert("catar"); tree->Insert("carry");
            tree->Insert("cut"); tree->Insert("abc"); tree->Insert("abrr");
            tree->Insert("defens"); tree->Insert("deferent"); tree->Insert("track");
            tree->Insert("locked");
            break;
        default:
            flag = 0;
            break;
        }

        if (!flag) break;

        cout << endl << "состояние дерева: " << endl;
        tree->Show();
        cout << endl << string(32, '-') << endl;
    }

    delete tree;
    tree = nullptr;

    return 0;
}