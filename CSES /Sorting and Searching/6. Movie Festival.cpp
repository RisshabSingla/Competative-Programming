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
    vector<pair<ll, ll>> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), comp);
    ll count = 0;
    ll last = 0;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i].first >= last)
        {
            count++;
            last = arr[i].second;
        }
    }
    cout << count << "\n";
    return 0;
}