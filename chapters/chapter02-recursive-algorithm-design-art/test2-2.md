<!--
 * @Date        : 2020-05-02 20:37:47
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-29 21:47:56
 * @FilePath    : \algorithm-design\chapters\chapter02-recursive-algorithm-design-art\test2-2.md
 * @Describe    : 
 -->
## 题目地址
2.1 递归算法设计

## 题目描述

问题：
```
#2.5 用递归法求一个整数数组 a 中的最大元素。

#2.6 有一个不带头结点的单链表 L，设计一个算法释放其中的所有结点。

#2.7 有一个不带头结点的单链表 L，设计一个算法删除其中所有结点值为 x 的结点。

#2.8 对于含有 n(n > 0) 个结点的二叉树，所有结点值为 int 类型，设计一个算法由其先序序列 a 和中序序列 b 创建对应的二叉链存储结构。

#2.10 假设二叉树采用二叉链存储结构，设计一个递归算法由二叉树 bt 复制产生另一颗二叉树 btcopy。
```

## 思路
#1

设 f(a, i) 求解数组 a 中前 i 个元素（即 a[0...i-1]）中的最大元素，则 f(a, i-1) 求解数组 a 中前 i-1 个元素（即 a[0...i-2]）中的最大元素，前者为“大问题”，后者为“小问题”，假设 f(a, i-1) 已求出，则有 f(a, i) = MAX{f(a, i-1), a[i-1]}。递推方向是朝 a 中元素个数减少的方向推进，当 a 中只有一个元素时，该元素就是最大元素，所以 f(a, 1) = a[0]。由此得到递归模型如下：
```c++
f(arr, end) = arr[0]                            //当 end = 1 时
f(arr, end) = MAX{f(arr, end-1), arr[end-1]}    //当 end > 1 时
```

#2

设 L = {a1, a2, ..., an}，f(L) 的功能是释放 a1~an 中的所有结点，则 f(L->next) 的功能是释放 a2~an 的所有结点，前者是“大问题”，后者是“小问题”。假设 f(L->next) 已实现，则 f(L) 就可以通过先调用 f(L->next) 然后释放 L 所指的结点来求解，对应的递归模型如下：
```c++
f(L) ≡ 不做任何事情                 //当 L = NULL 时
f(L) ≡ f(L->next);释放 *L 结点      //其他情况
```
其中，“≡”表示功能等价关系。

#3

设 f(L, x) 的功能是删除以 L 为首结点的单链表中所有结点值为 x 的结点，是“大问题”，而 f(L->next, x) 的功能是删除以 L->next 为首结点的单链表中所有节点值为 x 的结点，是“大问题”。对应的递归模型如下：
```c++
f(L, x) ≡ 不做任何事情     //当 L = NULL 时
f(L, x) ≡ 删除 L 结点；L指向原后继结点；f(L, x)    //当 L->data = x时
f(L, x) ≡ f(L->next, x)   //当 L->data ≠ x 时
```

#4

设 f(a, b, n) 的功能是返回先序序列 a 和中序序列 b 创建含 n 个结点的二叉链的根结点。先创建根结点 bt，其结点值为 root(a[0])。在 b 序列中找到根结点值 b[k]，再递归调用 CreateBTree(a+1, b, k) 创建 bt 的左子树，递归调用 CreateBTree(a+k+1, b+k+1, n-k-1) 创建 bt 的右子树。创建整个二叉链是“大问题”，创建左、右子树的二叉链是“小问题”，递归出口对应 n <= 0 的情况。

#5

设 f(bt, btcopy) 的功能是由二叉树 bt 复制产生另一颗二叉树 btcopy，它是“大问题”，而 f(bt->lchild, btcopy->lchild)的功能就是由 bt 的左子树复制产生 btcopy 的左子树，f(bt->rchild, btcopy->rchild) 的功能就是由 bt 的右子树复制产生 btcopy 的右子树，它们是 “小问题”，对应递归模型如下：
```c++
f(bt, btcopy) ≡ btcopy = NULL                   //当 b = NULL 时
f(bt, btcopy) ≡ 由 bt 结点复制产生 btcopy 结点;   //其他情况
   f(bt->lchild, btcopy->lchild);
   f(bt->rchild, btcopy->rchild);
```

## 关键点
- 递归体

## 代码
#1、2、3、4、5

- [exp2-2.cpp](code/exp2-2.cpp)

## 补充

## 复杂度分析

- 时间复杂度：O( )
- 空间复杂度：O( )