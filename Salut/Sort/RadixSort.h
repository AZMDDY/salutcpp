#ifndef SALUT_SORT_RADIX_SORT_H_
#define SALUT_SORT_RADIX_SORT_H_
#include <vector>
#include <array>
#include <algorithm>

namespace salut {
    namespace sort {
        template<class T>
        void RadixSort(std::vector<T>& arr)
        {
            T maxVal = *(std::max_element(arr.begin(), arr.end()));
            std::vector<T> tmp = arr;
            std::array<int, 20> count{};
            for (int64_t exp = 1; maxVal / exp > 0; exp *= 10) {
                count.fill(0);
                for (int i = 0; i < arr.size(); i++) {
                    count[10 + (arr[i] / exp) % 10]++;
                }
                for (int i = 9; i > 0; i--) {
                    count[i - 1] += count[i];
                }
                count[10] += count[0];
                for (int i = 11; i < 20; i++) {
                    count[i] += count[i - 1];
                }
                for (int i = arr.size() - 1; i >= 0; i--) {
                    tmp[count[10 + (arr[i] / exp) % 10] - 1] = arr[i];
                    count[10 + (arr[i] / exp) % 10]--;
                }
                arr = tmp;
            }
        }
    }  // namespace sort
}  // namespace salut

#endif  // SALUT_SORT_RADIX_SORT_H_