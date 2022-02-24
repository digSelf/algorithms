#include <cstdio>

const int N = 1e3 + 5;
int matrix[N][N];
int sum[N][N];

void calc_prefix_sum(int (*matrix)[N], int n, int m, int (*s)[N]) {
    // s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i][j];
        }
    }
}

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);

    // 获取整个矩阵
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    calc_prefix_sum(matrix, n, m, sum);
    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        int val = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
        printf("%d\n", val);
    }

    return 0;
}