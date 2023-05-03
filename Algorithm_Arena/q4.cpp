#include <iostream>
#include<algorithm>

using namespace std;


int main(){
    int n;
    int k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i<n; i++){
        arr[i] = 1;
    }
    int index = 0;
    int size = n;

    while(n>1){
        int to_be_killed = index+k-1;
        if(to_be_killed >=size){
            to_be_killed-=size;
        }
        if(arr[to_be_killed] == 1){
            arr[to_be_killed] = 0;
            index = to_be_killed +1;
            if(index == size){
                index = 0;
            }
            n--;
        }else{
            while(arr[to_be_killed] != 1){
                to_be_killed ++;
                if(to_be_killed == size){
                    to_be_killed = 0;
                }
            }
        }
    }

    for(int i =0; i<size; i++){
        if(arr[i]== 1){
            cout<<i+1<<endl;
            break;
        }
    }
    return 0;
}