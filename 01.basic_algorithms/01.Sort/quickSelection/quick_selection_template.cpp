#include <bits/stdc++.h>

const int N = 1e5 + 5;
int arr[N];

// arr, [start, end], k
int quickSelection(int *arr, int start, int end, int k) {
    // exit condition
    if (start >= end) 
        return arr[start];

    int left = start - 1, right = end + 1;
    int pivot = arr[(left + right) >> 1];

    while (left < right) {
        while (arr[++left] < pivot); // >=
        while (arr[--right] > pivot); // <=

        if (left < right) {
            std::swap(arr[left], arr[right]);
        }
    }

    if (k <= right - start + 1) {
        return quickSelection(arr, start, right, k);
    } else {
        return quickSelection(arr, right + 1, end, k - right + start - 1);
    }
}

int main() {
    int n = 0, k = 0;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    printf("%d\n", quickSelection(arr, 0, n - 1, k));

    return 0;
}