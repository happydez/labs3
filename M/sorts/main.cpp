#include <iostream>

#include "ArrayGenerator.h"

using namespace std;

void TestSortMethod(int N, ArrayInstance::GenerationType gt, ArrayInstance::SortType st)
{
    auto arr = ArrayInstance::Generate(N, gt);
    
    ArrayInstance::SortTime(arr, N, st, gt);

    delete[] arr;
}

int main()
{
    int N = 10000000;
    ArrayInstance::GenerationType gt = ArrayInstance::GenerationType::Sorted;

    TestSortMethod(N, gt, ArrayInstance::SortType::Tim);
    TestSortMethod(N, gt, ArrayInstance::SortType::Quick);
    TestSortMethod(N, gt, ArrayInstance::SortType::Shell);

    return 0;
}