# 相关例题

## [1331. 数组序号转换](https://leetcode-cn.com/problems/rank-transform-of-an-array/)

给你一个整数数组 arr ，请你将数组中的每个元素替换为它们排序后的序号。

序号代表了一个元素有多大。序号编号的规则如下：

* 序号从 1 开始编号。
* 一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。
* 每个数字的序号都应该尽可能地小。

**示例 1**：

> 输入：arr = [40,10,20,30]
> 输出：[4,1,2,3]
> 解释：40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30 是第三小的数字。

**示例 2**：

> 输入：arr = [100,100,100]
> 输出：[1,1,1]
> 解释：所有元素有相同的序号。

**示例 3**：

> 输入：arr = [37,12,28,9,100,56,80,5,12]
> 输出：[5,3,4,2,8,6,7,1,3]

**提示**：

* `0 <= arr.length <= 10^5`
* `-10^9 <= arr[i] <= 10^9`



**备注** 离散化索引模板题，可以使用`stl`中的`lower_bound`来构造一个更简易的模板，而不用自己每次都要写二分查找：

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

给你一个二维整数数组 logs ，其中每个`logs[i] = [birthi, deathi]` 表示第 i 个人的出生和死亡年份。

年份 x 的 人口 定义为这一年期间活着的人的数目。第 i 个人被计入年份 x 的人口需要满足：x 在闭区间 `[birthi, deathi - 1]` 内。注意，人不应当计入他们死亡当年的人口中。

返回 人口最多 且 最早 的年份。

 

**示例 1**：

> 输入：logs = [[1993,1999],[2000,2010]]
> 输出：1993
> 解释：人口最多为 1 ，而 1993 是人口为 1 的最早年份。

**示例 2**：

> 输入：logs = [[1950,1961],[1960,1971],[1970,1981]]
> 输出：1960
> 解释： 
> 人口最多为 2 ，分别出现在 1960 和 1970 。
> 其中最早年份是 1960 。

**提示**：

* `1 <= logs.length <= 100`

* `1950 <= birthi < deathi <= 2050`
