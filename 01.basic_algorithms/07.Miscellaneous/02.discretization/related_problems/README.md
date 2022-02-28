# 相关例题

## [1331. 数组序号转换](https://leetcode-cn.com/problems/rank-transform-of-an-array/)

**备注** 离散化索引模板题，可以使用`stl`中的`lower_bound`来构造一个更简易的模板：

```cpp
// 初始化一个存放离散化映射关系的索引数组，arr是所有可能出现的key的集合
vector<int> indices(arr);

// cpp排序去重模板
sort(indices.begin(), indices.end());
indices.erase(unique(indices.begin(), indices.end()), indices.end());

// 获取原数组中各个值映射之后的索引值，并存放在result中
vector<int> result;
for (auto value : arr) {
    // 找的是分界点的最左边界，即：xxoo中的第一次出现o的下标值，也成为不小于给定值value的最小下标
    // lower_bound返回的是一个迭代器（类似于指针）
    // 根据题目的不同，可以加1也可以不加1
    int index = lower_bound(indices.begin(), indices.end(), value) - indices.begin() + 1;
    result.push_back(index);
}
```

## [1854. 人口最多的年份](https://leetcode-cn.com/problems/maximum-population-year/)

* 差分
* 离散化

两种思路均可以实现
