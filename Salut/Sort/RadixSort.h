#ifndef SALUT_SORT_RADIX_SORT_H_
#define SALUT_SORT_RADIX_SORT_H_
#include <vector>
namespace salut {
    namespace sort {
        template<class T>
        void RadixSort(std::vector<T>& arr)
        {
            T maxVal = *std::max(arr.begin(), arr.end());
            std::vector<T> tmp = arr;
            for (uint64_t exp = 1; maxVal / exp > 0; exp *= 10) {
                std::vector<int> count(10, 0);
                for (int i = 0; i < arr.size(); i++) {
                    count[(arr[i] / exp) % 10]++;
                }
                for (int i = 1; i < 10; i++) {
                    count[i] += count[i - 1];
                }
                for (int i = 0; i < arr.size(); i++) {
                    tmp[count[(arr[i] / exp) % 10] - 1] = arr[i];
                    count[(arr[i] / exp) % 10]--;
                }
                arr = tmp;
            }
        }
    }  // namespace sort
}  // namespace salut

#endif  // SALUT_SORT_RADIX_SORT_H_