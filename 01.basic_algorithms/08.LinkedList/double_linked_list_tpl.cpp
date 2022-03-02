#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int e[N], l[N], r[N], curr;

const int head = 0, tail = 1;

void init() {
    r[head] = tail;
    l[tail] = head;
    
    curr = tail + 1;
}

void insert(int k, int x) {
    e[curr] = x;
    
    r[curr] = r[k];
    l[curr] = k;
    
    l[r[k]] = curr;
    r[k] = curr ++;
}

void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main() {
    int m; cin >> m;
    
    init();
    while (m--) {
        string op;
        int k, x;

        cin >> op;
        if (op == "L") {
            cin >> x;
            insert(head, x);
        } else if (op == "R") {
            cin >> x;
            insert(l[tail], x);
        } else if (op == "D") {
            cin >> k;
            remove(k + 1);
        } else if (op == "IL") {
            cin >> k >> x;
            insert(l[k + 1], x);
        } else { // IR
            cin >> k >> x;
            insert(k + 1, x);
        }
    }
    
    for (int i = r[head]; i != tail; i = r[i]) {
        cout << e[i] << " ";
    }
    cout << endl;
    
    return 0;
}