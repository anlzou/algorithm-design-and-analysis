/***
 * @Date        : 2020-05-29 20:23:48
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-29 20:25:38
 * @FilePath    :
 * \algorithm-design\chapters\chapter02-recursive-algorithm-design-art\code\exp2-2.cpp
 * @Describe    :
 */
#include "./header/header.h"

/**
 * 求数组 arr 中的最大元素的递归算法
 */
int maxArrNumber(int arr[], int end) {
    if (end == 1) {
        return arr[0];
    } else {
        return (maxArrNumber(arr, end - 1) > arr[end - 1]
                    ? maxArrNumber(arr, end - 1)
                    : arr[end - 1]);
    }
}

/**
 * 释放单链表 L 中的所有结点
 */
void DestroyList(LinkNode *&L) {
    if (L != NULL) {
        DestroyList(L->next);
        free(L);
    }
}

/**
 * 删除 L 中所有结点值为 x 的结点
 */
void delAllx(LinkNode *&L, ElemType x) {
    LinkNode *p;
    if (L == NULL) {
        return;
    }
    if (L->data == x) {
        p = L;
        L = L->next;
        free(p);        //删除结点值为 x 的结点
        delAllx(L, x);  //此时 L 中少了一个结点
    } else {
        delAllx(L->next, x);
    }
}

/**
 * 递归创建二叉树
 * 由先序序列 a[0...n-1] 和中序列 b[0...n-1] 创建二叉链存储结构 bt
 */
BTNode *CreateBTree(ElemType a[], ElemType b[], int n) {
    int k;
    if (n <= 0) {
        return NULL;
    }
    ElemType root = a[0];  //根结点值
    BTNode *bt = (BTNode *)malloc(sizeof(BTNode));
    bt->data = root;
    for (k = 0; k < n; k++) {  //在 b 中查找 b[k] = root 的根结点
        if (b[k] == root) {
            break;
        }
        bt->lchild = CreateBTree(a + 1, b, k);  //递归创建左子树
        bt->rchild =
            CreateBTree(a + k + 1, b + k + 1, n - k - 1);  //递归创建右子树
        return bt;
    }
}

/**
 * 由二叉树 bt 复制产生二叉树 btcopy
 */
void copyBTree(BTNode *bt, BTNode *&btcopy) {
    if (bt == NULL) {
        btcopy = NULL;
    } else {
        btcopy = (BTNode *)malloc(sizeof(BTNode));
        btcopy->data = bt->data;
        copyBTree(bt->lchild, btcopy->lchild);
        copyBTree(bt->rchild, btcopy->lchild);
    }
}

/*==================Test================*/
int main() {
    int arr[] = {10, 4, 6, 20, 5};
    cout << maxArrNumber(arr, 5) << endl;
    return 0;
}
