/***
 * @Date        : 2020-06-05 17:15:41
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-06-05 17:42:43
 * @FilePath    :
 * \algorithm-design\chapters\chapter05-backtracking\code\exp5-1.cpp
 * @Describe    :
 */

#include <iostream>
#include <string.h>

using namespace std;

/**
 * 象棋算式求解
 * 非递归
 */
void funSolve() {
    bool dig[10];
    int a, b, c, d, e, m, n, s;
    memset(dig, 0, sizeof(dig));  //置初值为 0 表示所有数字均没有使用

    for (a = 0; a < 10; a++) {
        dig[a] = 1;  //试探兵取值 a
        for (b = 0; b < 10; b++) {
            if (!dig[b]) {
                dig[b] = 1;  //试探炮取值 b
                for (c = 0; c < 10; c++) {
                    if (!dig[c]) {
                        dig[c] = 1;  //试探马取值 c
                        for (d = 0; d < 10; d++) {
                            if (!dig[d]) {
                                dig[d] = 1;  //试探卒取值 d
                                for (e = 0; e < 10; e++) {
                                    if (!dig[e]) {
                                        dig[e] = 1;  //试探车取值 e
                                        m = a * 1000 + b * 100 + c * 10 + d;
                                        n = a * 1000 + b * 100 + e * 10 + d;
                                        s = e * 10000 + d * 1000 + c * 100 +
                                            a * 10 + d;
                                        if (m + n == s) {
                                            cout << "兵：" << a << "；炮：" << b
                                                 << "；马：" << c << "；卒："
                                                 << d << "；车：" << e << endl;
                                        }
                                        dig[e] = 0;  //回溯车的取值
                                    }
                                    dig[d] = 0;  //回溯卒的取值
                                }
                            }
                            dig[c] = 0;  //回溯马的取值
                        }
                    }
                    dig[b] = 0;  //回溯炮的取值
                }
            }
            dig[a] = 0;  //回溯兵的取值
        }
    }
}

/*======================test========================*/
int main() {
    funSolve();
    return 0;
}