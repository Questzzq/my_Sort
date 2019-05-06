//
// Created by eric on 19-5-7.
//

#ifndef MY_SORT_MY_SORT_H
#define MY_SORT_MY_SORT_H

#include <vector>

void input_Array(std::vector<int> &nums, const int n);  // 输入


template <class T>
void my_Swap(T &num1, T &num2); // 交换

// 七种排序方法
void bubble_Sort(std::vector<int> &nums, const int n);
void select_Sort(std::vector<int> &nums, const int n);
void insert_Sort(std::vector<int> &nums, const int n);
void quick_Sort(std::vector<int> &nums, const int n);
void shell_Sort(std::vector<int> &nums, const int n);
void merge_Sort(std::vector<int> &nums, const int n);
void heap_Sort(std::vector<int> &nums, const int n);

void print_Array(std::vector<int> &nums, const int n); // 打印排序结果

#endif //MY_SORT_MY_SORT_H
