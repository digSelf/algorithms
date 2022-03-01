#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0], end = intervals[0][1];
        for (auto& range : intervals) {
            int left = range[0], right = range[1];

            if (end < left) {
                result.emplace_back(vector<int>({start, end}));
                start = left, end = right;
            } else {
                end = max(end, right);
            }
        }

        result.emplace_back(vector<int>({start, end}));

        return result;
    }
};