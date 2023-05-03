#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool findIndex(int* arr, int size, int &index){
    for(int i=0; i< size; i++){
        if(arr[i] == -1){
            index = i;
            return true;
        }
    }
    index = -1;
    return false;
}



int main()
{
    int cases;
    cin>>cases;
    while(cases--){
        int n;
        int x;
        cin>>n>>x;
        int arr[n];
        bool present[n];
        for(int i = 0; i<n; i++){
            present[i] = false;
            arr[i] = -1;
        }
        present[1-1] = true;
        present[x-1] = true;
        arr[n-1] = 1;
        arr[0] = x;
        int filled = 2;
        while(filled!=n){
            int index;
            if(findIndex(arr,n,index)){
                
            }
        }

    }
    return 0;
}