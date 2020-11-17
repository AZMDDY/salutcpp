#include <iostream>
#include "Salut/Sort/BucketSort.h"
using namespace std;

using namespace salut;

int main(int argc, char** argv)
{
    vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    sort::BucketSort(arr, 5, [](int a) { return a / 2; });
    for (auto& a : arr) {
        std::cout << a << ",";
    }
    return 0;
}