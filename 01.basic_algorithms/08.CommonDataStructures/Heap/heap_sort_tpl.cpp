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
    // 从i = int(n / 2)的地方开始进行调整，即：从倒数第二层开始进行调整
    // 此时由于叶子层（倒数第一层）都是单一元素，逻辑上各个都是最小堆
    // 因此从倒数第二层开始调整，直到堆顶即可，时间复杂度为O(n * x), 其中x < 1
    // 因为x最后是等比数列1 / 2 + 1 / 4 + ... + 1 / (2^n), 这个求和是小于1的
    // 因此这个初始化堆的时间复杂度是小于O(n)的
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
