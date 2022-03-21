#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int kN = 1e5 + 5;

int parent_indices[kN];

// 找到idx所指向的节点的祖宗节点，并做路径压缩
int find(int idx) {
    if (parent_indices[idx] != idx) 
        // 做路径压缩，如果此时还未到根节点，继续向父亲节点的父亲节点查找
        // 并将当前节点的父亲节点指向为父亲节点的父亲节点
        parent_indices[idx] = find(parent_indices[idx]);
    return parent_indices[idx];
}

int main(int argc, char *argv[])
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        parent_indices[i] = i;
    }

    while (m --) {
        char op;
        int a, b;
        cin >> op >> a >> b;

        if (op == 'M') {
            parent_indices[find(a)] = find(b);
        } else {
            if (find(a) == find(b)) {
                cout << "Yes" << endl;
                continue;
            }

            cout << "No" << endl;
        }
    }
    return 0;
}
