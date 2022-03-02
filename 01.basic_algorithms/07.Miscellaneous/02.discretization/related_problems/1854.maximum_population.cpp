#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    int get_index(const vector<int>& map, int x) {
        return lower_bound(map.begin(), map.end(), x) - map.begin() + 1;
    }

    void insert_into_diff(vector<int>& diff, int l, int r, int x) {
        // [l, r]
        diff[l] += x;
        diff[r + 1] -=x;
    }

public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> indices;
        for (auto& record : logs) {
            indices.push_back(record[0]);
            indices.push_back(record[1]);
        } // 拿到所有的原始索引值（key）

        // 离散化映射，然后获取映射后的下标值
        sort(indices.begin(), indices.end());
        indices.erase(unique(indices.begin(), indices.end()), indices.end());

        // 构造差分数组
        vector<int> diff(indices.size() + 1, 0);
        for (auto& log : logs) {
            int birth = get_index(indices, log[0]);
            int death = get_index(indices, log[1]);

            insert_into_diff(diff, birth, death - 1, 1);
        }

        // 构造前缀和数组，并记录当前最大的值及其年份
        int idx = 0;
        for (int i = 1; i < diff.size(); ++i) {
            diff[i] += diff[i - 1];
            idx = (diff[idx] < diff[i] ? i : idx); 
        }

        return indices[idx - 1];
    }
};