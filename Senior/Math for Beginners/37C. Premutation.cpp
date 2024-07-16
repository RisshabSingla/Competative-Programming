#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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

        ll n;
        cin >> n;
        vector<vector<ll>> arr(n, vector<ll>(n - 1));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n - 1; j++)
            {
                cin >> arr[i][j];
            }
        }

        vector<ll> ans;
        map<ll, ll> mp;
        ll nxt = -1;
        for (ll i = 0; i < n; i++)
        {
            mp[arr[i][0]]++;
        }

        for (auto i : mp)
        {
            if (i.second == (n - 1))
            {
                ans.push_back(i.first);
            }
            else
            {
                nxt = i.first;
            }
        }
        ans.push_back(nxt);

        for (ll j = 1; j < n - 1; j++)
        {
            ll prev = nxt;
            for (ll i = 0; i < n; i++)
            {
                if (arr[i][j] != prev)
                {
                    nxt = arr[i][j];
                }
            }
            ans.push_back(nxt);
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
        // ll n;
        // cin >> n;
        // map<pair<ll, ll>, ll> mp;
        // map<ll, ll> start;
        // for (ll i = 0; i < n; i++)
        // {
        //     ll prev;
        //     cin >> prev;
        //     start[prev]++;
        //     for (ll j = 2; j < n; j++)
        //     {
        //         ll t;
        //         cin >> t;
        //         mp[{prev, t}]++;
        //         prev = t;
        //     }
        // }
        // ll starting = 0;
        // for (auto i : start)
        // {
        //     if (i.second == n - 1)
        //     {
        //         starting = i.first;
        //     }
        // }
        // map<ll, ll> order;
        // for (auto i : mp)
        // {
        //     // cout << i.first.first << " " << i.first.second << " : " << i.second << "\n";
        //     if (i.second == n - 2)
        //     {
        //         order[i.first.first] = i.first.second;
        //     }
        // }

        // // cout << "\n";

        // // for (auto i : order)
        // // {
        // //     cout << i.first << " " << i.second << "\n";
        // // }
        // // cout << "\n";
        // while (order.count(starting))
        // {
        //     cout << starting << " ";
        //     starting = order[starting];
        // }
        // cout << starting << "\n";
    }
    return 0;
}