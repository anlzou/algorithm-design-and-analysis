/***
 * @Date        : 2020-12-20 16:26:33
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-12-20 16:37:00
 * @FilePath    :
 * \algorithm-design\chapters\chapter08-dynamic-programming\code\exp8_2_1.cpp
 * @Describe    :
 */

#include "../struct/head.h"

/**
 * 动态规划问题的逆序解法
 */
int reverseOrder(int s) {
    if (dp[s] != -1) return dp[s];  // 若dp[s]已求出，直接返回
    if (s == end_) {                //找到终点
        dp[s] = 0;
        cout << "(" << Count++ << ") "
             << "(" + vname[s] << ") = 0" << endl;
    } else {
        int cost, mincost = INF, minj;
        for (int j = 0; j < n; j++) {  //查找顶点s的后继顶点
            if (c[s][j] != 0 && c[s][j] != INF) {
                cost = c[s][j] +
                       reverseOrder(j);  //先求出后继顶点j的reverSeOrder值
                if (mincost > cost) {  //比较求最短路径
                    mincost = cost;
                    minj = j;
                }
            }
        }
        dp[s] = mincost;
        next_[s] = minj;  //当前顶点s后继顶点为minj
        cout << "(" << Count++ << ") reverseOrder"
             << "(" << vname[s] << ") = "
             << "c(" << vname[s] << "," << vname[minj] << ") + reverseOrder("
             << vname[minj] << ") = " << dp[s] << ", ";

        cout << "next(" << vname[s] << ") = " << vname[minj] << endl;
        return dp[s];
    }
    return -1;
}

/*================================ test ==================================*/
int main() {
    Init();
    cout << vname[end_] << "->" << vname[start_] << "求解过程" << endl;
    reverseOrder(start_);
    // Disp();
    return 0;
}