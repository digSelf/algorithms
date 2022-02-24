// 这个版本使用的是数组而不是容器来进行实现

#include <cstdio>

const int N = 100000 + 5;
int nums[N];
int prefix[N];

void calc_prefix_sum(int nums[], int n, int result[]) {
    for (int i = 1; i <= n; ++i) {
        result[i] = result[i - 1] + nums[i];
    }
}

int main() {
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) 
        scanf("%d", &nums[i]);
    
    calc_prefix_sum(nums, n, prefix);

    while (m --) {
        int l = 0, r = 0;
        scanf("%d%d", &l, &r);

        printf("%d\n", prefix[r] - prefix[l - 1]);
    }

    return 0;
}