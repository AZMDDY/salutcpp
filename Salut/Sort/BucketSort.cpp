#include "BucketSort.h"

namespace salut {
    namespace sort {
        void BucketSort(std::vector<int>& arr, int bucketNum, const std::function<int(int)>& mappingFunc)
        {
            std::vector<std::vector<int>> buckets(bucketNum);
            for (int i = 0; i < arr.size(); i++) {
                buckets[mappingFunc(arr[i])].push_back(arr[i]);
            }
            for (int i = 0, j = 0; i < bucketNum; i++) {
                std::sort(buckets[i].begin(), buckets[i].end());
                for (auto& v : buckets[i]) {
                    arr[j++] = v;
                }
            }
        }
    }  // namespace sort
}  // namespace salut