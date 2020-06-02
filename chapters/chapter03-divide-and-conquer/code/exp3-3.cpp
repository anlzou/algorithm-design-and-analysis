/***
 * @Date        : 2020-06-02 14:57:37
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-06-02 15:05:22
 * @FilePath    :
 * \algorithm-design\chapters\chapter03-divide-and-conquer\code\exp3-3.cpp
 * @Describe    :
 */
#include <iostream>
#define INF 2147483648
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)

using namespace std;

void funFindMaxTop2(int arr[], int low, int high, int &max1, int &max2) {
    if (low == high) {  //区间只有一个元素
        max1 = arr[low];
        max2 = -INF;
    } else if (low == high - 1) {  //区间只有两个元素
        max1 = max(arr[low], arr[high]);
        max2 = min(arr[low], arr[high]);
    } else {  //区间中有两个元素以上
        int mid = (low + high) / 2;
        int lmax1, lmax2;
        funFindMaxTop2(arr, low, mid, lmax1, lmax2);  //左区间求 lmax1 和 lmax2
        int rmax1, rmax2;
        funFindMaxTop2(arr, mid + 1, high, rmax1,
                       rmax2);  //右区间求 rmax1 和 rmax2
        if (lmax1 > rmax2) {
            max1 = lmax1;
            max2 = max(lmax2, rmax1);  // lmax2、rmax1 中求次大元素
        } else {
            max1 = rmax1;
            max2 = max(lmax1, rmax2);  // lamx1、rmax2 中求次大元素
        }
    }
}

int main() {
    // cout << INT32_MAX << endl;
    int arr[] = {5, 2, 1, 4, 3};
    int len = sizeof(arr) / sizeof(int);
    int max1, max2;
    funFindMaxTop2(arr, 0, len - 1, max1, max2);
    cout << "max1:" << max1 << " max2:" << max2 << endl;
    return 0;
}