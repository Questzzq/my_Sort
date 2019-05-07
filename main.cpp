#include <iostream>
#include <cstdio>
#include "MY_SORT.h"
using namespace std;

void input_Array(vector<int> &nums, const int n) {
    int tmp;
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        nums.push_back(tmp);
    }
}

template <class T>
void my_Swap(T &num1, T &num2) {
    T tmp;
    tmp = num1;
    num1 = num2;
    num2 = tmp;
}

// n 个数要比较 n - 1 趟
void bubble_Sort(std::vector<int> &nums, const int n) {
    for(int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (nums[i] > nums[j])
                my_Swap(nums[i], nums[j]);
        }
    }
}

// n 个数的数组只要进行 n 次的挑出最小的那个数到最前面就完成了排序
// 0x3f3f3f3f 的 10 进制是 106110967, 也就是 10^9 级别, 而一般情况概况下数据都小于它
void select_Sort(std::vector<int> &nums, const int n) {
    auto my_Min = 0x3f3f3f3f;
    for(int i = 0; i < n; i++) {
        my_Min = nums[i];
        for(int j = i + 1; j < n; j++) {
            if(my_Min > nums[j])
                my_Swap(my_Min, nums[j]);
        }
        nums[i] = my_Min;
    }
}

// 返回应该插入的位置
int binary_Search(std::vector<int> &nums, int n, int value) {
    int left = 0;
    int right = n - 1;
    int mid = 0;
    while(left <= right) {
        mid = left + ((right - left) >> 1);
        if(nums[mid] > value)
            right--;
        else if(nums[mid] < value)
            left++;
        else return mid;
    }
    return mid;
}

void insert_Sort(std::vector<int> &nums, const int n) {
    int tmp;
    int position;
    for(int i = 0; i < n; i++) {
        tmp = nums[i];
        position = binary_Search(nums, i + 1, tmp);
        for(int j = i; j > position; j--) {
            nums[j] = nums[j - 1];
        }
        nums[position] = tmp;
    }
}

void quick_Sort(std::vector<int> &nums, const int n) {

}

void shell_Sort(std::vector<int> &nums, const int n);
void merge_Sort(std::vector<int> &nums, const int n);
void heap_Sort(std::vector<int> &nums, const int n);

void print_Array(vector<int> &nums, const int len) {
    for(int i = 0; i < len; i++)
        printf("%d ", nums[i]);
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
//    cout << nums.size() << endl;
    nums.reserve(n);
//    cout << nums.capacity() << endl;
//    cout << nums.size() << endl;
    input_Array(nums, n);
//    bubble_Sort(nums, n);
//    select_Sort(nums, n);
    insert_Sort(nums, n);
    print_Array(nums, n);
    return 0;
}