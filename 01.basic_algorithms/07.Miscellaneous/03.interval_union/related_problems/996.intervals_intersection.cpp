#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if (firstList.empty() || secondList.empty()) return {};

        vector<vector<int>> result;

        // 双指针算法的第二个模板，即：类似于归并排序的模板
        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size()) {
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);

            if (start <= end) {
                result.emplace_back(vector<int>({start, end}));
            }

            // check(i, j) -> 开始步进
            if (firstList[i][1] < secondList[j][1]) { // first.end < second.end
                ++i;
            } else {
                ++j;
            }
        }

        return result;
    }
};