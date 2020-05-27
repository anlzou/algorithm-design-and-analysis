<!--
 * @Date        : 2020-05-02 20:37:47
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-27 23:42:12
 * @FilePath    : \algorithm-design\chapters\chapter08-dynamic-programming\test-1.md
 * @Describe    : 
 -->
## 题目地址
8.1 动态规划概述

## 题目描述

问题：
```
求解斐波那契数列
```
目的：
```
从求解斐波那契数列看动态规划法
```

## 思路
[第2章](./../chapter02-recursive-algorithm-design-art/problems.md)中讨论斐波那契数列的**递归算法**

1. 递归调用<code>Fib( )</code>采用自顶向下的执行过程
2. 算法中存在大量的重复计算

## 关键点
为了避免重复设计，设计一个 dp 数组，dp[i] 存放 Fib(i) 的值，首先设置 dp[1] 和 dp[2] 均为 1，再让 i 从 3 到 n 循环以计算 dp[3] 到 dp[n] 的值，最后返回 dp[n]，即 Fib(n)。

## 代码
- [exp8-1.cpp](./code/exp8-1.cpp)
- [test8_1.cpp](./../../test/test8_1.cpp)

## 复杂度分析

- 时间复杂度：O( )
- 空间复杂度：O( )