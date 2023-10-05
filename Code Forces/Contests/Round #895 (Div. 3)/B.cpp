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
        ll n;
        cin>>n;
        
        vector<pair<ll,ll>> traps(n);
        for(ll i = 0; i<n; i++){
            ll a,b;
            cin>>a>>b;
            traps[i] = {a,b};
        }

        sort(traps.begin(), traps.end());
        ll total_steps = traps[0].first + (traps[0].second-1)/2;
        for(ll i = 1; i<n; i++){
            ll steps = traps[i].first + (traps[i].second-1)/2;
            total_steps = min(total_steps, steps);
        }

        cout<<max(total_steps, 1LL)<<endl;
        
    }
    return 0;
}
