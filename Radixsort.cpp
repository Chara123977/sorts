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
    cout << "����������Ԫ�أ�����-1������:";
    
    while (true) {
        cin >> n;
        if (n == -1)
            break;
        if (cin.fail()) {
            cin.clear(); // ��������־
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���Դ�������
            cout << "������һ����Ч��������" << endl;
            continue; // ����ѭ�����ȴ���һ������
        }

        arr.push_back(n);
    }

    // �������Ϊ�գ�ֱ�ӷ���
    if (arr.empty()) {
        cout << "���������Ϊ�ա�" << endl;
        return 0;
    }

    // ��������λ��
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

    vector<vector<int>> temp(10); // ��һ����ά���������̬����

    // ��λ����
    for (int exp = 1; exp <= count; exp++) {
        for (int num : arr) {
            int index = (num / static_cast<int>(pow(10, exp - 1))) % 10;
            temp[index].push_back(num);
        }

        // �ռ����
        arr.clear();
        for (const auto& bucket : temp) {
            arr.insert(arr.end(), bucket.begin(), bucket.end());
        }

        // �����ʱ����
        for (auto& bucket : temp) {
            bucket.clear();
        }
    }
}
