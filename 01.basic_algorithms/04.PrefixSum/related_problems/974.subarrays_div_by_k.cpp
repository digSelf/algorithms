#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> r_to_count;
        r_to_count[0] = 1;

        int prefix_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];

            // 防止余数是负数的情况，如果是负数，则调整为正
            int r = (prefix_sum % k + k) % k;
            if (r_to_count.find(r) != r_to_count.end()) {
                ans += r_to_count[r];
            }

            r_to_count[r] ++;
        }

        return ans;
    }
};