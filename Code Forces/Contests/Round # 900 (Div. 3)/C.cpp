#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool isPossible(ll n, ll k, ll sum)
{
    ll min_possible = (k * (k + 1)) / 2;
    ll max_possible = (k * (2 * n - k + 1)) / 2;
    if (sum >= min_possible && sum <= max_possible)
    {
        return true;
    }
    return false;
}

// bool isValid(ll &n, ll k, ll reqsum, ll curr){

//     // if(dp.count({reqsum, k})){
//     //     return dp[{reqsum,k}];
//     // }
//     if(reqsum == 0 && k == 0){
//         return true;
//     }

//     if(k < 0 || reqsum < 0 || curr > n){
//         return false;
//     }

//     bool a = isValid(n, k-1, reqsum-curr, curr+1);
//     bool b = isValid(n, k, reqsum, curr+1);
//     // dp[{reqsum,k}] = a || b;
//     return a || b;
//     // not including the current element
// }

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {

        // Contest Code
        // ll n;
        // ll k;
        // ll reqsum;
        // cin>>n>>k>>reqsum;

        // // if((k*(k+1))/2 > reqsum){
        // //     cout<<"NO"<<endl;
        // //     continue;
        // // }

        // map<pair<ll,ll>,bool> dp;
        // if(isValid(n, k, reqsum, 1)){
        //     cout<<"YES"<<endl;
        // }else{
        //     cout<<"NO"<<endl;
        // }

        // New Code
        ll n;
        ll k;
        ll reqsum;
        cin >> n >> k >> reqsum;

        if (isPossible(n, k, reqsum))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
