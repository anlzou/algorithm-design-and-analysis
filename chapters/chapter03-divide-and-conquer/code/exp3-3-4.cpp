/***
 * @Date        : 2020-06-02 22:16:02
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-06-02 22:17:44
 * @FilePath    :
 * \algorithm-design\chapters\chapter03-divide-and-conquer\code\exp3-3-4.cpp
 * @Describe    :
 */
#include <iostream>

using namespace std;

/**
 * 求 arr[front...rear] 序列的前半子序列
 */
void funArrPrePart(int &front, int &rear) {
    int mid = (front + rear) / 2;
    rear = mid;
}

/**
 * 求 arr[front...rear] 序列的后半子序列
 */
void funArrPostPart(int &front, int &rear) {
    int mid = (front + rear) / 2;
    if ((front + rear) % 2 == 0) {  //序列中有奇数个元素
        front = mid;
    } else {  //序列中有偶数个元素
        front = mid + 1;
    }
}

/**
 * 求两个有序序列 arra[front1...rear1] 和 arrb[front2...rear2] 的中位数
 * 递归方法
 */
int funRecuMidNum(int arra[], int front1, int rear1, int arrb[], int front2,
                  int rear2) {
    int mid1, mid2;
    if (front1 == rear1 &&
        front2 == rear2) {  //两个序列只有一个元素时返回较小者
        return arra[front1] < arrb[front2] ? arra[front1] : arrb[front2];
    } else {
        mid1 = (front1 + rear1) / 2;  //求 a 的中位数
        mid2 = (front2 + rear2) / 2;  //求 b 的中位数
        if (arra[mid1] == arrb[mid2]) {  //两个中位数相等时返回该中位数
            return arra[mid1];
        }
        if (arra[mid1] < arrb[mid2]) {      //当 arra[mid1] < arrb[mid2] 时
            funArrPostPart(front1, rear1);  // arra 取后半部分
            funArrPrePart(front2, rear2);   // arrb 取后半部分
            return funRecuMidNum(arra, front1, rear1, arrb, front2, rear2);
        } else {                            //当 arra[mid1] > arrb[mid2] 时
            funArrPrePart(front1, rear1);   // arra 取前半部分
            funArrPostPart(front2, rear2);  // arrb 取后半部分
            return funRecuMidNum(arra, front1, rear1, arrb, front2, rear2);
        }
    }
}

/**
 * 求两个有序序列 arra[front1...rear1] 和 arrb[front2...rear2] 的中位数
 * 非递归方法
 */
int funUnreMidNum(int arra[], int arrb[], int lenab) {
    int front1, rear1, mid1;
    int front2, rear2, mid2;

    front1 = 0;
    rear1 = lenab - 1;
    front2 = 0;
    rear2 = lenab - 1;

    while (front1 != rear1 || front2 != rear2) {
        mid1 = (front1 + rear1) / 2;
        mid2 = (front2 + rear2) / 2;
        if (arra[mid1] == arrb[mid2]) {
            return arra[mid1];
        }
        if (arra[mid1] < arrb[mid2]) {
            funArrPostPart(front1, rear1);
            funArrPrePart(front2, rear2);
        } else {
            funArrPrePart(front1, rear1);
            funArrPostPart(front2, rear2);
        }
    }
    return arra[front1] < arrb[front2] ? arra[front1] : arrb[front2];
}

/*========================test===========================*/
int main() {
    int arra[] = {11, 13, 15, 17, 19};
    int arrb[] = {2, 4, 6, 8, 20};
    int lena = sizeof(arra) / sizeof(int);
    int lenb = sizeof(arrb) / sizeof(int);

    /*=============funRecuMidNum=============*/
    cout << "中位数：" << funRecuMidNum(arra, 0, lena - 1, arrb, 0, lenb - 1)
         << endl;

    /*=============funUnreMidNum=============*/
    cout << "中位数：" << funUnreMidNum(arra, arrb, lena);
}