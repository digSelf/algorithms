#include <iostream>

using namespace std;

// 溢出相当于对2^64取模
typedef unsigned long long ull;

const int N = 1e5 + 5;
const int P = 131;

char str[N];
ull h[N], p[N];

ull get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    cin >> (str + 1);

    // 预处理
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        // h[i - 1]是高位，每次向右移动，相当于高位都要再乘以一个P
        h[i] = h[i - 1] * P + str[i];

        // 用来统计P^i为多少，在get函数中使用
        p[i] = p[i - 1] * P;
    }

    while (m --) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if (get(l1, r1) == get(l2, r2)) {
            cout << "Yes" << endl; 
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}