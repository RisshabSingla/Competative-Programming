#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

ll findSum(ll n)
{
    return ((n) * (n + 1)) / 2;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {

        ll n;
        cin >> n;
        vector<ll> arr(n);
        vector<ll> count(n + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            count[arr[i]]++;
        }
        sort(count.begin(), count.end(), greater<ll>());
        for (ll i = 1; i <= n; i++)
        {
            if (count[i] >= count[i - 1])
            {
                count[i] = max(0LL, count[i - 1] - 1);
            }
        }
        // for (auto i : count)
        // {
        //     cout << i << ' ';
        // }
        // cout << "\n";
        ll ans = 0;
        for (ll i = 0; i <= n; i++)
        {
            ans += count[i];
        }
        cout << ans << "\n";

        // ll n;
        // cin >> n;
        // vector<ll> arr(n);
        // unordered_map<ll, ll> mp;
        // for (ll i = 0; i < n; i++)
        // {
        //     cin >> arr[i];
        //     mp[arr[i]]++;
        // }
        // vector<ll> counts(n + 1, 0);
        // for (auto i : mp)
        // {
        //     counts[i.second]++;
        // }
        // // for (auto i : counts)
        // // {
        // //     cout << i << " ";
        // // }
        // // cout << "\n";
        // ll ans = 0;
        // ll add = 0;
        // ll start = n;
        // for (ll i = n; i >= 0; i--)
        // {
        //     // counts[i] += add;
        //     if (counts[i] + add == 0 || i == 0)
        //     {
        //         add = 0;
        //         ll sAns = findSum(start) - findSum(i);
        //         ans = max(ans, sAns);
        //         start = i - 1;
        //     }
        //     else
        //     {
        //         add += ((counts[i]) - 1);
        //         if (i - counts[i] >= 0)
        //         {
        //             counts[i - counts[i]] -= (counts[i] - 1);
        //         }
        //         // add--;
        //     }
        // }
        // // for (auto i : counts)
        // // {
        // //     cout << i << " ";
        // // }
        // // cout << "\n";
        // cout << ans << "\n";
    }
    return 0;
}