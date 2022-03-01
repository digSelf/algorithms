#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    size_t get_index(const vector<int>& map, int x) {
        int left = 0, right = map.size() - 1;

        while (left < right) {
            int mid = (left + right) >> 1;

            if (map[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left + 1;
    }

public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> indicies(arr);
        sort(indicies.begin(), indicies.end());
        indicies.erase(unique(indicies.begin(), indicies.end()), indicies.end());

        vector<int> result;
        for (auto x : arr) {
            result.push_back(get_index(indicies, x));
        }   

        return result;
    }
};