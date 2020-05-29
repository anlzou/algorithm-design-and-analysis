/***
 * @Date        : 2020-05-29 21:14:30
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-29 21:15:10
 * @FilePath    :
 * \algorithm-design\chapters\chapter02-recursive-algorithm-design-art\code\header\header.h
 * @Describe    :
 */

#include <iostream>
using namespace std;
/**
 * 单链表结构体
 * */
typedef char ElemType;  //存储类型

typedef struct Node {
    ElemType data;
    Node *next;
} LinkNode;

/**
 * 二叉树结构体
 */
typedef struct node {  //定义结点
    ElemType data;
    struct node *rchild;
    struct node *lchild;
} BTNode;