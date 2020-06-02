<!--
 * @Date        : 2020-05-02 20:37:47
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-06-02 15:18:41
 * @FilePath    : \algorithm-design\chapters\chapter03-divide-and-conquer\test8-3.md
 * @Describe    : 
 -->
 
## 题目地址
3.2 求解查找问题

## 题目描述

问题：
```
#1
查找最大和次大元素

#2
折半查找

#3
寻找一个序列中第 k 小的元素

#4
寻找两个等长有序序列的中位数
```
问题描述：
```
#1
对于给定的含有 n 个元素的无序序列，求这个序列中最大和次大的两个不同元素。
```

## 思路
#1 

对于无序序列 a[low...high]，采用分治法求最大元素 max1 和次大元素 max2 的过程如下：
1. 若 a[low...high] 中只有一个元素，则 max1 = a[low]，max2 = -INF(-∞)。
2. 若 a[low...high] 中只有两个元素，则 max1 = max{a[low], a[high]}，max2 = min{a[low], a[high]}。
3. 若 a[low...high] 中有两个以上元素，按中间位置 min = (low+high)/2 划分为 a[low...mid] 和 a[mid+1...high] 两个区间（注意左区间包含 a[mid]元素）。求出左区间的最大元素 lmax1 和次大元素 lmax2，求出右区间的最大元素 rmax1 和次大元素 rmax2。
4. 若 lmax1 > rmax1，则 max1 = lmax1，max2 = max{lmax2, rmax1}；否则 max1 = rmax1，max2 = max{lmax1, rmax2}。


## 代码
#1
[exp3-3.cpp](./code/exp3-3.cpp)

## 复杂度分析

#1、2
- 平均时间复杂度：O(nlog2n)
- 空间复杂度：O(n)