#include <iostream>
#include <fstream>
#include <map>

#include "stack.h"

using namespace std;

ifstream* fopen(string path) {
    ifstream* file = new ifstream(path, ios::in);

    if (!file->is_open()) {
        delete file;
        return nullptr;
    }

    return file;
}

stack fparse(string path) {
    auto file = fopen(path);

    if (file == nullptr) {
        throw invalid_argument("invalid file path");
    }

    char ch;
    stack s = stack();
    while (file->get(ch)) {
        s.push(ch);
    }

    file->close();
    delete file;

    return s;
}

bool solve(stack s) {
    auto opposite = [](char ch) -> int {
        return ch == '(' ? ')' : (ch == '[' ? ']' : (ch == '{' ? '}' : ch));
    };

    map<char, int> states;

    while (!s.is_empty()) {
        char next = s.pop();
        
        if (next == '(' || next == '[' || next == '{') {
            int ops = opposite(next);
            if (!states[ops]) {
                return false;
            }
            states[ops]--;
        }
        else {
            states[next]++;
        }
    }

    return true;
}

int main() {

    auto s = fparse("data.txt");

    if (solve(s)) {
        cout << "true\n";
    }
    else {
        cout << "false\n";
    }

    return 0;
}