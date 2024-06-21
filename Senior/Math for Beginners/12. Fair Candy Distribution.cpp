#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    ll all = 0;
    if (k >= n)
    {
        all = (k / n);
    }
    vector<ll> got(n, all);
    ll extra = k % n;
    for (ll i = 0; i < extra; i++)
    {
        got[arr[i].second]++;
    }
    for (auto i : got)
    {
        cout << i << '\n';
    }
    return 0;
}