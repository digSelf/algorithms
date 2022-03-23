#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

const int kN = 1e5 + 5;
int heap[kN], size;

// 分别指向第k个插入的节点下标和当前节点是第几次插入的两张映射表
int k_to_index[kN], index_to_k[kN];

// 第m个插入的数
int m = 0; 

// 在交换两个节点的值的时候，另外的两张映射表也应该相应的进行交换
void heap_swap(int lhs, int rhs) {
    std::swap(k_to_index[index_to_k[lhs]], k_to_index[index_to_k[rhs]]);
    std::swap(index_to_k[lhs], index_to_k[rhs]);
    std::swap(heap[lhs], heap[rhs]);
}

// 向下调整。当节点idx中的值变大了，“体重”就变大了，因此需要向下沉
void down(int idx) {
    int temp = idx; 
    
    // 比较之前要保证左右儿子要存在
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

// 向上调整。当节点idx中的值变小了，“体重”变轻了，因此需要向上浮
void up(int idx) {
    int curr = idx;
    
    // 比较前要保证当前节点的父节点要存在
    while (curr / 2 && heap[curr] < heap[curr / 2]) {
        heap_swap(curr, curr / 2);
        curr = curr / 2;
    }
}

/**
 * insert, remove, modify, top, pop等堆操作均可以通过down和up操作组合而成 
 */

void insert(int x) {
    heap[++size] = x;
    index_to_k[size] = ++m;
    k_to_index[m] = size;

    up(size);
}

// 删除第k个插入的数
void remove(int k) {
    int idx = k_to_index[k];
    heap_swap(idx, size--);
    
    down(idx);
    up(idx);
}

// 修改第k个插入的数
void modify(int k, int x) {
    heap[k_to_index[k]] = x;
    down(k_to_index[k]);
    up(k_to_index[k]);
}

int top() {
    return heap[1];
}

void pop() {
    heap_swap(1, size--);
    
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