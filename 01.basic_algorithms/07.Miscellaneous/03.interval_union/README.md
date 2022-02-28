# 区间合并

给定 n 个区间 `[li,ri]`，要求合并所有有交集的区间。

注意如果在端点处相交，也算有交集。

输出合并完成后的区间个数。

例如：`[1,3]` 和`[2,6]`可以合并为一个区间 `[1,6]`。

## 输入格式

第一行包含整数 n。

接下来 n 行，每行包含两个整数 l 和 r。

## 输出格式

共一行，包含一个整数，表示合并区间完成后的区间个数。

## 数据范围

* `1 <= n <= 100000`
* `−10^9 <= li <= ri <= 10^9`

## 输入样例：

```
5
1 2
2 4
5 6
7 8
7 9
```

## 输出样例：

```
3
```

## 模板

```cpp
size_t count_intervals_after_union(vector<PII>& pairs) {
    // 如果没有或者只有一个元素，直接返回，本身就合并了
    if (pairs.size() <= 1)
        return pairs.size();
    
    // start和end标志着当前正在合并的区间的起始点和终点，为闭区间[start, end]
    int start = pairs[0].first, end = pairs[0].second;

    vector<PII> result;
    for (int i = 1; i < pairs.size(); ++i) {
        int left = pairs[i].first, right = pairs[i].second;

        if (end < left) { // 没有交集
            result.emplace_back(start, end);
            start = left, end = right;
        } else { // 有交集合并
            end = max(end, right);
        }
    }

    // 合并到最后只有一个区间了，补加入到结果集中
    result.emplace_back(start, end);

    return result.size();
}
```

