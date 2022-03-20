#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

const int N = 1e5 + 5;

const int head = 0, tail = 1;
int e[N], l[N], r[N], idx;

void init() {
    // head, tail 所指向的两个节点是哨兵节点
    r[head] = tail;
    l[tail] = head;

    // 从下标为2的地方正式开始存储数据
    idx = 2;
}

// 将head, tail, idx, k均理解为指针，不理解为下标就更好理解了
void insert_after(int k, int x) { 
    e[idx] = x;
    l[idx] = k, r[idx] = r[k];

    l[r[k]] = idx, r[k] = idx ++;
}

void remove_at(int k) {
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    init();

    int m; cin >> m;
    while (m --) {
        string op; cin >> op;
        int k, x;
        if (op == "L") {
            cin >> x;
            insert_after(head, x);
        } else if (op == "R") {
            cin >> x;
            insert_after(l[tail], x);
        } else if (op == "D") {
            cin >> k;
            // 由于题目的下标是从1开始的，而我们存储的数据是从下标为2的节点开始存储的
            // 因此需要进行调整
            remove_at(k + 1);
        } else if (op == "IL") {
            cin >> k >> x;
            insert_after(l[k + 1], x);
        } else { // op == "IR"
            cin >> k >> x;
            insert_after(k + 1, x);
        }
    }

    for (int i = r[head]; i != tail; i = r[i]) {
        cout << e[i] << " ";
    }
    cout << endl;

    return 0;
}