# 相关问题

## [560. 和为 K 的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的连续子数组的个数。

 

**示例 1**：

> 输入：nums = [1,1,1], k = 2
> 输出：2

**示例 2**：

> 输入：nums = [1,2,3], k = 3
> 输出：2

**提示**：

* `1 <= nums.length <= 2 * 10^4`
* `-1000 <= nums[i] <= 1000`
* `-10^7 <= k <= 10^7`



三种做法：两种n^2复杂度的，一种使用缓存降低时间复杂度。

**NOTICE** 对于`unordered_map`的值初始化问题：

* `int/double` - 0
* `string` - ""
* `bool` - false
* 结构体则是内部各字段的值的初始化

## [974. 和可被 K 整除的子数组](https://leetcode-cn.com/problems/subarray-sums-divisible-by-k/)

给定一个整数数组 nums 和一个整数 k ，返回其中元素之和可被 k 整除的（连续、非空） 子数组 的数目。

子数组 是数组的 连续 部分。

 

**示例 1**：

输入：nums = [4,5,0,-2,-3,1], k = 5
输出：7
解释：
有 7 个子数组满足其元素之和可被 k = 5 整除：
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

**示例 2**:

输入: nums = [5], k = 9
输出: 0

**提示**:

* `1 <= nums.length <= 3 * 10^4`
* `-10^4 <= nums[i] <= 10^4`
* `2 <= k <= 10^4`



## [523. 连续的子数组和](https://leetcode-cn.com/problems/continuous-subarray-sum/)

## [112. 路径总和](https://leetcode-cn.com/problems/path-sum/)

## [113. 路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/)

## [437. 路径总和 III](https://leetcode-cn.com/problems/path-sum-iii/)



**NOTICE** 遍历向上回溯时，以当前节点为根的子树上的计算结果不应该影响到向上回溯后的兄弟子树上的结果，因此需要取消掉在当前子树上的运算结果，因此在遍历当前节点的左右子树前所做的可能影响到兄弟子树的操作都需要在回溯前进行撤销。



# 附录

## 前缀和

其他同学写的总结，很不错：[得了，前缀和被我一下给扒光了 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/circle/article/EQWhUd/)

