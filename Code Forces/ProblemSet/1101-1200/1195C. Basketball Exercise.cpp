#include <iostream>
#include <vector>
#include <algorithm>

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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> brr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> brr[i];
    }
    vector<ll> dp1(n, 0);
    vector<ll> dp2(n, 0);
    dp1[0] = arr[0];
    dp2[0] = brr[0];
    ll maxi1 = arr[0];
    ll maxi2 = brr[0];
    for (ll i = 1; i < n; i++)
    {
        dp1[i] = max(dp2[i - 1] + arr[i], maxi2 + arr[i]);
        dp2[i] = max(dp1[i - 1] + brr[i], maxi1 + brr[i]);
        maxi1 = max(maxi1, dp1[i]);
        maxi2 = max(maxi2, dp2[i]);
    }
    // for (auto i : dp1)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";
    // for (auto i : dp2)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";
    cout << max(maxi1, maxi2);
    return 0;
}