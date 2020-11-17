#ifndef SALUT_SORT_BUCKET_SORT_H_
#define SALUT_SORT_BUCKET_SORT_H_
#include <algorithm>
#include <vector>
#include <functional>
namespace salut {
    namespace sort {
        void BucketSort(std::vector<int>& arr, int bucketNum, const std::function<int(int)>& mappingFunc);
    }  // namespace sort
}  // namespace salut
#endif  // SALUT_SORT_BUCKET_SORT_H_