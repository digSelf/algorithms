#include <vector>

using std::vector;

class Solution {
    void down(vector<int>& nums, int idx) {
        int u = idx;
        if (2 * idx <= nums.size() && nums[2 * idx - 1] < nums[u - 1]) {
            u = 2 * idx;
        }

        if (2 * idx + 1 <= nums.size() && nums[2 * idx] < nums[u - 1]) {
            u = 2 * idx + 1;
        }

        if (u != idx) {
            std::swap(nums[u - 1], nums[idx - 1]);
            down(nums, u);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = n / 2; i; --i) {
            down(nums, i);
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            result.emplace_back(nums.front());
            nums[0] = nums.back(); nums.pop_back();
            down(nums, 1);
        }

        return result;
    }
};
