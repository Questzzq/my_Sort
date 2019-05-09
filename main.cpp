#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include "MY_SORT.h"
using namespace std;

// 模板
template<typename T>
void input_Array(vector<T> &nums, const int n) {
    T tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
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
template<typename T>
void bubble_Sort(std::vector<T> &nums, const int n) {
    for(int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] > nums[j])
                my_Swap(nums[i], nums[j]);
        }
    }
}

// n 个数的数组只要进行 n 次的挑出最小的那个数到最前面就完成了排序
template<typename T>
void select_Sort(std::vector<T> &nums, const int n) {
    T my_Min = nums[0];
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
template<typename T>
int binary_Search(std::vector<T> &nums, int n, T value) {
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

template<typename T>
void insert_Sort(std::vector<T> &nums, const int n) {
    T tmp;
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

/*
 * 功能: 递归实现快速排序
 * 参数: head: 数组首下标元素 | tail: 数组末下i标元素
 * 返回值: 无
 */
template<typename T>
void quick_Sort(std::vector<T> &nums, int left, int right) {
    int i, j;
    T pivot;
    if(left >= right) return;

    pivot = nums[left]; // 一般取第一个作为基准
    i = left;
    j = right;

    while(i != j) {
        // 顺序很主要, 要从右边开始找
        while((i < j) && (nums[j] >= pivot)) j--;
        if(i < j) {
            my_Swap(nums[i], nums[j]);
            i++;
        }
        while((i < j) && (nums[i] <= pivot)) i++;
        if(i < j) {
            my_Swap(nums[i], nums[j]);
            j--;
        }
        // 最后将基数归位
        nums[i] = pivot;
        quick_Sort(nums, left, i - 1);
        quick_Sort(nums, i + 1, right);
    }
}

// 归并排序
template<typename T>
void merge_Sort(vector<T> &data, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_Sort(data, start, mid);
        merge_Sort(data, mid + 1, end);
        my_Merge(data, start, mid, end);
    }
}

template<typename T>
void my_Merge(vector<T> &data, int start, int mid, int end) {
    vector<T> tmp;
    int i = start, j = mid + 1;
    while (i != mid + 1 && j != end + 1) {
        if (data[i] <= data[j]) {
            tmp.push_back(data[i++]);
        } else {
            tmp.push_back(data[j++]);
        }
    }
    while (i != mid + 1) {
        tmp.push_back(data[i++]);
    }
    while (j != end + 1) {
        tmp.push_back(data[j++]);
    }
    for (int i = 0; i < tmp.size(); i++) {
        data[start + i] = tmp[i];
    }
}

/*
 * 希尔排序：先取一个小于n的整数d1作为第一个增量，
 * 把文件的全部记录分成（n除以d1）个组。所有距离为d1的倍数的记录放在同一个组中。
 * 先在各组内进行直接插入排序；然后，取第二个增量d2<d1重复上述的分组和排序，
 * 直至所取的增量dt=1(dt<dt-l<…<d2<d1)，即所有记录放在同一组中进行直接插入排序为止。
 */
template<typename T>
void shell_Insert_Sort(std::vector<T> &nums, int start, int inc) {
    for (int i = start + inc; i < nums.size(); i += inc) {
        for (int j = i; (j >= inc) && (nums[j] < nums[j - inc]); j -= inc) {
            my_Swap(nums[j], nums[j - inc]);
        }
    }
}

template<typename T>
void shell_Sort(std::vector<T> &nums, const int n) {
    int j, gap;
    for(gap = n / 2; gap > 0; gap /= 2) {
        for(j = 0; j < gap; j++) {
            shell_Insert_Sort(nums, j, gap);
        }
    }
    shell_Insert_Sort(nums, 0, 1);
}

template<typename T>
void heap_Sort(std::vector<T> &nums, const int n);

template<typename T>
void print_Array(vector<T> &nums, const int len) {
    for(int i = 0; i < len; i++)
        cout << nums[i] << " ";
    cout << endl;
}

/*
 * 产生 [a, b] 之间的 n 个随机整数
 */
template<typename T>
void random_Input(std::vector<T> &nums, const int n, int a, int b) {
    srand((int)time(NULL));
    for(int i = 0; i < n; i++)
        nums.push_back(rand() % (b - a + 1) + a);
}

void print_Line(const int n) {
    for(int i = 0; i < 2 * n; i++)
        cout << "-";
    cout << endl;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b; // 输入测试数组的大小, 数组元素的值的范围, 将随机初始化数组
    vector<int> nums;
    nums.reserve(n);
    random_Input(nums, n, a, b);
    print_Array(nums, n);
    print_Line(n);
    vector<int> nums1;
    nums1.reserve(n);
    vector<int> nums2;
    nums2.reserve(n);
    vector<int> nums3;
    nums3.reserve(n);
    vector<int> nums4;
    nums4.reserve(n);
    vector<int> nums5;
    nums5.reserve(n);
    vector<int> nums6;
    nums6.reserve(n);

    // nums1~nums6 分别调用 6 种排序函数, 所以初始化一样的元素
    for(int i = 0; i < n; i++) {
        nums1.push_back(nums[i]);
        nums2.push_back(nums[i]);
        nums3.push_back(nums[i]);
        nums4.push_back(nums[i]);
        nums5.push_back(nums[i]);
        nums6.push_back(nums[i]);
    }

    bubble_Sort(nums1, n);
    print_Array(nums1, n);
    select_Sort(nums2, n);
    print_Array(nums2, n);
    insert_Sort(nums3, n);
    print_Array(nums3, n);
    quick_Sort(nums4, 0, n - 1);
    print_Array(nums4, n);
    merge_Sort(nums5, 0, n - 1);
    print_Array(nums5, n);
    shell_Sort(nums6, n);
    print_Array(nums6, n);
    return 0;
}
