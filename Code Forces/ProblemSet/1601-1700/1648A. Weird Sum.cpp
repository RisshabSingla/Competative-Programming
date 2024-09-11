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

bool comp(pll &a, pll &b)
{
    return a.second < b.second;
}

int main()
{
    map<ll, vector<pll>> mp;
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll a;
            cin >> a;
            mp[a].push_back({i, j});
        }
    }

    ll ans = 0;
    for (auto i : mp)
    {
        vector<pll> arr = i.second;
        ll size = arr.size();
        sort(arr.begin(), arr.end());
        ll currSum = 0;
        for (auto i : arr)
        {
            currSum += i.first;
        }
        for (ll i = 0; i < size; i++)
        {
            currSum -= arr[i].first;
            ans += (currSum - (size - 1 - i) * (arr[i].first));
        }
        sort(arr.begin(), arr.end(), comp);
        currSum = 0;
        for (auto i : arr)
        {
            currSum += i.second;
        }
        for (ll i = 0; i < size; i++)
        {
            currSum -= arr[i].second;
            ans += (currSum - (size - 1 - i) * (arr[i].second));
        }
    }
    cout << ans << "\n";

    // map<ll, vector<pll>> mp;
    // ll n, m;
    // cin >> n >> m;
    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j < m; j++)
    //     {
    //         ll a;
    //         cin >> a;
    //         mp[a].push_back({i, j});
    //     }
    // }
    // map<ll, vector<ll>> costs;
    // ll ans = 0;
    // for (auto i : mp)
    // {
    //     vector<ll> arr;
    //     sort(i.second.begin(), i.second.end(), comp);
    //     pll p = i.second[0];
    //     // arr.push_back(0);
    //     for (auto j : i.second)
    //     {
    //         // cout << j.first << " " << j.second << "\n";
    //         arr.push_back(abs(p.first - j.first) + abs(j.second - p.second));
    //     }
    //     sort(arr.begin(), arr.end());
    //     // cout << "\n";
    //     ll len = arr.size();
    //     vector<ll> prefix(len + 1, 0);
    //     for (ll i = 1; i >= 0; i--)
    //     {
    //         prefix[i] = prefix[i - 1] + arr[i - 1];
    //     }

    //     for (ll i = 0; i < len; i++)
    //     {
    //         ll a = (prefix[i] - (arr[i] * (len - i)));
    //         ans += a;
    //         cout << "Added: " << a << "\n";
    //     }
    //     cout << "Number is: " << i.first << "\n";
    //     cout << "Arr is: ";
    //     for (auto i : arr)
    //     {
    //         cout << i << ' ';
    //     }
    //     cout << "\n";
    //     cout << "Suffix is: ";
    //     for (auto i : prefix)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << ans << "\n";

    return 0;
}