#include <iostream>

using namespace std;

// head 表示头结点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针是多少
// idx 指向当前尚未分配的节点的位置
const int N = 1e5 + 5;
int head, e[N], ne[N], idx;

void init() {
    // 先分配一个哨兵节点
    head = idx;
    ne[head] = -1;
    
    idx ++; // 构造哨兵节点
}

void add_to_head(int x) {
    e[idx] = x;
    ne[idx] = ne[head];
    ne[head] = idx++;
}

void remove(int k) {
    ne[k] = ne[ne[k]];
}

void add(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

int main()
{
    init();

    int m;
    cin >> m;
    while (m --) {
        char op;
        int k, x;

        cin >> op;
        switch (op)
        {
        case 'H':
            cin >> x;
            add_to_head(x);
            break;
        case 'I':
            cin >> k >> x;
            add(k, x);
            break;
        case 'D':
            cin >> k;
            if (k == 0) head = ne[head];
            else remove(k);
            break;
        default:
            break;
        }
    }

    // head 所指向的是哨兵节点
    for (int i = ne[head]; i != -1; i = ne[i]) {
        cout << e[i] << " ";
    }
    cout << endl;
    return 0;
}