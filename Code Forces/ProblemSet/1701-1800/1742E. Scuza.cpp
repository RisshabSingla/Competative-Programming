#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

void takeInputVector(vector<ll> &arr, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void takeInputVector(vector<vector<ll>> &arr, ll n, ll m)
{
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> arr(n);
        vector<ll> queries(q);

        takeInputVector(arr, n);
        takeInputVector(queries, q);

        vector<ll> pref(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + arr[i - 1];
        }

        ll maxi = arr[0];
        for (ll i = 0; i < n; i++)
        {
            maxi = max(arr[i], maxi);
            arr[i] = maxi;
        }

        for (auto i : queries)
        {
            auto itr = upper_bound(arr.begin(), arr.end(), i);
            if (itr == arr.end())
            {
                cout << pref[n] << " ";
                continue;
            }
            ll index = itr - arr.begin();
            cout << pref[index] << " ";
        }
        cout << "\n";
    }
    return 0;
}