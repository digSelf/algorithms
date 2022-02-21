# 归并排序相关题目

## [912. 排序数组](https://leetcode-cn.com/problems/sort-an-array/)

### 题目描述

给你一个整数数组 `nums`，请你将该数组升序排列。

### 示例 1

> 输入：nums = [5,2,3,1]
> 输出：[1,2,3,5]

### 示例 2

> 输入：nums = [5,1,1,2,0,0]
> 输出：[0,0,1,1,2,5]

### 提示

* `1 <= nums.length <= 5 * 10^4` 

* `-5 * 10^4 <= nums[i] <= 5 * 10^4`

### 对应的cpp文件

* merge_sort_template

## [剑指 Offer 51. 数组中的逆序对](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)

### 题目描述

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

### 示例

> **输入**: [7,5,6,4]
> **输出**: 5

### 限制

* `0 <= 数组长度 <= 50000`

### 对应的cpp文件

* `51.reverse_pairs`

## [493. 翻转对](https://leetcode-cn.com/problems/reverse-pairs/)

### 题目描述

给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。你需要返回给定数组中的重要翻转对的数量。



### 示例

> **输入**: [1,3,2,3,1]
> **输出**: 2
> 
> **输入**: [2,4,3,5,1]
> **输出**: 3



### 注意

1. 给定数组的长度不会超过`50000`。

2. 输入数组中的所有数字都在32位整数的表示范围内。

### 对应的cpp文件

`493.reverse_pairs`