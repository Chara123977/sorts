#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void countingsort(queue<int> arr,vector<int>& target,int max_num);

int main(void){
    queue<int> arr1;
    int n=0,temp=0;
    cout<<"��������Ԫ��:";
    while(1){
        cin>>n;
        if(n == -1) 
            break;
        if(n>temp) 
            temp=n;
        arr1.push(n);
    }
    vector<int> target;
    countingsort(arr1,target,temp);
}

//ע�� :�˼���������ֻ������ܷǸ�����������Ϊ���� ����Ҫ���ܸ�����������Ҫ��¼��Сֵ������
void countingsort(queue<int> arr,vector<int>& target,int max_num){
    int index[max_num+1]={0};   
    while(!arr.empty()){
        int tmp = arr.front();
        arr.pop();
        index[tmp]++;
    }
    int i=0;
    while(i<=max_num){
        while(index[i]!=0){
            target.push_back(i);
            index[i]--;
        }
        i++;
    }
    for(int i = 0; i < target.size(); i++){
        cout << target[i] << " ";
    }
}