#include <iostream>
#include <fstream>
#include <map>
#include <Windows.h>

#include "List.cpp"
#include "Record.h"

using namespace std;

ifstream* fopen(string path) {
    ifstream* file = new ifstream(path, ios::in);

    if (!file->is_open()) {
        delete file;
        return nullptr;
    }

    return file;
}

List<Record> fparse(string path) {
    auto file = fopen(path);

    if (file == nullptr) {
        throw invalid_argument("invalid file path");
    }

    List<Record> records;
    map<string, int> copies;
    
    while (!file->eof()) {
        Record rec;
        *file >> rec.Catalog >> rec.Name >> rec.Extension >> rec.Day >> rec.Month >> rec.Year >> rec.Size;

        if (copies.find(rec.FullName()) == copies.end()) {
            copies[rec.FullName()] = 1;
        }
        else {
            rec.Name = rec.Name + " - копия (" + to_string(copies[rec.FullName()]) + ")";
            copies[rec.FullName()]++;
        }

        records.PushBack(rec);
    }

    file->close();
    delete file;

    return records;
}

void solve(List<Record>& records) {
    records.Sort([](Record r1, Record r2) {
        return r1.FullName() > r2.FullName();
    });
}

int main() {

    setlocale(0, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string path = "data.txt";
    auto records = fparse(path);

    solve(records);

    records.Print();

    return 0;
}