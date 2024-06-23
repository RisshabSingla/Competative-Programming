#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> arr(n + 1);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i + 1];
    }
    for (ll i = 1; i <= n; i++)
    {
        arr[i] += arr[i - 1];
    }

    set<pair<ll, ll>> st;
    for (ll i = a; i <= b; i++)
    {
        st.insert({arr[i], i});
    }
    ll ans = LLONG_MIN;
    for (ll i = 1; i <= (n - a + 1); i++)
    {
        ll sum = (*st.rbegin()).first - arr[i - 1];
        ans = max(ans, sum);
        st.erase({arr[i + a - 1], i + a - 1});
        if (i + b <= n)
        {
            st.insert({arr[i + b], i + b});
        }
    }
    cout << ans << "\n";

    return 0;
}