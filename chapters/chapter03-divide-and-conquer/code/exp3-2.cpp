/***
 * @Date        : 2020-05-31 21:23:43
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-05-31 21:24:57
 * @FilePath    :
 * \algorithm-design\chapters\chapter03-divide-and-conquer\code\exp3-2.cpp
 * @Describe    :
 */
#include <iostream>

using namespace std;

/**
 * 输出数组
 */
void disp(int arr_int[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        cout << arr_int[i] << " ";
    }
    cout << endl;
}

/**
 * 划分算法
 * 按基准值进行排序
 */
int partition(int arr_int[], int front, int rear) {
    int i = front, j = rear;
    int temp = arr_int[front];  // 用数列的第 1 个记录作为基准
    while (i != j) {  // 从序列两端交替向中间扫描，直到 i=j 为止
        while (j > i && arr_int[j] >= temp) {
            j--;  // 从右向左扫描，找第 1 个关键字小于 temp 的 arr_int[j]
        }
        arr_int[i] = arr_int[j];  // 将 arr_int[j] 向前移动到 arr_int[i] 的位置
        while (i < j && arr_int[i] <= temp) {
            i++;  // 从左向右扫描，找第 1 个关键字大于 temp 的 arr_int[i]
        }
        arr_int[j] = arr_int[i];  // 将 arr_intp[i] 后移到 arr_int[j] 的位置
    }
    arr_int[i] = temp;
    return i;
}

/**
 * 对 arr_int[front...rear] 元素序列进行递增排序
 */
void quickSort(int arr_int[], int front, int rear) {
    if (front < rear) {  //序列内至少存在两个元素的情况
        int i = partition(arr_int, front, rear);
        quickSort(arr_int, front, i);     //对左子序列递归排序
        quickSort(arr_int, i + 1, rear);  //对右子序列递归排序
    }
}

int main() {
    int arr_int[] = {2, 5, 1, 7, 10, 6, 9, 4, 3, 8};
    int len = sizeof(arr_int) / sizeof(int);

    cout << "before sort:";
    disp(arr_int, len);

    quickSort(arr_int, 0, len - 1);
    cout << "after sort:";
    disp(arr_int, len);
    return 0;
}