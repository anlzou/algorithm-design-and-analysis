/***
 * @Date        : 2020-05-28 09:01:08
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-28 09:01:52
 * @FilePath    :
 * \algorithm-design\chapters\chapter02-recursive-algorithm-design-art\code\exp2-1.cpp
 * @Describe    :
 */
#include <iostream>
using namespace std;

/**
 * #2.1
 * 设计求 n! (n 为正数)的递归算法。
 */
int factorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        return (factorial(n - 1) * n);
    }
}

/**
 * #2.2
 * 二叉树采用二叉链存储结构
 */
typedef struct BNode {
    int data;
    struct BNode *lchild, *rchild;
} BTNode;  //二叉链结点类型

/**
 * 求非空二叉树链 bt 中所有结点值之和的递归算法
 */
int sumBTnodes(BTNode *bt) {
    if (bt->lchild == NULL && bt->rchild == NULL) {
        return bt->data;  //只有一个结点时返回该结点值
    } else {  //否则返回左、右子树结点值之和加上根结点值
        return sumBTnodes(bt->lchild) + sumBTnodes(bt->rchild) + bt->data;
    }
}