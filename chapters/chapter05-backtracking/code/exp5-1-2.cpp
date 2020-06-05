/***
 * @Date        : 2020-06-05 20:00:26
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-06-05 20:01:14
 * @FilePath    :
 * \algorithm-design\chapters\chapter05-backtracking\code\exp5-1-2.cpp
 * @Describe    :
 */

#include <iostream>
#include <string.h>
#define MAXN 100

using namespace std;

/**
 * 输出一个解
 */
void funDispASolution(int arr[], int len, int sign[]) {
    cout << "{";
    for (int i = 0; i < len; i++) {
        if (sign[i] == 1) {
            cout << arr[i] << "";
        }
    }
    cout << "}";
}

/**
 * 用回溯法求解向量 x
 * 递归
 * 深度优先遍历(depth-first traversal)
 */
void DFS(int arr[], int len, int level, int sign[]) {
    if (level >= len) {
        funDispASolution(arr, len, sign);
    } else {
        sign[level] = 0;  //不选择 a[level]
        DFS(arr, len, level + 1, sign);
        sign[level] = 1;  //选择 a[level]
        DFS(arr, len, level + 1, sign);
    }
}

/*======================test========================*/
int main() {
    int arr[] = {1, 2, 3};
    int len = sizeof(arr) / sizeof(int);

    int sign[MAXN];                 //解向量
    memset(sign, 0, sizeof(sign));  //解向量初始化

    cout << "求解结果:" << endl;
    DFS(arr, len, 0, sign);
    return 0;
}