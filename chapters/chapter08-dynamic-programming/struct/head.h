/***
 * @Date        : 2020-12-20 16:56:23
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-12-20 16:56:49
 * @FilePath    :
 * \algorithm-design\chapters\chapter08-dynamic-programming\struct\head.h
 * @Describe    :
 */
#include <iostream>
#include <string.h>
#include <map>

using namespace std;
#define MAX 21
#define INF 0x3f3f3f3f
/**
 * 问题表示
 */
int n;                   //顶点个数
int start;               //起点编号
int end_;                //终点编号
int c[MAX][MAX];         //存放边长度
int next_[MAX];          //存放最短路径上当前顶点的后继顶点
map<int, string> vname;  //存放编号对应的顶点名称
int dp[MAX];             //最优结果数组
int Count = 1;           //计算步骤

/**
 * Test
 * 输出数组
 */
void Disp() {
    cout << "dp:" << endl;
    for (int i = 0; i < MAX; i++) {
        cout << dp[i] << " ";
    }

    cout << endl << "c:" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * 初始化图
 */
void Init() {
    n = 10;
    start = 0;
    end_ = 9;
    memset(c, INF, sizeof(c));
    //结果数组置为-1
    for (int i = 0; i < n; i++) dp[i] = -1;
    //左上角到右下角对角线为0
    for (int j = 0; j < n; j++) c[j][j] = 0;
    // 图8.4邻接矩阵
    c[0][1] = 2;
    c[0][2] = 4;
    c[0][3] = 3;

    c[1][4] = 7;
    c[1][5] = 4;

    c[2][4] = 3;
    c[2][5] = 2;
    c[2][6] = 4;

    c[3][4] = 6;
    c[3][5] = 2;
    c[3][6] = 5;

    c[4][7] = 3;
    c[4][8] = 4;

    c[5][7] = 6;
    c[5][8] = 3;

    c[6][7] = 3;
    c[6][8] = 3;

    c[7][9] = 3;

    c[8][9] = 4;

    // 图中顶点 A 对应的编号为0,下同
    vname[0] = "A";

    vname[1] = "B1";
    vname[2] = "B2";
    vname[3] = "B3";

    vname[4] = "C1";
    vname[5] = "C2";
    vname[6] = "C3";

    vname[7] = "D1";
    vname[8] = "D2";

    vname[9] = "E";

    // Disp();
}