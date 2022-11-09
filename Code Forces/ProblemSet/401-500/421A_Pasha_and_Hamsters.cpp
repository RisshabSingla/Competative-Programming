#include<iostream>
using namespace std;

int main()
{
    int number;
    int arthurLikesNum;
    int alexLikesNum;
    cin>>number>>arthurLikesNum>>alexLikesNum;
    int *arr = new int[number];
    for(int i = 0; i<arthurLikesNum; i++){
        int t;
        cin>>t;
        arr[t-1] = 1;
    }
    // for(int i = 0; i<number;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<"array after"<<endl;
    for(int i = 0; i<alexLikesNum; i++){
        int t;
        cin>>t;
        arr[t-1] = 2;
    }
    for(int i = 0; i<number;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
