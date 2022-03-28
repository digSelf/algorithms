/**
 * @file closed_hashing_tpl.cpp
 * @author digSelf (coding@algo.ac.cn)
 * @brief closed hashing, 又称Open Addressing，即：开放地址法
 * @version 0.1
 * @date 2022-03-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <cstdio>
#include <cstring>

const int N = 200003;

int get_lower_bound_prime(int x) {
    bool found = false;
    int n = x;
    while (true) {
        for (int i = 2; i * i <= n; ++i) {
            found = true;
            if (n % i == 0) {
                found = false;
                break;
            }
        }

        if (found) {
            return n;
        }

        ++n;
    }

    return 0;
}

int h[N];

// 只要null标识不在要出现的元素的值域范围内即可。
const int null = 0x3f3f3f3f;

void init() { memset(h, 0x3f, sizeof(int) * N); }

int get_hash_code(int x) { return (x % N + N) % N; }

// 如果x存在，则返回其下标，如果不存在，则返回适合插入该元素的下标
int find(int x) {
    int hash_code = get_hash_code(x);

    int curr = hash_code;
    // 看当前的坑位有没有人，如果有人则往下找；如果到头了，则从头开始查找
    while (h[curr] != null && h[curr] != x) {
        curr = (curr + 1) % N;
    }

    return curr;
}

void insert(int x) {
    int idx = find(x);

    if (h[idx] == null) {
        h[idx] = x;
    }
}

int main() {
    // std::printf("%d\n", get_lower_bound_prime(N));
    init();
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if (op[0] == 'I') {
            insert(x);
        } else {
            int idx = find(x);

            printf("%s\n", h[idx] == x ? "Yes" : "No");
        }
    }
    return 0;
}