#include <iostream>
#include <vector>
using namespace std;

void selectsort(vector<int>& arr);

int main(void){
    int temp;
    vector<int> arr;
    cout<<"��������Ԫ��:";
    while (1){
        cin>>temp;
        if (temp==-1) break;
        arr.push_back(temp);
    }
    selectsort(arr);
}

void selectsort (vector<int>& arr){
    int curr;
    for (int i=0; i<arr.size()-1; i++){
        curr = i;
        for(int j=i; j<arr.size(); j++){
            if (arr[j]<arr[curr])
                curr = j;
        }
        swap(arr[i], arr[curr]);
    }
    cout<<"����������:";
    for (int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}