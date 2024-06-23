#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool comp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        arr.push_back({a, 1});
        arr.push_back({b, -1});
    }
    sort(arr.begin(), arr.end());
    // for (auto i : arr)
    // {
    //     cout << i.first << " " << i.second << "\n";
    // }
    ll current = 0;
    ll maxi = 0;
    for (auto i : arr)
    {
        current += i.second;
        maxi = max(maxi, current);
    }
    cout << maxi << "\n";
    return 0;
}