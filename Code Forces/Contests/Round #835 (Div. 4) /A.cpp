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
    int cases;
    cin>>cases;
    while(cases--){
        vector<int> arr ;
        for(int i =0; i<3; i++){
            int t;
            cin>>t;
            arr.push_back(t);
        }
        sort(arr.begin(), arr.end());
        cout<<arr[1]<<endl;
    }
    return 0;
}
