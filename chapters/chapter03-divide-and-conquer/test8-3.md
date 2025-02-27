<!--
 * @Date        : 2020-05-02 20:37:47
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-06-02 23:30:47
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

#3
对于给定的含有 n 个元素的无序序列，求这个序列中第 k(1<=k<=n) 小的元素。

#4
对于一个长度为 n 的有序序列（假设均为升序序列）a[0...n-1]，处于中间位置的元素称为 a 的中位数。
两个等长有序序列的中位数是含它们所有元素的有序序列的中位数。设计一个算法求给定的两个有序序列的中位数。
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

#3

假设无序序列存放在 a[0...n-1] 中，若将 a 递增排序，则第 k 小的元素为 a[k-1]。采用类似快速排序的思想。

对于无序序列 a[s...t]，在其中查找第 k 小的元素的过程如下：
1. 若 s >= t，即其中只有一个元素或没有任何元素，如果 s = t 且 s = k-1，表示只有一个元素且 a[k-1] 就是要求的结果，返回 a[k-1]。
2. 若 s < t，表示该序列中有两个或两个以上的元素，以基准为中心将其划分为 a[s...i-1] 和 a[i+1...t] 两个子序列，基准 a[i] 已归位（快速排序），a[s...i-1] 中的所有元素均小于 a[i]，a[i+1...t] 中的所有元素均大于 a[i]，也就是说 a[i] 是第 i+1 小的元素，有3种情况：
   - 若 k-1 = i，a[i] 即为所求，返回 a[i]。
   - 若 k-1 < i，第 k 小的元素应在 a[s...i-1] 子序列中，递归在该序列中求解并返回其结果。
   - 若 k-1 > i，第 k 小的元素应在 a[i+1...t] 子序列中，递归在该序列中求解并返回其结果。

#4

对于含有 n 个元素的有序序列 a[s...t]，当 n 为奇数时，中位数出现在 m = floor((s+t)/2) 处；当 n 为偶数时，中位数下标有 m = floor((s+t)/2) （下中位）和 m = floor((s+t)/2)+1 （上中位）两个。为了简单，这里仅考虑中位数下标为 m = floor((s+t)/2)。

采用二分法求含有 n 个有序元素的序列 a、b 的中位数的过程如下：
1. 分别求出 a、b 的中位数 a[m1] 和 b[m2]。
2. 若 a[m1] = b[m2]，则 a[m1] 或 b[m2] 即为所求中位数，end。
3. 若 a[m1] < b[m2]，则舍弃序列 a 中的前半部分（较小的一半），同时舍弃序列 b 中的后半部分（较大的一半），要求舍弃的长度相等。
4. 若 a[m1] > b[m2]，则舍弃序列 a 中的后半部分（较大的一半），同时舍弃序列 b 中的前半部分（较小的一半），要求舍弃的长度相等。
5. 在保留的升序序列中重复上述过程直到两个序列中只有一个元素时为止，较小者即为所求的中位数。
6. 为了保证每次取的两个子有序序列等长，对于 a[s...t]，m = (s+t)/2，若取前半部分，则为 a[s...m]。在取后半部分时要区分 a 中的元素个数为奇数还是偶数，若为奇数（满足 (s+t)%2 == 0 的条件），则后半部分为 a[m...t]，若为偶数（满足 (s+t)%2 == 1 的条件），则后半部分为 a[m+1...t]。

## 补充
三分查找：
```
求解假币问题。有 100 个硬币，其中有一个假币（与真币一模一样，只是比真币的重量轻），
采用天平称重方法找出这个假币，最少用天平称多少次保证找到假币?
```
将 100 个硬币分为 33、33、34 三组，用天平一次称重可以找到假币所在的组，依次进行，对于一棵三分判定树，树高度恰好是称重次数，结果为 <code>ceil(log3(100+1)) = 5。</code>

## 代码
#1、2、3

[exp3-3.cpp](./code/exp3-3.cpp)

#4

[exp3-3-4.cpp](./code/exp3-3-4.cpp)

## 复杂度分析

#1
- 时间复杂度：O(n)
- 空间复杂度：O(n)

#2
- 空间复杂度：O(log2n)
- 空间复杂度：O(n)

#3
- 空间复杂度：O(n)
- 空间复杂度：O(n)

#4
- 空间复杂度：O(log2n)
- 空间复杂度：O(n) //序列 a 或序列 b 的长度