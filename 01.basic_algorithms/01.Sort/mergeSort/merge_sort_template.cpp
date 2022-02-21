#include <bits/stdc++.h>

const int N = 1e5 + 5;
int nums[N];
int tmp_arr[N]; // temp array for merging two ordered arrays.

void mergeSort(int *arr, int start, int end) {
    if (start >= end) return;
    
    int mid = (start + end) >> 1;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    
    // merge
    int left = start, right = mid + 1;
    int i = 0;
    for (; left <= mid && right <= end; ++i) {
        if (arr[left] < arr[right]) {
            tmp_arr[i] = arr[left];
            left++;
        } else {
            tmp_arr[i] = arr[right];
            right++;
        }
    }
    
    while (left <= mid) {
        tmp_arr[i++] = arr[left++];
    }
    
    while (right <= end) {
        tmp_arr[i++] = arr[right++];
    }
    
    for (int j = 0; j < i; ++j) {
        arr[start + j] = tmp_arr[j];
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }
    
    mergeSort(nums, 0, n - 1);
    
    for (int i = 0; i < n; ++i) {
        printf("%d%c", nums[i], " \n"[i == n - 1]);
    }
    
    return 0;
}