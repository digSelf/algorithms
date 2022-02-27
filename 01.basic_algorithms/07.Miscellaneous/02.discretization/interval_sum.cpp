#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> PII;

int get_index(vector<int>& indices, int x) {
    int left = 0, right = indices.size() - 1;
    
    while (left < right) {
        int mid = (left + right) >> 1;
        
        if (indices[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    // [left, 10^5 - 1] + 1 -> [left + 1, 10^5]
    return left + 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // 要保存所有可能出现的index，然后再去重做索引函数
    vector<int> all_index;
    vector<PII> operations;
    
    for (int i = 0; i < n; ++i) {
        int x, c;
        cin >> x >> c;
        
        operations.push_back({x, c});
        all_index.push_back(x);
    }
    
    vector<PII> query;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        
        query.push_back({l, r});
        
        all_index.push_back(l);
        all_index.push_back(r);
    }
    
    sort(all_index.begin(), all_index.end());
    all_index.erase(unique(all_index.begin(), all_index.end()), all_index.end());
    
    vector<int> arr(all_index.size() + 1, 0);
    for (auto& op : operations) {
        int x = op.first, c = op.second;
        
        int idx = get_index(all_index, x);
        arr[idx] += c;
    }
    
    // 构造前缀和，注意：只是添加了一个哨兵0，元素个数函数arr.size() - 1
    // 所以最后一个元素的索引值i = arr.size() - 1
    for (int i = 1; i < arr.size(); ++i) {
        arr[i] += arr[i - 1];
    }
    
    // 查询
    for (auto& item : query) {
        int start = get_index(all_index, item.first), end = get_index(all_index, item.second);
        
        cout << arr[end] - arr[start - 1] << endl;
    }
    
    return 0;
}