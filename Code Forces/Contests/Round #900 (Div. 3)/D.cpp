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
        // After contest
        int n,k;
        cin>>n>>k;
        string str;
        cin>>str;
        vector<int> l(k);
        vector<int>r(k);
        for(int i = 0; i<k; i++){
            cin>>l[i];
            l[i]--;
        }
        for(int i = 0; i<k; i++){
            cin>>r[i];
            r[i]--;
        }

        int q;
        cin>>q;
        while(q--){
            int x;
            cin>>x;
            x--;
            int index = -1;
            for(int i = 0; i<k; i++){
                if(l[i]<=x && x<=r[i]){
                    index = i;
                    break;
                }
            }
            // index++;
            // cout<<"index: "<<index<<endl;
            int a = min(x, r[index]+l[index]-x);
            int b = max(x, r[index]+l[index]-x);
            reverse(str.begin()+a+1, str.begin()+b+1);
        }
        cout<<str<<endl;


        // vector<ll> queries[k];
        // vector<ll> swaps(n,0);

        // while(q--){
        //     ll x;
        //     cin>>x;
        //     x--;
        //     auto itr = upper_bound(l.begin(), l.end(), x);
        //     itr--;
        //     ll index = itr - l.begin();
        //     queries[index].push_back(x);
        // }

        
        // for(ll i = 0; i<k; i++){
        //     for(auto j: queries[i]){
        //         ll a = min(j, l[i]+r[i]-j);
        //         ll b = max(j, l[i]+r[i]-j);
        //         swaps[a]++;
        //         swaps[b]--;
        //     }
        // }
        

    }
    return 0;
}
