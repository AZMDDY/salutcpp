#include <iostream>
#include "Salut/Sort/BucketSort.h"
#include "Salut/Sort/RadixSort.h"
using namespace std;

using namespace salut;

int main(int argc, char** argv)
{
    vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    sort::BucketSort<int>(arr, 5, [](int a) { return 4 - a / 2; });
    for (auto& a : arr) {
        std::cout << a << ",";
    }
    std::cout << std::endl;
    sort::RadixSort<int>(arr);
    for (auto& a : arr) {
        std::cout << a << ",";
    }
    return 0;
}