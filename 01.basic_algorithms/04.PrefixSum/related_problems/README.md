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

> 输入：nums = [4,5,0,-2,-3,1], k = 5
> 输出：7
> 解释：
> 有 7 个子数组满足其元素之和可被 k = 5 整除：
> [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

**示例 2**:

> 输入: nums = [5], k = 9
> 输出: 0

**提示**:

* `1 <= nums.length <= 3 * 10^4`
* `-10^4 <= nums[i] <= 10^4`
* `2 <= k <= 10^4`



## [523. 连续的子数组和](https://leetcode-cn.com/problems/continuous-subarray-sum/)

给你一个整数数组 nums 和一个整数 k ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：

子数组大小 至少为 2 ，且
子数组元素总和为 k 的倍数。
如果存在，返回 true ；否则，返回 false 。

如果存在一个整数 n ，令整数 x 符合 x = n * k ，则称 x 是 k 的一个倍数。0 始终视为 k 的一个倍数。

 

**示例 1**：

> 输入：nums = [23,2,4,6,7], k = 6
> 输出：true
> 解释：[2,4] 是一个大小为 2 的子数组，并且和为 6 。

**示例 2**：

> 输入：nums = [23,2,6,4,7], k = 6
> 输出：true
> 解释：[23, 2, 6, 4, 7] 是大小为 5 的子数组，并且和为 42 。 
> 42 是 6 的倍数，因为 42 = 7 * 6 且 7 是一个整数。

**示例 3**：

> 输入：nums = [23,2,6,4,7], k = 13
> 输出：false


提示：

* `1 <= nums.length <= 10^5`
* ``0 <= nums[i] <= 10^9`
* `0 <= sum(nums[i]) <= 2^31 - 1`
* `1 <= k <= 2^31 - 1`



## [112. 路径总和](https://leetcode-cn.com/problems/path-sum/)

给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。

叶子节点 是指没有子节点的节点。

![](https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg)

**示例1**

> 输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
> 输出：true
> 解释：等于目标和的根节点到叶节点路径如上图所示。

![](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)

**示例2**

> 输入：root = [1,2,3], targetSum = 5
> 输出：false
> 解释：树中存在两条根节点到叶子节点的路径：
> (1 --> 2): 和为 3
> (1 --> 3): 和为 4
> 不存在 sum = 5 的根节点到叶子节点的路径。

**示例 3**：

> 输入：root = [], targetSum = 0
> 输出：false
> 解释：由于树是空的，所以不存在根节点到叶子节点的路径。


提示：

* 树中节点的数目在范围 [0, 5000] 内
* `-1000 <= Node.val <= 1000`
* `-1000 <= targetSum <= 1000`



## [113. 路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/)

给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

 ![](https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg)  

**示例 1** ：

> 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
> 输出：[[5,4,11,2],[5,8,4,5]]

![](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)

**示例 2**：

> 输入：root = [1,2,3], targetSum = 5
> 输出：[]

**示例 3**：

> 输入：root = [1,2], targetSum = 0
> 输出：[]

**提示**：

* 树中节点总数在范围 [0, 5000] 内
* `-1000 <= Node.val <= 1000`
* `-1000 <= targetSum <= 1000`



## [437. 路径总和 III](https://leetcode-cn.com/problems/path-sum-iii/)

给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。



![](https://assets.leetcode.com/uploads/2021/04/09/pathsum3-1-tree.jpg)

**示例 1**：

> 输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
> 输出：3
> 解释：和等于 8 的路径有 3 条，如图所示。

**示例 2**：

> 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
> 输出：3

**提示:**

* 二叉树的节点个数的范围是 [0,1000]
* `-10^9 <= Node.val <= 10^9 `
* `-1000 <= targetSum <= 1000`



**NOTICE** 遍历向上回溯时，以当前节点为根的子树上的计算结果不应该影响到向上回溯后的兄弟子树上的结果，因此需要取消掉在当前子树上的运算结果，因此在遍历当前节点的左右子树前所做的可能影响到兄弟子树的操作都需要在回溯前进行撤销。



# 附录

## 前缀和

其他同学写的总结，很不错：[得了，前缀和被我一下给扒光了 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/circle/article/EQWhUd/)

