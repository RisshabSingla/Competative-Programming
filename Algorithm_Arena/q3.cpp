#include <iostream>
#include<algorithm>

using namespace std;


int main(){
    int n;
    cin>>n;
    int arr[n];
    int ans[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        ans[i] = 0;
    }

    for(int i = 0; i<n; i++){
        int count = 0;
        for(int j =i; j>=0; j--){
            if(arr[j] <=arr[i]){
                count++;
            }else{
                break;
            }
        }
        ans[i] = count;
    }

    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}