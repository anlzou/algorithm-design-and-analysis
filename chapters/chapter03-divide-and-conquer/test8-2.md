<!--
 * @Date        : 2020-05-02 20:37:47
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-31 21:47:18
 * @FilePath    : \algorithm-design\chapters\chapter03-divide-and-conquer\test8-2.md
 * @Describe    : 
 -->
 
## 题目地址
3.2 求解排序问题

## 题目描述

问题：
```
#1
快速排序

```
分治法的一般算法设计模式如下：
```
divide-and-conquer(P){
    if |P| <= n0 return adhoc(P);
    将 P 分解为较小的子问题 P1、P2、...、Pk;
    for(i = 1; i <= k; i++)                 //循环处理 k 次
        yi = divide-and-conquer(Pi);        //递归解决 Pi
    return merge(yi, y2, ..., yk);          //合并子问题
}
```

## 思路
快速排序的基本思想是在待排序的 n 个元素中任取一个元素（通常取第一个元素）作为基准，把该元素放入最终位置后，整个数据序列被基准分割成两个子序列，所有小于基准的元素放置在前子序列中，所有大于基准的元素放置在后子序列中，并把基准排在这两个子序列的中间，这个过程称为划分。然后对连个子序列分别重复上述过程，直到每个子序列内只有一个元素或空为止。

## 代码
[exp3-2.cpp](./code/exp3-2.cpp)

## 复杂度分析

- 平均时间复杂度：O(nlog2n)
- 空间复杂度：O(n)