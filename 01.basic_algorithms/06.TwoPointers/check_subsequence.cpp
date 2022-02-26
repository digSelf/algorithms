#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n, 0), b(m, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    // r -> a, l -> b
    int l, r;
    for (l = 0, r = 0; r <= n - 1; ++r) {
        while (l <= m - 1 && a[r] != b[l]) {
            ++l;
        }

        if (l >= m)
            break;

        // 如果等于了，则两个指针都要向下走, l <= m - 1 && a[r] == b[l]
        ++l;
    }

    if (r >= n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}