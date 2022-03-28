#include <cstdio>
#include <cstring>

const int N = 100003;

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

// Open Hashing, 拉链法解决冲突。其本质就是开一个指针数组，数组中保存的是出现冲突的单链表的指针
// 本模板使用的是数组模拟的单链表
int h[N], e[N], ne[N], idx;

void init() {
    std::memset(h, -1, sizeof(h));
}

int get_hash_code(int x) {
    return (x % N + N) % N;
}

void insert(int x) {
    int hash_code = get_hash_code(x);

    e[idx] = x, ne[idx] = h[hash_code];
    h[hash_code] = idx++;
}

bool find(int x) {
    int hash_code = get_hash_code(x);

    for (int i = h[hash_code]; i != -1; i = ne[i]) {
        if (e[i] == x)
            return true;
    }

    return false;
}

int main() {
    init();
    int n; scanf("%d", &n);

    while (n --) {
        char op[2]; 
        int x;
        scanf("%s%d", op, &x);

        if (op[0] == 'I') {
            insert(x);
        } else {
            printf("%s\n", find(x) == true ? "Yes" : "No");
        }
    }
    
    return 0;
}