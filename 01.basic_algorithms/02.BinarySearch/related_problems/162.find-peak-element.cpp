#include <vector>
using namespace std;

class Solution {
    static int binary_search_helper(const vector<int>& arr, int start, int end) {
        int left = start, right = end;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // 若为上升
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

public:
    int findPeakElement(vector<int>& nums) {
        return binary_search_helper(nums, 0, nums.size() - 1);
    }
};