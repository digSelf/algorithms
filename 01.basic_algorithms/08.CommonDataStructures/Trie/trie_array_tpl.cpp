#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int N = 1e5 + 5;

// idx == 0是空节点也是根节点
// idx 是一个指针，指向当前空闲节点
int son[N][26], cnt[N], idx;

char str[N];

void insert(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        // 离散化映射，将英文字母的ascii转变为从0开始到25的离散值
        int u = str[i] - 'a';
        if (!son[p][u]) // 如果当前节点是空，则先分配节点给它，并给值
            son[p][u] = ++idx;
        
        // 然后移动到刚刚插入的这个节点上去
        p = son[p][u];
    }

    // 做标记，并统计以p指针指向的字符为结尾的字符串的个数
    cnt[p] ++;
}

int query(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int u = str[i] - 'a';
        // 如果当前节点不存在，证明当前不包含该字符，因此肯定不存在这个字符串
        // 直接返回个数为0
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }

    return cnt[p];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    while (n --) {
        char op;
        cin >> op >> str;
        
        if (op == 'I') {
            insert(str);
        } else {
            cout << query(str) << endl;
        }
    }

    return 0;
}