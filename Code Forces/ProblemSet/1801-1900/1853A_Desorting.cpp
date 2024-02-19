#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;
int solve(vector<ll> &arr, ll n)
{
    ll min_diff = INT_MAX;
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            // already not sorted
            return 0;
        }
        min_diff = min(min_diff, arr[i] - arr[i - 1]);
    }
    if (min_diff == 0)
    {
        return 1;
    }
    return ceil((min_diff + 1) / 2.00);
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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << solve(arr, n) << "\n";
    }
    return 0;
}