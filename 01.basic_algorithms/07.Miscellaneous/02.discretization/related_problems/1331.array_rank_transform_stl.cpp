// 这个版本使用的是stl的lower_bound函数进行实现
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> map(arr);
        sort(map.begin(), map.end());
        map.erase(unique(map.begin(), map.end()), map.end());

        vector<int> result;
        for (auto x : arr) {
            int index = lower_bound(map.begin(), map.end(), x) - map.begin() + 1;
            result.push_back(index);
        }

        return result;
    }
};