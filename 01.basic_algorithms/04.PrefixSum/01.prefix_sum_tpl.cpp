#include <vector>
#include <iostream>
using namespace std;

vector<int> cacl_prefix_sum(const vector<int>& arr) {
    vector<int> result; 
    // 将数组的大小扩大一位，设置哨兵S_0 = 0
    // 相当于待求前缀和的数组的下标是从1开始的，而前缀和的数组下标是从0开始的
    result.resize(arr.size() + 1, 0);

    for (int i = 1; i < result.size(); ++i) {
        result[i] = result[i - 1] + arr[i - 1];
    }
    
    return result;
}

int main() {
    int n = 0, m = 0;
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        cin >> tmp;
        nums.push_back(tmp);
    }

    // 计算前缀和
    vector<int> prefix = cacl_prefix_sum(nums);

    while (m--) {
        int l = 0, r = 0;
        cin >> l >> r;

        // 查询
        cout << prefix[r] - prefix[l - 1] << endl;
    }

    return 0;
}