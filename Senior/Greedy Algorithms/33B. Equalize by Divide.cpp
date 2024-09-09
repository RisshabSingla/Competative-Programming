#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        map<ll, vector<ll>> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]].push_back(i);
        }
        if (mp.count(1) && mp.size() > 1)
        {
            cout << -1 << "\n";
            continue;
        }
        vector<pll> opr;
        while (mp.size() > 1)
        {
            ll mini = mp.begin()->first;
            ll maxi = prev(mp.end())->first;
            ll num = (maxi) / mini;
            if (maxi % mini)
            {
                num++;
            }
            for (auto i : mp[maxi])
            {
                mp[num].push_back(i);
                opr.push_back({i, mp[mini][0]});
            }
            mp.erase(maxi);
        }
        cout << opr.size() << "\n";
        for (auto i : opr)
        {
            cout << i.first + 1 << " " << i.second + 1 << "\n";
        }
        // cout << "\n";
    }
    return 0;
}