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

/**
 * 查找最大和次大元素
 */
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

/*==============================折半查找===============================*/
/**
 * 折半查找/二分查找
 * 递归
 */
int funRecuBinSearch(int arr[], int low, int high, int value) {
    int mid;
    if (low <= high) {            //当前区间存在元素时
        mid = (low + high) / 2;   //求查找区间的中间位置
        if (arr[mid] == value) {  //找到后返回其物理下标 mid
            return mid;
        }
        if (arr[mid] >
            value) {  //当 arr[mid]>value 时在 arr[low...mid-1] 中递归查找
            return funRecuBinSearch(arr, low, mid - 1, value);
        } else {  //当 arr[mid]<value 时在 arr[mid+1...high] 中递归查找
            return funRecuBinSearch(arr, mid + 1, high, value);
        }
    } else {
        return -1;  //当前查找区间没有元素时返回 -1
    }
}

/**
 * 折半查找/二分查找
 * 非递归
 */
int funUnreBinSearch(int arr[], int len, int value) {
    int low = 0, high = len - 1, mid;
    while (low <= high) {         //当前区间存在元素时循环
        mid = (low + high) / 2;   //求查找区间的中间位置
        if (arr[mid] == value) {  //找到后返回其物理下标 mid
            return mid;
        }
        if (arr[mid] > value) {  //继续在 arr[low...mid-1] 中继续查找
            high = mid - 1;
        } else {            // a[mid] < k
            low = mid + 1;  //继续在 a[mid+1...high] 中查找
        }
    }
    return -1;  //当前查找区间没有元素时返回 -1
}

/*========================寻找一个序列中第 k 小的元素=========================*/
/**
 * 在 a[s...t] 序列中找第 k 小的元素
 */
int funQuickSelect(int arr[], int front, int rear, int k) {
    int i = front, j = rear;
    int temp;
    if (front < rear) {     //区间内至少存在两个元素的情况
        temp = arr[front];  //用区间的第 1 个记录作为基准
        while (i != j) {  //从区间两端交替向中间扫描，直到 i=j 为止
            while (j > i && arr[j] >= temp) {
                j--;  //从右向左扫描，找第 1 个关键字小于 i=j 为止
            }
            arr[i] = arr[j];  //将 arr[j] 前移到 arr[i]的位置
            while (i < j && arr[i] <= temp) {
                i++;  //从左向右扫描，找第 1 个关键字大于 temp 的 arr[i]
            }
            arr[j] = arr[i];  //将 arr[i] 后移到 arr[j] 的位置
        }
        arr[i] = temp;
        if (k - 1 == i) {
            return arr[i];
        } else if (k - 1 < i) {
            return funQuickSelect(arr, front, i - 1, k);  //在左区间中递归查找
        } else {
            return funQuickSelect(arr, i + 1, rear, k);  //在右区间中递归查找
        }
    } else if (front == rear &&
               front == k - 1) {  //区间内只有一个元素且为 arr[k-1]
        return arr[k - 1];
    }
    return -1;
}

/*============================test==============================*/
int main() {
    // cout << INT32_MAX << endl;   //INF = 2147483647+1
    int arr[] = {6, 1, 7, 3, 4, 5};
    int len = sizeof(arr) / sizeof(int);

    /*===============test funFindMaxTop2()================*/
    // int max1, max2;
    // funFindMaxTop2(arr, 0, len - 1, max1, max2);
    // cout << "max1:" << max1 << " max2:" << max2 << endl;

    /*================test funBinSearch()==================*/
    // int value = 2;
    // int index = funRecuBinSearch(arr, 0, len - 1, value);
    // if (index >= 0) {
    //     cout << "arr[" << index << "]=" << value << endl;
    // } else {
    //     cout << "not find the number:" << value << endl;
    // }

    // value = 1;
    // index = funUnreBinSearch(arr, len, value);
    // if (index >= 0) {
    //     cout << "arr[" << index << "]=" << value << endl;
    // } else {
    //     cout << "not find the number:" << value << endl;
    // }

    /*================test funQuickSelect()================*/
    int index;
    for (int k = 1; k <= len; k++) {
        index = funQuickSelect(arr, 0, len - 1, k);
        if (index != -1) {
            cout << "第" << k << "小的元素为:" << index << endl;
        } else {
            cout << "error!" << endl;
        }
    }

    return 0;
}