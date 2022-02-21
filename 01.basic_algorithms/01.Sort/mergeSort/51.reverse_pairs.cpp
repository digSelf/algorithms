#include <vector>
using namespace std;


class Solution {
    int merge_sort_helper(vector<int>& arr, int start, int end) {
        if (start >= end) 
            return 0;
        
        int mid = (start + end) >> 1;
        int count = merge_sort_helper(arr, start, mid) + merge_sort_helper(arr, mid + 1, end);

        // merge and count
        int left = start, right = mid + 1;
        vector<int> tmp;
        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                tmp.push_back(arr[left++]);
            } else {
                // count
                count += mid - left + 1;
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