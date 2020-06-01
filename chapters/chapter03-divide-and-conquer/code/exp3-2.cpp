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

/*==================快速排序====================*/
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

/*=======================归并排序========================*/
/**
 * 将 a[low...mid] 和 a[mid+1...high] 两个相邻的有序子序列归并为一个有序子序列
 * a[low...high]
 */
void funMerge(int a[], int low, int mid, int high) {
    int *temp;
    int i = low, j = mid + 1,
        k = 0;  // k 是 temp 的下标，i,j 分别为两个子表的下标
    temp = (int *)malloc((high - low + 1) * sizeof(int));
    while (i <= mid &&
           j <= high) {  //在第 1 个子表和第 2 个子表均未扫描完时循环
        if (a[i] <= a[j]) {  //将第 1 个子表中的元素放入 temp 中
            temp[k] = a[i];
            i++;
            k++;
        } else {  //将第 2 个子表中的元素放入 temp 中
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {  //将第 1 个子表余下的部分复制到 temp
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= high) {  //将第 2 个子表余下的部分复制到 temp
        temp[k] = a[j];
        j++;
        k++;
    }
    for (k = 0, i = low; i <= high; k++, i++) {  //将 temp 复制回 a 中
        a[i] = temp[k];
    }
    free(temp);  //释放空间
}

/**
 * 一趟二路归并排序
 */
void funMergePass(int a[], int length, int n) {
    int i;
    for (i = 0; i + 2 * length - 1 < n;
         i = i + 2 * length) {  //归并 length 长的两个相邻子表
        funMerge(a, i, i + length - 1, i + 2 * length - 1);
    }
    if (i + length - 1 < n) {  //余下两个子表，后者的长度小于 length
        funMerge(a, i, i + length - 1, n - 1);
    }
}

/**
 * 二路归并算法
 * 自底向上
 */
void funMergeSort_downTop(int a[], int n) {
    int length;
    for (length = 1; length < n; length = 2 * length) {
        funMergePass(a, length, n);
    }
}

/**
 * 二路归并算法
 * 自顶向下
 */
void funMergeSort_topDown(int a[], int low, int high) {
    int mid;
    if (low < high) {            //子序列有两个或两个以上元素
        mid = (low + high) / 2;  //取中间位置
        funMergeSort_topDown(a, low, mid);  //对 a[low...mid] 子序列排序
        funMergeSort_topDown(a, mid + 1, high);  //对 [mid+1...high] 子序列排序
        funMerge(a, low, mid, high);  //将两个子序列合并，见前面的算法
    }
}
/*============================test============================*/

int main() {
    int arr1_int[] = {2, 5, 1, 7, 10, 6, 9, 4, 3, 8};
    int arr2_int[] = {2, 5, 1, 7, 10, 6, 9, 4, 3, 8};
    int arr3_int[] = {2, 5, 1, 7, 10, 6, 9, 4, 3, 8};
    int len = sizeof(arr1_int) / sizeof(int);

    cout << "quick sort, before sort:";
    disp(arr1_int, len);

    quickSort(arr1_int, 0, len - 1);
    cout << "quick sort, after sort:";
    disp(arr1_int, len);

    ///////////////////////////////////////////
    cout << "merge sort down-top, before sort:";
    disp(arr2_int, len);

    funMergeSort_downTop(arr2_int, len - 1);
    cout << "merge sort down-top, after sort:";
    disp(arr2_int, len);

    cout << "merge sort top-down, before sort:";
    disp(arr3_int, len);

    funMergeSort_topDown(arr3_int, 0, len - 1);
    cout << "merge sort top-down, after sort:";
    disp(arr3_int, len);

    return 0;
}