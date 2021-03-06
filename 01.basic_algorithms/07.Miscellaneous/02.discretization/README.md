# 离散化

**离散化的本质**：将给定数值作为**“散列函数”**的key，返回其下标索引值。



**离散化的应用时机**：对于给定数组，由于数组中的数据的范围较大，当需要使用数组中的元素作为某一个数组的下标进行使用的时候，就需要进行离散化。



**离散化的目标**：将离散化的各个元素的值映射到与数组内所保存的元素的个数相同的数组中去。

```plain
1 3 5 7 9 11 13 15 17
---------------------
0 1 2 3 4 5  6  7  8 
```

问题转化为，给定数组中的数值`x`，从去重后的有序数组中查找出第一个不小于`x`的元素所对应的下标位置，这个位置就是离散化后的索引。



## 离散化操作步骤

* 由于待离散化的数据可能有重复，因此需要去重。
* 使用二分查找计算离散化后的值。



## `cpp`去重模板

```cpp
// std::vector<int> list;
// 先排序，由于std::unique函数只对有序数组有用，故得先排序
std::list(list.begin(), list.end());
list.erase(std::unique(list.begin(), list.end()), list.end());
```

## 例题

### 区间和

假定有一个无限长的数轴，数轴上每个坐标上的数都是 0。

现在，我们首先进行 n 次操作，每次操作将某一位置 x 上的数加 c。

接下来，进行 m 次询问，每个询问包含两个整数 l 和 r，你需要求出在区间 `[l,r]` 之间的所有数的和。

#### 输入格式

第一行包含两个整数 n 和 m。

接下来 n 行，每行包含两个整数 x 和 c。

再接下来 m 行，每行包含两个整数 l 和 r。

#### 输出格式

共 m 行，每行输出一个询问中所求的区间内数字和。

#### 数据范围

* `−10^9 <= x <= 10^9`
* `1 <= n,m <= 10^5`
* `−10^9 <= l <= r <= 10^9`
* `−10000 <= c <= 10000`

#### 输入样例：

```
3 3
1 2
3 6
7 5
1 3
4 6
7 8
```

#### 输出样例：

```
8
0
5
```





