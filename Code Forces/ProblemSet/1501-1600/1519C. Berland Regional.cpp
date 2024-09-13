#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

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
        vector<ll> teams(n);
        vector<ll> skill(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> teams[i];
            teams[i]--;
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> skill[i];
        }

        vector<vector<ll>> mp(n + 1);
        for (ll i = 0; i < n; i++)
        {
            mp[teams[i]].push_back(skill[i]);
        }

        vector<vector<ll>> pref(n, vector<ll>(1, 0));
        for (ll i = 0; i < n; i++)
        {
            sort(mp[i].begin(), mp[i].end(), greater<ll>());
            for (auto j : mp[i])
            {
                pref[i].push_back(pref[i].back() + j);
            }
        }

        vector<ll> ans(n);
        for (ll i = 0; i < n; i++)
        {
            ll size = mp[i].size();
            for (ll k = 1; k <= size; k++)
            {
                ans[k - 1] += pref[i][(size / k) * k];
            }
        }

        // for (ll i = 0; i < n; i++)
        // {
        //     sort(mp[i].begin(), mp[i].end(), greater<ll>());
        //     // ll size = mp[i].size();
        //     // for (ll j = size - 2; j >= 0; j--)
        //     // {
        //     //     mp[i][j] = mp[i][j + 1] + mp[i][j];
        //     // }
        // }

        // vector<ll> ans(n);
        // for (ll i = 1; i <= n; i++)
        // {
        //     ll count = 0;
        //     for (ll j = 0; j < n; j++)
        //     {
        //         ll size = mp[j].size();
        //         if (size == 0)
        //         {
        //             continue;
        //         }
        //         ll ignore = size % i;
        //         if (size - ignore < 0)
        //         {
        //             cout << "NO\n";
        //             continue;
        //         }
        //         if (ignore == 0)
        //         {
        //             count += mp[j][0];
        //         }
        //         else
        //         {
        //             count += (mp[j][0] - mp[j][size - ignore]);
        //         }
        //     }
        //     ans[i - 1] = count;
        //     if (count == 0)
        //     {
        //         break;
        //     }
        // }

        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";

        // for (auto i : mp)
        // {
        //     cout << i.first << " : ";
        //     for (auto j : i.second)
        //     {
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }
    return 0;
}