#include <iostream>

using namespace std;

const int N = 1e3 + 5;
int arr[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
    arr[x1][y1] += c;
    arr[x2 + 1][y1] -= c;
    arr[x1][y2 + 1] -= c;
    arr[x2 + 1][y2 + 1] += c;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int c; cin >> c;
            insert(i, j, i, j, c);
        }
    }

    while (q --) {
        int x1, x2, y1, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }

    // 然后求矩阵的前缀和，输出出来结果即可
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + arr[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << arr[i][j] << " \n"[j == m];
        }
    }
    return 0;
}