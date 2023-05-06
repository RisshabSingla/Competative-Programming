#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;


int main()
{
    int cases;
    cin>>cases;
    while(cases--){
        int n;
        cin>>n;
        int arr[n];
        map<int, int> freq;
        int lowest = INT_MAX;
        for(int i = 0; i<n; i++){
            cin>>arr[i];
            freq[arr[i]]++;
            lowest = min(lowest, arr[i]);
        }
        if(lowest == n){
            cout<<-1<<endl;
            continue;
        }
        





        // sort(arr,arr+n);
        // int first = arr[0];
        // if(first >=n){
        //     cout<<-1<<endl;
        //     continue;
        // }
        // // int liars = 0;
        // // for(int i = 0; i<n; i++){
        // //     if(arr[i]!= first){
        // //         liars++;
        // //     }
        // // }
        // // cout<<liars<<endl;
        // bool found = false;
        // for(int i = 0; i<n; i++){
        //     int liars = arr[i];
        //     int count = 0;
        //     int same = 0;
        //     for(int j = 0; j<n ; j++ ){
        //         if(i == j){
        //             continue;
        //         }
                
        //         if(liars != arr[j]){
        //             count++;
        //         }else{
        //             same++;
        //         }
        //     }
        //     if(liars == count-same){
        //         found = true;
        //         cout<<liars<<endl;
        //         break;
        //     }
        // }
        // if(!found){
        //     cout<<-1<<endl;
        // }
    }
    return 0;
}
