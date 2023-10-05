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
        vector<ll> arr(n);
        vector<ll>prefix(n+1);
        for(int i = 0; i<n; i++){
            cin>>arr[i];
            prefix[i+1] = arr[i];
            prefix[i+1] = prefix[i+1] xor prefix[i];
        }
        string str;
        cin>>str;
        ll slen = str.length();
        ll xr = 0;
        for(ll i = 0; i<slen; i++){
            if(str[i] == '1'){
                xr = xr xor arr[i];
            }   
        }
        ll q;
        cin>>q;
        while(q--){
            ll a;
            cin>>a;
            if(a == 2){
                ll b;
                cin>>b;
                if(b == 0){
                    cout<<(xr xor prefix[n])<<" ";
                }else{
                     cout<<xr<<" ";
                }
                // cout<<ans<<" ";
            }else{
                ll b;
                ll c;
                cin>>b>>c;
                // b--;
                // c--;
                xr = xr xor(prefix[c] xor prefix[b-1]);
                // cout<<"\nString is: "<<str<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
