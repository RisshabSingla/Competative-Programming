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
    // int cases;
    // cin >> cases;
    // while (cases--)
    // {
    ll n, q;
    cin >> n >> q;
    vector<pair<ll, ll>> arr(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        sum += arr[i].first;
        arr[i].second = -1;
    }
    pair<ll, ll> change;
    change.first = -2;
    change.second = -2;
    for (ll i = 0; i < q; i++)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll index, x;
            cin >> index >> x;
            // cout << "index is: " << index << " x is: " << x << "\n";
            ll prev = arr[index - 1].second;
            if (prev > change.second)
            {
                sum -= arr[index - 1].first;
                // cout << "Minus: " << arr[index - 1].first << " add: " << x << "\n";
                arr[index - 1].first = x;
                arr[index - 1].second = i;
                sum += x;
                // cout << "Not Changed\n";
            }
            else
            {
                sum -= change.first;
                arr[index - 1].first = x;
                arr[index - 1].second = i;
                sum += x;
                // cout << "Changed\n";
            }
        }
        else
        {
            ll x;
            cin >> x;
            sum = n * x;
            change.first = x;
            change.second = i;
        }
        cout << sum << "\n";
    }

    return 0;
}