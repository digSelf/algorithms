#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 5;
int stk[N], esp, ebp;

bool empty() {
    return esp == ebp;
}

void push(int x) {
    stk[++esp] = x;
}

void pop() {
    esp--;
}

int top() {
    return stk[esp];
}

int main() {
    int m; cin >> m;
    
    while (m --) {
        string op;
        int x;
        
        cin >> op;
        if (op == "push") {
            cin >> x;
            push(x);
        } else if (op == "pop") {
            pop();
        } else if (op == "empty") {
            if (empty()) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else { //query
            cout << top() << endl;
        }
    }
    
    return 0;
}