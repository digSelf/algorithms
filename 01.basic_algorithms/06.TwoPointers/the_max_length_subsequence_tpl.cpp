#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    int length = 0;
    unordered_map<int, int> elem_to_count;
    for (int l = 0, r = 0; r < n; ++r) {
        elem_to_count[arr[r]] ++;
        while (l <= r && elem_to_count[arr[r]] > 1) { // 加进来的元素导致了重复
            elem_to_count[arr[l++]] --;
        }
        
        // 符合条件，可以记录解
        length = max(length, r - l + 1);
    }
    
    printf("%d\n", length);
    
    return 0;
}