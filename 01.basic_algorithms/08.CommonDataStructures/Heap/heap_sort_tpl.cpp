#include <iostream>
#include <type_traits>

using std::cin;
using std::cout;
using std::endl;

const int kN = 1e5 + 5;
const int kRoot = 1;

int heap[kN];
int size;

void down(int idx) {
    int min_elem_idx = idx;
    // 求三者最小的那个元素的编号，因此两个if条件是并列的，不能使用else if
    // 否则逻辑就错误了
    if (2 * idx <= size && heap[2 * idx] < heap[min_elem_idx])
        min_elem_idx = 2 * idx;
    if (2 * idx + 1 <= size && heap[2 * idx + 1] < heap[min_elem_idx])
        min_elem_idx = 2 * idx + 1;

    if (min_elem_idx != idx) {
        std::swap(heap[min_elem_idx], heap[idx]);
        down(min_elem_idx);
    }
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; 
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> heap[i];

    // 初始化堆
    size = n;
    for (int i = n / 2; i; --i) {
        down(i);
    }
    
    // 开始堆排序
    while (m --) {
        cout << heap[kRoot] << " ";
        heap[kRoot] = heap[size --];
        down(kRoot);
    }

    return 0;
}
