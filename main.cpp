#include <iostream>
#include "Salut/Sort/BucketSort.h"
#include "Salut/Sort/RadixSort.h"
#include "Salut/Tree/BinTree.h"

using namespace std;

using namespace salut;

int main(int argc, char** argv)
{
    vector<int32_t> arr = {92, 803, 7, 43, -578, 4, 3, -2, -11111, 0};
//    sort::BucketSort<int>(arr, 5, [](int a) { return 4 - a / 2; });
//    for (auto& a : arr) {
//        std::cout << a << ",";
//    }
    std::cout << std::endl;
    sort::RadixSort<int32_t>(arr);
    for (auto& a : arr) {
        std::cout << a << ",";
    }

    tree::BinTree<int> t;
    t.InsertAsRoot(20);

    return 0;
}