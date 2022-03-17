#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5;
const int M = 1e6 + 5;

int ne[N];
char p[N], s[M];

void get_next(int n) {
    // 注意计算next数组时下标是从第二个开始
    // 因为next[1] 一定是为0的，因为在计算next数组时，前缀和后缀的长度不能等于子串的长度
    // 否则的话前缀和后缀是一定相等的
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j && p[i] != p[j + 1])
            j = ne[j];

        if (p[i] == p[j + 1])
            ++j;
        ne[i] = j;
    }
}


void match(int n, int m) {
    // 开始匹配
    for (int i = 1, j = 0; i <= m; ++i) {
        while (j && s[i] != p[j + 1])
            j = ne[j];

        if (s[i] == p[j + 1]) {
            ++j;
        }
       
        if (j == n) {
            cout << i - n << " ";
            j = ne[j];
        } 
    }
    return;
}

int main(int argc, char *argv[])
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    // 由于计算next数组时，使用了哨兵，因此存储的位置是从下标1开始的
    int n, m;
    cin >> n >> (p + 1) >> m >> (s + 1);
    // 计算ne数组;
    get_next(n);

    match(n, m);
    cout << endl;
    return 0;
}
