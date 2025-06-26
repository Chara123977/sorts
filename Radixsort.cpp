#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

void radixsort(vector<int>& arr, int count);

int main(void) {
    vector<int> arr;
    int n;
    cout << "请输入数组元素（输入-1结束）:";
    
    while (true) {
        cin >> n;
        if (n == -1)
            break;
        if (cin.fail()) {
            cin.clear(); // 清除错误标志
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误输入
            cout << "请输入一个有效的整数。" << endl;
            continue; // 继续循环，等待下一个输入
        }

        arr.push_back(n);
    }

    // 如果数组为空，直接返回
    if (arr.empty()) {
        cout << "输入的数组为空。" << endl;
        return 0;
    }

    // 计算最大的位数
    int maxVal = *max_element(arr.begin(), arr.end());
    int count = 0;
    while (maxVal != 0) {
        count++;
        maxVal /= 10;
    }

    radixsort(arr, count);
}

void radixsort(vector<int>& arr, int count) {
    if (count <= 0) {
        return;
    }

    vector<vector<int>> temp(10); // 用一个二维向量替代动态数组

    // 按位分配
    for (int exp = 1; exp <= count; exp++) {
        for (int num : arr) {
            int index = (num / static_cast<int>(pow(10, exp - 1))) % 10;
            temp[index].push_back(num);
        }

        // 收集结果
        arr.clear();
        for (const auto& bucket : temp) {
            arr.insert(arr.end(), bucket.begin(), bucket.end());
        }

        // 清空临时数组
        for (auto& bucket : temp) {
            bucket.clear();
        }
    }
}
