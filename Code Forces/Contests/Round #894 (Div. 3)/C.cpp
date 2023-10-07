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

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        // int n;
        // cin >> n;

        // Brute Force
        // vector<int> vert(n);
        // int max_height = 0;
        // for(int i = 0; i<n; i++){
        //     cin>>vert[i];
        //     max_height = max(max_height, vert[i]);
        // }
        // vector<int> hor(n);
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<vert[i]; j++){
        //         hor[j]++;
        //     }
        // }

        // bool broken = false;
        // for(int i = 0; i<n; i++){
        //     if(vert[i] != hor[i]){
        //         cout<<"NO"<<endl;
        //         broken = true;
        //         break;
        //     }
        // }
        // if(!broken){
        //     cout<<"YES"<<endl;
        // }

        // for(auto i: vert){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        // for(auto i: hor){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (n != arr[0])
        {
            cout << "NO" << endl;
            continue;
        }

        vector<ll> hort(n + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            hort[arr[i]]++;
        }

        for (ll i = n - 1; i > 0; i--)
        {
            hort[i] += hort[i + 1];
        }

        bool broken = false;
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] != hort[i + 1])
            {
                cout << "NO" << endl;
                broken = true;
                break;
            }
        }
        if (!broken)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
