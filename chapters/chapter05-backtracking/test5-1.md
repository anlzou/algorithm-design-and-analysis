<!--
 * @Date        : 2020-05-02 20:37:47
 * @LastEditors : anlzou
 * @Github      : https://github.com/anlzou
 * @LastEditTime: 2020-06-05 17:43:00
 * @FilePath    : \algorithm-design\chapters\chapter05-backtracking\test5-1.md
 * @Describe    : 
 -->
 
## 题目地址
8.1 回溯法概述

## 题目描述

问题：
```
#1

使用回溯法非递归求解下列象棋算式中不同的棋子代表的数值
        兵 炮 马 卒
   +    兵 炮 车 卒
   ————————————————
     车 卒 马 兵 卒
```

## 思路
非递归回溯框架
```cpp
int x[x];                                          // x存放解向量，全局变量
void backtrack(int n){                             // 非递归框架
    int i = 1;                                     // 根结点层次为 1
    while(i >= 1){                                 // 尚未回溯到头
        if(ExisSubNode(t)){                        // 当前结点存在子结点
            for(j = 下界; j <= 上界; j++){          // 对于子集树，j从0到1循环
                x[i]取一个可能的值;
                if(constraint(i) && bound(i)){     // x[i]满足约束条件或界限函数
                    if(x是一个可行解)
                        输出 ;
                    else i++;                      // 进入下一层
                }
            }
        }else i--;                                 // 不存在子结点，返回上一层，即回溯
    }
}
```
说明：算法中的变量 i 十分重要，它对应解空间的第 i 层的某个结点，也就是为整个解向量 X 的第 i 步选择一个合适的分量 xi。

#1

这里的解向量为 (a,b,c,d,e)，分别表示兵、炮、马、卒和车的取值。

采用多重循环来试探各棋子不同的取值情况，逐一判断它们是否满足算式的条件；为了避免同一数字被重复使用，可设立布尔数组 dig，当 dig[i](0 <= i <= 9)值为 0 时表示数字 i 没有被使用，为 1 时表示数字 i 已经被使用。

例如对于棋子兵，先试探它取值 a，让 dig[a] = 1 表示其它棋子不能再取值 a，继续其它棋子的试探，当不成功（放弃当前候选解）或输出一个解（找到一个解）后进行回溯，让 dig[a] = 0 表示其它棋子可以取值 a，即再试探其它候选解。

## 关键点
- **解空间**(solution space) ≡ **解空间树** ≡ **状态空间树**(state space tree)

## 补充
<code>memset()</code>

语法:
```cpp
  #include <string.h>
  void *memset( void *buffer, int ch, size_t count );
```
功能: 函数拷贝ch 到buffer 从头开始的count 个字符里, 并返回buffer指针。 memset() 可以应用在将一段内存初始化为某个值。例如：
```cpp
    memset( the_array, '\0', sizeof(the_array) );
```
这是将一个数组的所以分量设置成零的很便捷的方法。

## 代码
- [exp5-1.cpp](./code/exp5-1.cpp)

## 复杂度分析

- 时间复杂度：O( )
- 空间复杂度：O( )