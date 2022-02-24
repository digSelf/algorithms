# 相关问题

## [560. 和为 K 的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

三种做法：两种n^2复杂度的，一种使用缓存降低时间复杂度。

**NOTICE** 对于`unordered_map`的值初始化问题：

* `int/double` - 0
* `string` - ""
* `bool` - false
* 结构体则是内部各字段的值的初始化

## [974. 和可被 K 整除的子数组](https://leetcode-cn.com/problems/subarray-sums-divisible-by-k/)

## [523. 连续的子数组和](https://leetcode-cn.com/problems/continuous-subarray-sum/)

## [112. 路径总和](https://leetcode-cn.com/problems/path-sum/)

## [113. 路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/)

## [437. 路径总和 III](https://leetcode-cn.com/problems/path-sum-iii/)



**NOTICE** 遍历向上回溯时，以当前节点为根的子树上的计算结果不应该影响到向上回溯后的兄弟子树上的结果，因此需要取消掉在当前子树上的运算结果，因此在遍历当前节点的左右子树前所做的可能影响到兄弟子树的操作都需要在回溯前进行撤销。



# 附录

## 前缀和

其他同学写的总结，很不错：[得了，前缀和被我一下给扒光了 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/circle/article/EQWhUd/)

