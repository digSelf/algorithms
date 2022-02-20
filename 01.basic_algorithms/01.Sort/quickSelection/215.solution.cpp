#include <vector>
using namespace std;

class Solution {
    int quick_select(vector<int>& arr, int start, int end, int k) {
        if (start >= end)
            return arr[start];
        
        int left = start - 1, right = end + 1;
        int pivot = arr[(left + right) >> 1];

        while (left < right) {
            while (arr[++left] > pivot); // >=
            while (arr[--right] < pivot); // <=

            if (left < right) {
                std::swap(arr[left], arr[right]);
            }
        }

        if (k <= right - start + 1) {
            return quick_select(arr, start, right, k);
        } else {
            return quick_select(arr, right + 1, end, k - right + start - 1);
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums, 0, nums.size() - 1, k);
    }
};