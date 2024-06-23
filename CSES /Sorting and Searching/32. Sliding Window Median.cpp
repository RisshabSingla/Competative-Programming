#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (k == 1)
    {
        for (ll i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        return 0;
    }

    if (k == 2)
    {
        for (ll i = 1; i < n; i++)
        {
            cout << min(arr[i], arr[i - 1]) << " ";
        }
        return 0;
    }

    set<pair<ll, ll>> ls;
    set<pair<ll, ll>> rs;

    ll leftSizeReq = (k / 2) + (k % 2);
    for (ll i = 0; i < k; i++)
    {
        ls.insert({arr[i], i});
    }
    while (ls.size() > leftSizeReq)
    {
        rs.insert(*ls.rbegin());
        ls.erase(*ls.rbegin());
    }
    cout << (*ls.rbegin()).first << " ";

    for (ll i = k; i < n; i++)
    {
        if (ls.count({arr[i - k], i - k}))
        {
            ls.erase({arr[i - k], i - k});
        }
        else
        {
            rs.erase({arr[i - k], i - k});
        }

        if ((*ls.rbegin()).first < arr[i])
        {
            rs.insert({arr[i], i});
        }
        else
        {
            ls.insert({arr[i], i});
        }

        while (ls.size() < leftSizeReq)
        {
            ls.insert(*rs.begin());
            rs.erase(*rs.begin());
        }

        while (ls.size() > leftSizeReq)
        {
            rs.insert(*ls.rbegin());
            ls.erase(*ls.rbegin());
        }

        cout << (*ls.rbegin()).first << " ";
    }
    return 0;
}