#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    // unordered_map<int, int> mp;
    // for (int i = 0; i < n; i++)
    // {
    //     for (auto j : mp)
    //     {
    //         mp[j.first + arr[i]]++;
    //     }
    //     mp[arr[i]]++;
    // }
    // ll ans = 1;
    // while (mp.count(ans))
    // {
    //     ans++;
    // }
    // cout << ans << "\n";
    ll target = 1;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] > target)
        {
            break;
        }
        target += arr[i];
    }
    cout << target << "\n";
    return 0;
}