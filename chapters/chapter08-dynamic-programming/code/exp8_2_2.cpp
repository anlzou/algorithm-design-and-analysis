/***
 * @Date        : 2020-12-20 18:51:46
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-12-20 18:58:37
 * @FilePath    :
 * \algorithm-design\chapters\chapter08-dynamic-programming\code\exp8_2_2.cpp
 * @Describe    :
 */

#include "../struct/head.h"

/**
 * 动态规划问题的逆序解法
 */
int positiveSequence(int s) {
    if (dp[s] != -1) return dp[s];  // 若dp[s]已求出，直接返回
    if (s == start_) {              //找到终点
        dp[s] = 0;
        cout << "(" << Count++ << ") "
             << "(" + vname[s] << ") = 0" << endl;
    } else {
        int cost, mincost = INF, mini;
        for (int i = 0; i < n; i++) {  //查找顶点s的前驱顶点
            if (c[i][s] != 0 && c[i][s] != INF) {
                cost = c[i][s] +
                       positiveSequence(i);  //先求出前驱顶点j的reverSeOrder值
                if (mincost > cost) {  //比较求最短路径
                    mincost = cost;
                    mini = i;
                }
            }
        }
        dp[s] = mincost;
        pre_[s] = mini;  //当前顶点s前驱顶点为mini
        cout << "(" << Count++ << ") positiveSequence"
             << "(" << vname[s] << ") = "
             << "c(" << vname[mini] << "," << vname[mini]
             << ") + positiveSequence(" << vname[s] << ") = " << dp[s] << ", ";

        cout << "pre(" << vname[s] << ") = " << vname[mini] << endl;
        return dp[s];
    }
    return -1;
}

/*================================ test ==================================*/
int main() {
    Init();
    cout << vname[start_] << "->" << vname[end_] << "求解过程" << endl;
    positiveSequence(end_);
    // Disp();
    return 0;
}