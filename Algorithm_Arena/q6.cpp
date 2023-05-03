#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;


const int mod = 1000000007;


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    // int capacity = 0;
    // int first = -1;
    // int firstindex = -1;
    // int second = -1;
    // int secondindex = -1;
    // for(int i = 0; i<n; i++){
    //     if(arr[i] != 0){
    //         if(first == -1){
    //             first = arr[i];
    //             firstindex = i;
    //         }else{
    //             second = arr[i];
    //             secondindex = i;
    //             if(secondindex-firstindex>1){
    //                 capacity+=min(first,second)*(secondindex-firstindex);
    //             }
    //             first = second;
    //             firstindex = secondindex;
    //         }
    //     }
    // }
    // cout<<capacity<<endl;

    int left[n];
    int right[n];
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    for(int i =1; i<n; i++){
        left[i]= max(left[i-1], arr[i]);
    }
     for(int i =n-2; i>=0; i--){
        right[i]= max(right[i+1], arr[i]);
    }

    int capacity = 0;
    for(int i = 1; i<n-1; i++){
        int cap = min(left[i-1], right[i+1]);
        if(cap > arr[i]){
            capacity+=(cap-arr[i]);
        }
    }
    cout<<capacity<<endl;



    return 0;
}