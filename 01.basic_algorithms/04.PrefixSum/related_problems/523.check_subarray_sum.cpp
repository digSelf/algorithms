#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        unordered_map<int, int> r_to_index;

        // 由于nums是从0开始的，因此0对应的下标是-1，从而当i==1时，如果余数为0
        // 则前缀和区间长度为1 - (-1) = 2
        r_to_index[0] = -1;

        int prefix_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            int r = prefix_sum % k;

            if (r_to_index.find(r) != r_to_index.end()) {
                if (i - r_to_index[r] >= 2)
                    return true;
                else continue; // 由于要保存的是当前余数的最小下标索引，所以直接continue就行了
            }

            // 对于当前余数，索引表中没有，则保存当前余数对应的下标索引
            r_to_index[r] = i;
        }   

        return false;
    }
};