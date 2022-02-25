#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> record;
        record.insert(pair<int, int>(0, 1));

        int prefix_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            if (record.find(prefix_sum - k) != record.end()) {
                ans += record[prefix_sum - k];
            }

            record[prefix_sum]++;
        }

        return ans;
    }
};