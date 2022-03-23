#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

const int kN = 1e5 + 5;
int heap[kN], size; // size从下标1开始存储，即：先自增后存储
int m = 0; // 第m个插入的数

int k_to_index[kN];  // 指向第k个插入的节点下标
int index_to_k[kN];  // 指向当前节点是第几次插入的

void heap_swap(int lhs, int rhs) {
    std::swap(k_to_index[index_to_k[lhs]], k_to_index[index_to_k[rhs]]);
    std::swap(index_to_k[lhs], index_to_k[rhs]);
    std::swap(heap[lhs], heap[rhs]);
}

// 向下调整
void down(int idx) {
    int temp = idx; 
    if (2 * idx <= size && heap[2 * idx] < heap[temp]) {
        temp = 2 * idx;
    }

    if (2 * idx + 1 <= size && heap[2 * idx + 1] < heap[temp]) {
        temp = 2 * idx + 1;
    }

    if (temp != idx) {
        heap_swap(temp, idx);
        down(temp);
    }
}

// 向上调整
void up(int idx) {
    int curr = idx;
    while (curr / 2 && heap[curr] < heap[curr / 2]) {
        heap_swap(curr, curr / 2);
        curr = curr / 2;
    }
}

void insert(int x) {
    ++size, ++m;
    heap[size] = x;
    k_to_index[m] = size;
    index_to_k[size] = m;
    
    up(size);
}

void remove(int k) {
    int idx = k_to_index[k];
    heap_swap(idx, size);
    size--;
    
    down(idx);
    up(idx);
}

void modify(int k, int x) {
    heap[k_to_index[k]] = x;
    down(k_to_index[k]);
    up(k_to_index[k]);
}

int top() {
    return heap[1];
}

void pop() {
    heap_swap(1, size);
    --size;

    down(1);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    while (n --) {
        string op;  cin >> op;
        if (op == "I") {
            int x; cin >> x;
            insert(x);
        } else if (op == "D") {
            int k; cin >> k;
            remove(k);
        } else if (op == "C") {
            int k, x; cin >> k >> x;
            modify(k, x);
        } else if (op == "PM") {
            cout << top() << endl;
        } else { // op == "DM"
            pop();
        }
    }

    return 0;
}