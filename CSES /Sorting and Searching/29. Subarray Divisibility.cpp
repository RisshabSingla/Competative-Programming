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
    ll curr = 0;
    ll count = 0;
    mp[0] = 1;
    for (ll i = 0; i < n; i++)
    {
        curr += arr[i];
        while (curr < 0)
        {
            curr += n;
        }
        curr %= n;

        if (mp.count(curr))
        {
            count += mp[curr];
        }
        mp[curr]++;
    }
    cout << count << "\n";

    return 0;
}