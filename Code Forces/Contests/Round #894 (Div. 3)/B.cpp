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
        vector<int> arr(n);
        
        for(int i =0; i<n; i++){
            cin>>arr[i];
        }
        vector<int> ans(2*n);
        ans[0] = arr[0];
        int index = 1;
        // cout<<arr[0]<<" ";
        for(int i = 1; i<n; i++){
            if(arr[i-1] <= arr[i]){
                ans[index] = arr[i];
                index++;
                // cout<<arr[i]<<" ";
            }else{
                ans[index] = min(arr[i-1], arr[i]);
                index++;
                ans[index] = arr[i];
                index++;
                // cout<<<<" ";
            }
        }
        cout<<index<<endl;
        for(int i = 0; i<index; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
