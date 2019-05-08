//
// Created by eric on 19-5-7.
//

#ifndef MY_SORT_MY_SORT_H
#define MY_SORT_MY_SORT_H

#include <vector>

void print_Line(const int n); // 打印一行线作为分隔

template<typename T>
void print_Array(std::vector<T> &nums, const int n); // 打印排序结果

template<typename T>
void random_Input(std::vector<T> &nums, const int n, int a, int b); // 随机输入测试样例

template <class T>
void input_Array(std::vector<T> &nums, const int n);  // 手动输入测试样例

template <class T>
void my_Swap(T &num1, T &num2); // 交换

template <class T>
int binary_Search(std::vector<T> &nums, int n, T value); // 基于二分查找寻找插入位置

// 七种排序方法
template <class T>
void bubble_Sort(std::vector<T> &nums, const int n); // 冒泡

template <class T>
void select_Sort(std::vector<T> &nums, const int n); // 选择

template <class T>
void insert_Sort(std::vector<T> &nums, const int n); // 直接插入

template<typename T>
void quick_Sort(std::vector<T> &nums, int left, int right); // 快速排序

template<typename T>
void my_Merge(std::vector<T> &nums, int start, int mid, int end);

template<typename T>
void merge_Sort(std::vector<T> &nums, int start, int end); // 归并排序

template<typename T>
void shell_Insert_Sort(std::vector<T> &nums, int start, int inc); // 希尔排序
template<typename T>
void shell_Sort(std::vector<T> &nums, const int n);

template<typename T>
void heap_Sort(std::vector<T> &nums, const int n); // 堆排序

#endif //MY_SORT_MY_SORT_H
