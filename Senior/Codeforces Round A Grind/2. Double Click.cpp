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
    ll n, dur;
    cin >> n >> dur;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll ans = -1;
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] <= dur)
        {
            ans = arr[i];
            break;
        }
    }
    if (ans != -1)
    {
        cout << ans;
    }
    else
    {
        cout << -1;
    }
    return 0;
}