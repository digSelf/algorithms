#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int>& A, vector<int>& B, int l, int r, int x) {
    if (A[l] + B[r] < x)
        return true;
    
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    // 完成数据的读入
    int n, m, x;
    cin >> n >> m >> x;
    
    vector<int> A(n, 0), B(m, 0);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = 0; i < m; ++i)
        cin >> B[i];
    
    
    int l = 0, r = 0;
    for (l = 0, r = m - 1; r >= 0; --r) {
        while (l <= n - 1 && check(A, B, l, r, x)) {
            ++l;
        }
        
        // 此时判断是否是相等的情况，由于题目保证有解，所以不用添加表达式短路
        if (A[l] + B[r] == x) {
            cout << l << " " << r << endl;
            return 0;
        }
    }

    return 0;
}