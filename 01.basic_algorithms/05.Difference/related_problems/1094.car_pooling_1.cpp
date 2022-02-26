// 这个版本未使用哨兵节点去做，但是多了几个判断
#include <vector>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        const int max_loc_size = 1000;
        vector<int> diff(max_loc_size, 0);


        int max_loc_index = 0;
        for (auto& trip : trips) {
            int num = trip[0], start = trip[1], end = trip[2];
            diff[start] += num;
            if (end < max_loc_size)
                diff[end] -= num;

            max_loc_index = max(max_loc_index, end);
        }

        int sum = 0;
        for (int i = 0; i < max_loc_index; ++i) {
            sum += diff[i];

            if (sum > capacity)
                return false; 
        }

        return true;
    }
};