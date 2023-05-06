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
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        int max_count = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(arr[i] ==1){
                max_count = max(max_count, count);
                count=0;
            }else{
                count++;
                max_count = max(max_count, count);
            }
        }
        cout<<max_count<<endl;

    }
    return 0;
}
