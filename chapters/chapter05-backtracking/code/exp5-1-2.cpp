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
#include <vector>
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
 * 用回溯法求解向量 sign
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

/*=====================非向量求解======================*/
/**
 * 采用 vector<int>容器 path 直接存放获取的子集
 * 输出一个解
 */
void funDispASolutionUseVector(vector<int> path) {
    cout << "{";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
    }
    cout << "}";
}

/**
 * 用回溯法求解子集 path
 * 递归
 * 深度优先遍历(depth-first traversal)
 */
void DFS(int arr[], int len, int level, vector<int> path) {
    if (level >= len) {
        funDispASolutionUseVector(path);
    } else {
        DFS(arr, len, level + 1, path);
        path.push_back(arr[level]);
        DFS(arr, len, level + 1, path);
    }
}

/*======================test========================*/
int main() {
    int arr[] = {1, 2, 3};
    int len = sizeof(arr) / sizeof(int);

    /*==================方法一===================*/
    int sign[MAXN];                 //解向量
    memset(sign, 0, sizeof(sign));  //解向量初始化

    cout << "方法一，求解结果：" << endl;
    DFS(arr, len, 0, sign);
    cout << endl << endl;

    /*==================方法二===================*/
    vector<int> path;

    cout << "方法二，求解结果：" << endl;
    DFS(arr, len, 0, path);
    return 0;
}