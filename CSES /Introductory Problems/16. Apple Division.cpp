#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }
    ll ans = LLONG_MAX;
    for (ll i = 0; i < (1 << n); i++)
    {
        ll sum = 0;
        for (ll j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum += arr[j];
            }
        }
        ll diff = abs(total - sum - sum);
        ans = min(ans, diff);
    }
    cout << ans << "\n";

    return 0;
}