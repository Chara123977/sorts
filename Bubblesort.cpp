#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) ;

int main(void){
    int tmp;
    vector<int> arr;
    cout << "输入数组元素:"
        << endl;
    while(1){
        cin >> tmp;
        if(tmp != -1)
        arr.push_back(tmp);
        else
        break;
    }
    bubbleSort(arr);
    cout << "排序后的数组:"
        << endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}

void bubbleSort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}