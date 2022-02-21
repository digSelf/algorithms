#include <cstdio>
#include <vector>

using namespace std;

// 找到满足二分性质的数组的指定元素的左边界和右边界
// 该数列的性质为单调不减数列
void binarySearch(const vector<int>& arr, int start, int end, int k) {
    int left = start, right = end;
    
    // 找左边界
    // 退出条件是：left >= right，left的值能够大于right吗？不能的，最多是等于
    // 为什么？因为left和right的更新是由mid来进行更新的，而mid in [left, right]中，不会超出该区间
    // 所以退出条件一定是left == right时退出
    // 注意，不能写成`left <= right`的形式，因为可能会造成死循环
    while (left < right) {
        int mid = (left + right) >> 1; // 注意是向下取整
        
        if (arr[mid] >= k) {
            // [left, right]
            right = mid;
        } else {
            // arr[mid] < k
            left = mid + 1;
        }
    }
    
    if (arr[left] == k) {
        printf("%d", left);
    } else {
        printf("-1 -1\n");
        return;
    }
    
    // 找右边界
    left = start, right = end;
    while (left < right) {
        int mid = (left + right + 1) >> 1;
        
        if (arr[mid] <= k) {
            // 如果mid不补偿加1，则由于mid是向下取整，则容易造成死循环，所以要补偿加1，下整转上整
            // 取整公式，a/b的上整等于(a + b - 1) / b，当b为2时，则公式变为(a + 2 - 1)/ 2 = (a + 1) / 2
            // 这就是这个补偿加1的来历
            left =  mid; 
        } else {
            // > k
            right = mid - 1;
        }
    }
    
    if (arr[left] == k) {
        printf(" %d\n", left);
    }
}

int main() {
    int n = 0, q = 0;
    scanf("%d%d", &n, &q);
    
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        scanf("%d", &tmp);
        nums.push_back(tmp);
    }
    
    vector<int> Q;
    for (int i = 0; i < q; ++i) {
        int tmp = 0;
        scanf("%d", &tmp);
        Q.push_back(tmp);
    }
    
    for (int i = 0; i < q; ++i) {
        binarySearch(nums, 0, nums.size() - 1, Q[i]);
    }
    
    return 0;
}