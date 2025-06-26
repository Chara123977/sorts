#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(std::vector<int>& arr, int low, int high);
int partition(std::vector<int>& arr, int low, int high);

int main() {
    std::vector<int> arr = {19,56,64,545,32,16,48,66,483,15};
    quickSort(arr, 0, arr.size() - 1);
    
    std::cout << "排序后的数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 选择最右边的元素作为基准
    int i = low - 1; // i 表示小于基准的元素的最后一个位置
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]); // 交换元素
        }
    }
    
    std::swap(arr[i + 1], arr[high]); // 把基准元素放到正确的位置
    return i + 1; // 返回基准元素的索引
}
