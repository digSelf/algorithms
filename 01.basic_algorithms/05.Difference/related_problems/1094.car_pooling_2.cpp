// 这个版本使用的是哨兵，增加内存空间的使用
#include <vector>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        const int size = 1e3 + 5;
        vector<int> diff(size, 0);


        // [start, end) -> [start + 1, end + 1) -> [start + 1, end]
        int max_index = 0;
        for (const auto& trip : trips) {
            int n = trip[0], start = trip[1], end = trip[2];

            diff[start + 1] += n;
            diff[end + 1] -= n;

            max_index = max(max_index, end);
        }

        // check 
        for (int i = 1; i <= max_index; ++i) {
            diff[i] += diff[i - 1];

            if (diff[i] > capacity)
                return false;
        }

        return true;
    }
};