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

// bool comp(pair<ll, ll> &a, pair<ll, ll> &b)
// {
//     ll m1 = a.first * a.second;
//     ll m2 = b.first * b.second;

//     return m1 > m2;
// }

ll solve(map<ll, ll> &mp, ll n, ll money)
{
    ll ans = 0;
    for (auto &i : mp)
    {
        ll p1 = i.first;
        ll q1 = i.second;
        ll count1 = money / p1;

        ll petals = 0;
        ll t1 = min(count1, q1);
        petals += t1 * p1;

        ll remM = money - t1 * p1;

        if (mp.count(p1 + 1))
        {
            ll q2 = mp[p1 + 1];
            ll count2 = remM / (p1 + 1);

            ll t2 = min(count2, q2);

            petals += t2 * (p1 + 1);
            remM -= (t2 * (p1 + 1));

            if (remM > 0)
            {
                if (q2 > t2)
                {
                    ll diff = q2 - t2;
                    ll canTake = min(remM, diff);
                    petals += min(t1, canTake);
                }
            }
        }
        ans = max(ans, petals);
    }
    return ans;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, m;
        cin >> n >> m;
        vector<pair<ll, ll>> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i].first;
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i].second;
        }
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            mp[arr[i].first] = arr[i].second;
        }

        ll ans = solve(mp, n, m);
        cout << ans << "\n";

        // sort(arr.begin(), arr.end());
        // for (auto i : arr)
        // {
        //     cout << i.first << " " << i.second << "\n";
        // }
        // cout << "\n";

        // ll maxi = 0;

        // for (ll i = 0; i < n; i++)
        // {
        //     ll quan = m / arr[i].first;
        //     quan = min(quan, arr[i].second);
        //     maxi = max(maxi, quan * arr[i].first);
        // }
        // // cout << " maxi: " << maxi << "\n";
        // for (ll i = 1; i < n; i++)
        // {
        //     if (arr[i].first - arr[i - 1].first > 1)
        //     {
        //         continue;
        //     }
        //     ll r1 = m / arr[i - 1].first;
        //     ll r2 = m / arr[i].first;
        //     ll q1 = min(arr[i - 1].second, r1);
        //     ll q2 = min(arr[i].second, r2);
        //     // cout << "q1: " << q1 << " q2: " << q2 << "\n";
        //     for (ll j = q1; j > 0; j--)
        //     {
        //         for (ll k = q2; k > 0; k--)
        //         {
        //             ll c = (arr[i - 1].first * j) + (arr[i].first * k);
        //             // cout << " Cost is: " << c << " j: " << j << " k: " << k << "\n";
        //             if (c <= m)
        //             {
        //                 // cout << "Changed\n";
        //                 maxi = max(maxi, c);
        //                 break;
        //             }
        //         }
        //     }
        // }
        // cout << maxi << "\n";
    }
    return 0;
}
