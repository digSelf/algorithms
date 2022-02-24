#include <vector>
#include <iostream>

using namespace std;

// 差分数组的插入常数C的操作是成对出现的
void insert(vector<int>& diff, int l, int r, int c) {
    diff[l] += c;
    diff[r + 1] -= c;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    
    // 默认情况下，可以开大几个数，用来做哨兵
    // 0数组默认是一个差分数组，因为满足差分数组的定义
    vector<int> diff(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        int c; cin >> c;
        insert(diff, i, i, c);
    }
    
    while (m --) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(diff, l, r, c);
    }

    // 差分数组的前i项（包括第i项）的累加和等于给定数组中的第i项的值
    // 差分数组是前缀和的逆运算，即：已知前缀和n，求其一个差分数组，使得这个差分数组的i项和等于n
    for (int i = 1; i <= n; ++i) {
        diff[i] += diff[i - 1];
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << diff[i] << " ";
    }
    cout << endl;
     
    return 0;
}