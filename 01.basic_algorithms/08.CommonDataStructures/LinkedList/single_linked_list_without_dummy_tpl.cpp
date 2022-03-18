#include <iostream>

using namespace std;

const int N = 1e5 + 5;

// head 是指针，指向头结点
// idx 是指针，指向当前空闲节点
int e[N], ne[N], head, idx;

void init() {
    head = -1;
    idx = 0;
}

void insert_at_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void insert_after(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];

    ne[k] = idx++;
}

void delete_after(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    init();
    int m; cin >> m;

    while (m --) {
        char op; cin >> op;
        if (op == 'H') {
            int x; cin >> x;
            insert_at_head(x);
        } else if (op == 'D') {
            int k; cin >> k;
            // 如果k是头结点，即：k == 0时，需要特殊判断一下
            if (!k) head = ne[head];
            else delete_after(k - 1);
        } else {
            int k, x; cin >> k >> x;
            insert_after(k - 1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i]) {
        cout << e[i] << " ";
    }
    cout << endl;

    return 0;
}