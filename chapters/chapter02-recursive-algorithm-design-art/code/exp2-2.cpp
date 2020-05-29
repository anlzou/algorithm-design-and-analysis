/***
 * @Date        : 2020-05-29 20:23:48
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-29 20:25:38
 * @FilePath    :
 * \algorithm-design\chapters\chapter02-recursive-algorithm-design-art\code\exp2-2.cpp
 * @Describe    :
 */
#include <iostream>
using namespace std;

/**
 * 单链表结构体
 * */
typedef char ElemType;
typedef struct Node {
    ElemType data;
    Node *next;
} LinkNode;

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

int main() {
    int arr[] = {10, 4, 6, 20, 5};
    cout << maxArrNumber(arr, 5) << endl;
    return 0;
}
