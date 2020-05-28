<!--
 * @Date        : 2020-05-02 20:37:47
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-28 09:22:54
 * @FilePath    : \algorithm-design\chapters\chapter02-recursive-algorithm-design-art\test2-1.md
 * @Describe    : 
 -->
## 题目地址
2.1 什么是递归

## 题目描述

问题：
```
#2.1 设计求 n! (n 为正数)的递归算法。

#2.2 分析二叉树的二叉链存储结构的递归性，设计求非空二叉链 bt 中所有结点值之和的递归算法，
假设二叉链的 data 域为 int 型。
```

## 思路
在以下 3 种情况下经常要用到递归的方法。
1. 定义是递归的
   - 有许多数学公式、数列和概念的定义是递归的，例如求 n! 和斐波那契(Fibonacci)数列等。
2. 数据结构是递归的
   - 算法是用于数据处理的，有些存储数据的数据结构是递归的，对于递归数据结构，采用递归的方法设计算法既方便又有效，例如单链表和二叉树二叉链等。
3. 问题的求解方法是递归的
   - 有些问题的解法是递归的，典型的有例1.8 的汉诺塔(Hanoi) 问题求解。 

## 关键点
1. 需要解决的问题可以转化为一个或多个问题来求解，而这些子问题的求解方式与原问题完全相同，只是在数量规模上不同。
2. 递归调用的次数必须是有限的。
3. 必须有结束递归的条件来终止递归。

## 代码
- [exp2-1.cpp](code/exp2-1.cpp)
- [test1.cpp](code/test1.cpp)

## 补充
- [实现二叉树各种基本运算的算法](https://github.com/anlzou/data-structure/blob/master/chapters/chapter07-trees-and-binary-trees/test-1.md)
## 复杂度分析

- 时间复杂度：O( )
- 空间复杂度：O( )