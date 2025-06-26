#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(std::vector<int>& arr, int low, int high);
int partition(std::vector<int>& arr, int low, int high);

int main() {
    std::vector<int> arr = {19,56,64,545,32,16,48,66,483,15};
    quickSort(arr, 0, arr.size() - 1);
    
    std::cout << "����������: ";
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
    int pivot = arr[high]; // ѡ�����ұߵ�Ԫ����Ϊ��׼
    int i = low - 1; // i ��ʾС�ڻ�׼��Ԫ�ص����һ��λ��
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]); // ����Ԫ��
        }
    }
    
    std::swap(arr[i + 1], arr[high]); // �ѻ�׼Ԫ�طŵ���ȷ��λ��
    return i + 1; // ���ػ�׼Ԫ�ص�����
}
