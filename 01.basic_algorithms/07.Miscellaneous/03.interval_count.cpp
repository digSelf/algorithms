#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

size_t count_intervals_after_union(vector<PII>& pairs) {
    // 如果没有或者只有一个元素，直接返回，本身就合并了
    if (pairs.size() <= 1)
        return pairs.size();
    
    // start和end标志着当前正在合并的区间的起始点和终点，为闭区间[start, end]
    int start = pairs[0].first, end = pairs[0].second;

    vector<PII> result;
    for (int i = 1; i < pairs.size(); ++i) {
        int left = pairs[i].first, right = pairs[i].second;

        if (end < left) { // 没有交集
            result.emplace_back(start, end);
            start = left, end = right;
        } else { // 有交集合并
            end = max(end, right);
        }
    }

    // 合并到最后只有一个区间了，补加入到结果集中
    result.emplace_back(start, end);

    return result.size();
}

int main() {
    std::ios::sync_with_stdio(false);
    int n; cin >> n;

    vector<PII> pairs;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        pairs.emplace_back(l, r);
    }

    sort(pairs.begin(), pairs.end());

    cout << count_intervals_after_union(pairs) << endl;

    return 0;
}