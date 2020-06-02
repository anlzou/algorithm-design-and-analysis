<!--
 * @Date        : 2020-05-02 20:37:47
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-06-02 16:06:51
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

#2
对于给定的含有 n 个元素的有序序列，求这个序列中某个元素的下标。
```

## 思路
#1 

对于无序序列 a[low...high]，采用分治法求最大元素 max1 和次大元素 max2 的过程如下：
1. 若 a[low...high] 中只有一个元素，则 max1 = a[low]，max2 = -INF(-∞)。
2. 若 a[low...high] 中只有两个元素，则 max1 = max{a[low], a[high]}，max2 = min{a[low], a[high]}。
3. 若 a[low...high] 中有两个以上元素，按中间位置 min = (low+high)/2 划分为 a[low...mid] 和 a[mid+1...high] 两个区间（注意左区间包含 a[mid]元素）。求出左区间的最大元素 lmax1 和次大元素 lmax2，求出右区间的最大元素 rmax1 和次大元素 rmax2。
4. 若 lmax1 > rmax1，则 max1 = lmax1，max2 = max{lmax2, rmax1}；否则 max1 = rmax1，max2 = max{lmax1, rmax2}。

#2

**折半查找**又称二分查找，它是一种效率较高的查找方d法。但是折半查找要求查找列中的元素是有序的，为了简单，假设是递增有序的（前提是进行排序）。

折半查找的基本思路：设 a[low...high] 是当前的查找区间，首先确定该区间的中点位置 mid = floor(low+high/2)；然后将待查的 k 值与 a[mid].key 比较。
1. 若 k == a[mid].key，则查找成功并返回该元素的物理下标。
2. 若 k < a[mid]，则由表的序列性可知 a[mid...high] 均大于 k，因此若表中存在关键字等于 K 的元素，则该元素必定位于左子表 a[low...mid-1] 中，故新的查找区间是左子表 a[low...mid-1]。
3. 若 k > a[mid]，则要查找的 k 必定位于右子表 a[mid+1...high] 中，即新的查找区间是右子表 a[mid+1...high]。
4. 下一次查找是针对新的查找区间进行的。因此可以从初始的查找区间 a[0...n-1] 开始，每经过一次与当前查找区间的中点位置上的关键字比较就确定查找是否成功，不成功则当前的查找区间缩小一半。重复这一过程，直到找到关键字为 k 的元素，或者直到当前的查找区间为空（即查找失败）时为止。 


## 代码
#1、2

[exp3-3.cpp](./code/exp3-3.cpp)

## 复杂度分析

#1
- 时间复杂度：O(n)
- 空间复杂度：O(n)

#2
- 空间复杂度：O(log2n)
- 空间复杂度：O(n)