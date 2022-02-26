# 双指针算法

## 双指针枚举区间

先枚举终点，再枚举起点；终点和起点的位置可以相等，因为区间内可以有一个元素。



```cpp
for (int r = 0; r < n; ++r) {
    for (int l = 0; l <= r; ++l) {
        if (check(l, r)) {
            // blablabla...
        }
    }
}
```

