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
    ll n, target;
    cin >> n >> target;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_map<ll, ll> mp;
    mp[0] = 1;
    ll sum = 0;
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += arr[i];
        if (mp.count(sum - target))
        {
            count += (mp[sum - target]);
        }
        mp[sum]++;
    }
    cout << count;
    return 0;
}