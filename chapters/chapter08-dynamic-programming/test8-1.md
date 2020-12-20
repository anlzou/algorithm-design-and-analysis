<!--
 * @Date        : 2020-05-02 20:37:47
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-12-20 19:06:20
 * @FilePath    : \algorithm-design\chapters\chapter08-dynamic-programming\test8-1.md
 * @Describe    : 
 -->
 
## 题目地址
8.1 动态规划概述

**动态规划**（Dynamic Programming, PD）是将多阶段决策树问题进行公式化的一种技术，由 R.Bellman 于 1957 年提出，被成功运用于许多领域。

动态规划并非是“动态编程”或者“动态查询设计”。动态规划通常基于一个递推公式及一个或多个初始状态，当前子问题的解将由上一个子问题的解推出（有点像马尔可夫假设）。许多问题看起来复杂的问题采用动态规划求解十分方便，而且只需要多项式时间复杂度，比回溯法、暴力破解法等效率高，但并非任何问题都适合采用动态规划法求解。

## 题目描述

问题：
```
#1 求解斐波那契数列，Fib(n)的值

#2 一个多阶段图或多段图的最短路径（P284 图 8.4）
    1. 动态规划问题的逆序解法 
    2. 动态规划问题的顺序解法
```
目的：
```
从求解斐波那契数列看动态规划法

动态规划问题的解法
```

## 思路
#1 [第2章](./../chapter02-recursive-algorithm-design-art/problems.md)中讨论斐波那契数列的**递归算法**

1. 递归调用<code>Fib( )</code>采用自顶向下的执行过程
2. 算法中存在大量的重复计算
3. 计算结果保存到数组中，当前的计算结果是之前计算结果的算数

#2 对于有k个阶段的动态规划问题，从第k个阶段到第1阶段的求解过程称为逆序解法，从第1阶段到第k阶段的求解过程称为顺序解法。

## 关键点
#1 为了避免重复设计，设计一个 dp 数组，dp[i] 存放 Fib(i) 的值，首先设置 dp[1] 和 dp[2] 均为 1，再让 i 从 3 到 n 循环以计算 dp[3] 到 dp[n] 的值，最后返回 dp[n]，即 Fib(n)。

#2 用`next`表示路径上一个顶点的后继顶点。

## 补充
[【算法设计与数据结构】为何程序员喜欢将INF设置为0x3f3f3f3f？](https://blog.csdn.net/jiange_zh/article/details/50198097)
- 0x3f3f3f3f = 1061109567

[C++ map用法总结（整理）](https://blog.csdn.net/sevenjoin/article/details/81943864)
- 自动建立key:value的对应。key 和 value可以是任意你需要的类型，包括自定义类型。
- map<K, V> mapName;

## 代码
>- [head.h](./struct/head.h)
>>- [exp8-1.cpp](./code/exp8-1.cpp)
>>- [exp8_2_1.cpp](./code/exp8_2_1.cpp)
>>- [exp8_2_2.cpp](./code/exp8_2_2.cpp)

## 复杂度分析
#1
- 时间复杂度：O(n-2)
- 空间复杂度：O(n+1)