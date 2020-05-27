/***
 * @Date        : 2020-05-27 23:10:45
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-27 23:14:54
 * @FilePath    :
 * \algorithm-design\chapters\chapter08-dynamic-programming\code\exp8-1.cpp
 * @Describe    :
 */
#include <iostream>
#define MaxSize 46

using namespace std;

/**
 * 求斐波那契数列动态规划算法
 */
int Fibonacci(int n) {
    int sum = 1;  //累计求解步骤
    int dp[MaxSize];
    dp[1] = dp[2] = 1;

    cout << "(" << sum++ << ")"
         << "计算出 Fib(1)=1" << endl;

    cout << "(" << sum++ << ")"
         << "计算出 Fib(2)=1" << endl;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        cout << "(" << sum++ << ")"
             << "计算出 Fib(" << i << ")=" << dp[i] << endl;
    }
    return dp[n];
}