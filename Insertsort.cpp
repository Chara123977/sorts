#include <iostream>
#include <vector>
using namespace std;

void insertsort(vector<int> &arr);

int  main(void){
    int temp;
    vector<int> arr;
    cout<<"��������Ԫ��:";
    while(1){
        cin>>temp;
        if(temp==-1) break;
        arr.push_back(temp);
    }
    insertsort(arr);
}

void insertsort(vector<int> &arr){
    for(int i = 0;i<arr.size();i++){
        int temp=arr[i];
        int j=i;
        while(j>0 && arr[j-1]>temp){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=temp;
    }
    cout<<"����������:";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
