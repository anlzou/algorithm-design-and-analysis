/***
 * @Date        : 2020-06-06 22:26:01
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-06-06 22:32:25
 * @FilePath    :
 * \algorithm-design\chapters\chapter05-backtracking\code\exp5-1-3.cpp
 * @Describe    :
 */
#include <iostream>
#define N 9

using namespace std;

/**
 * 求解函数
 */
void funSolve(char op[], int sum, int prevadd, int arr_number[], int index) {
    if (index == N) {               //扫描完所有位置
        if (sum == 100) {           //找到一个解
            cout << arr_number[0];  //输出解
            for (int j = 1; j < N; j++) {
                if (op[j] != ' ') {
                    cout << op[j];
                }
                cout << arr_number[j];
            }
            cout << "=100" << endl;
        }
        return;
    }

    op[index] = '+';           //位置 i 插入 '+'
    sum += arr_number[index];  //计算结果
    funSolve(op, sum, arr_number[index], arr_number,
             index + 1);       //继续处理下一个位置
    sum -= arr_number[index];  //回溯
    op[index] = '-';           //位置 i 插入 '-'
    sum -= arr_number[index];  //计算结果
    funSolve(op, sum, -arr_number[index], arr_number,
             index + 1);       //继续处理下一个位置
    sum += arr_number[index];  //回溯
    op[index] = ' ';           //位置 i 插入 ' '
    sum -= prevadd;            //先减去前面的元素值
    int temp;                  //计算新元素值
    if (prevadd > 0) {
        temp = prevadd * 10 +
               arr_number[index];  //如 prevadd = 5，a[i] = 6，结果为 56
    } else {
        temp = prevadd * 10 -
               arr_number[index];  //如 prevadd = -5，a[i] = 6，结果为 -56
    }
    sum += temp;                                     //计算合并结果
    funSolve(op, sum, temp, arr_number, index + 1);  //继续处理下一个位置
    sum -= temp;                                     //回溯 sum
    sum += prevadd;
}

/*=============================test================================*/
int main() {
    int arr[N];
    char op[N];                    // op[i] 表示在位置 i 插入运算符
    for (int i = 0; i < N; i++) {  //将 a 赋值为1、2、...、9
        arr[i] = i + 1;
    }

    cout << "The answer:" << endl;
    funSolve(op, arr[0], arr[0], arr, 1);  //插入位置 i 从 1 开始

    return 0;
}