#include <cstdio>

const int N = 5e4 + 5;

// dist[x] 被定义为，从节点x到根节点的距离/代差；根节点到根节点的距离/代差定义为0
// 因此在初始化并查集的时候，无需初始化dist[i] = 0
int parent[N], dist[N];

int find(int idx) {
    if (parent[idx] != idx) {
        // 暂存为修改前的父节点指针
        int temp = find(parent[idx]);

        dist[idx] = dist[idx] + dist[parent[idx]];
        parent[idx] = temp;
    }

    return parent[idx];
}

void merge(int lhs, int rhs, int d) {
    int l = find(lhs), r = find(rhs);
    if (l == r)
        return;

    // 合并
    parent[l] = r;

    // 同类
    if (d == 1) {
        // (dist[lhs] + dist[l] - dist[rhs]) % 3 == 0 -> dist[l] = dist[rhs] -
        // dist[lhs]
        dist[l] = dist[rhs] - dist[lhs];
    } else {
        // (dist[lhs] + dist[l] - dist[rhs] - 1) % 3 == 0 -> dist[l] = dist[rhs]
        // + 1 - dist[lhs];
        dist[l] = dist[rhs] + 1 - dist[lhs];
    }
}

int main() {
    int n, k;
    std::scanf("%d%d", &n, &k);
    
    // NOTICE：并忘记并查集初始化
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    int result = 0;
    while (k--) {
        int d, x, y;
        std::scanf("%d%d%d", &d, &x, &y);

        if (x > n || y > n || (d != 1 && x == y)) {
            ++result;
        } else {
            int px = find(x), py = find(y);
            if (d == 1) { // 同类
                // 如果已经在同一个集合里面，且两者的代差模3的意义上不等，则为假话
                if (px == py && (dist[x] - dist[y]) % 3) {
                    ++result;
                } else {
                    merge(x, y, d);
                }
            } else { // 异类
                if (px == py && (dist[x] - dist[y] - 1) % 3) {
                    ++result;
                } else {
                    merge(x, y, d);
                }
            }
        }
    }

    printf("%d\n", result);
    return 0;
}