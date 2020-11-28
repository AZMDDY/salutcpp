#ifndef SALUT_SORT_BUCKET_SORT_H_
#define SALUT_SORT_BUCKET_SORT_H_
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <functional>
namespace salut {
    namespace sort {
        // arr: 待排序数组；bucketNum：桶的数量；mappingFunc映射函数；comp: 桶内排序用的比较函数
        template<class T>
        void BucketSort(std::vector<T>& arr,
                        uint32_t bucketNum,
                        const std::function<uint32_t(T)>& mappingFunc,
                        const std::function<bool(const T& lhs, const T& rhs)>& comp = std::less<T>())
        {
            std::vector<std::vector<T>> buckets(bucketNum);
            for (auto& a : arr) {
                buckets[mappingFunc(a)].push_back(a);
            }
            for (uint32_t i = 0, j = 0; i < bucketNum; i++) {
                std::sort(buckets[i].begin(), buckets[i].end(), comp);
                for (auto& v : buckets[i]) {
                    arr[j++] = v;
                }
            }
        }
    }  // namespace sort
}  // namespace salut
#endif  // SALUT_SORT_BUCKET_SORT_H_