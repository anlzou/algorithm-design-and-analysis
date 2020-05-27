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

int dp[MaxSize];
/**
 * 求斐波那契数列动态规划算法
 */
void Fibonacci(int n) {
    dp[1] = dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

/*================================ test ==================================*/
int main() {
    Fibonacci(40);
    for (int i = 1; i <= 40; i++) {
        cout << "[" << i << "]：" << dp[i] << endl;
    }

    return 0;
}