#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_map<ll, ll> mp;

    ll count = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        count += (n - i - 1 - mp[arr[i]]);
        mp[arr[i]]++;
    }
    cout << count << "\n";
    return 0;
}