// 该版本使用vector等容器实现
#include <iostream>
#include <vector>

using namespace std;

void insert(vector<vector<int>>& diff, int x1, int y1, int x2, int y2, int c) {
    diff[x1][y1] += c;
    diff[x1][y2 + 1] -= c;
    diff[x2 + 1][y1] -= c;
    diff[x2 + 1][y2 + 1] += c;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> arr(n + 5, vector<int>(m + 5, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int c; cin >> c;
            insert(arr, i, j, i, j, c);
        }
    }

    // 接受输入请求处理
    while (q --) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;

        insert(arr, x1, y1, x2, y2, c);
    }

    // 求前缀和
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }

    // 输出矩阵的结果
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << arr[i][j] << " \n"[j == m];
        }
    }

    return 0;
}