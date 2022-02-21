#include <vector>
using namespace std;

class Solution {
    typedef long long llong;
    int merge_sort_helper(vector<int>& arr, int start, int end) {
        if (start >= end) return 0;

        int mid = (start + end) >> 1;
        int count = merge_sort_helper(arr, start, mid) + merge_sort_helper(arr, mid + 1, end);

        // 到这里的时候，两个表已经是有序表了，那么为什么是在这里进行计数，而不是在合并的时候进行计数
        // 因为要比较多次
        // count
        for (int i = start, j = mid + 1; i <= mid && j <= end; ) {
            llong left = arr[i], right = arr[j];
            if (left <= 2 * right) {
                ++i;
            } else {
                count += mid - i + 1;
                ++j;
            }
        }

        // merge
        vector<int> tmp;
        int left = start, right = mid + 1;
        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                tmp.push_back(arr[left++]);
            } else { // 
                tmp.push_back(arr[right++]);
            }
        }

        while (left <= mid) {
            tmp.push_back(arr[left++]);
        }

        while (right <= end) {
            tmp.push_back(arr[right++]);
        }

        for (int i = 0; i < tmp.size(); ++i) {
            arr[start + i] = tmp[i];
        }

        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return merge_sort_helper(nums, 0, nums.size() - 1);
    }
};