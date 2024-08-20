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
    ll sum = 0;
    vector<ll> arr(n);
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
        sum += arr[i];
    }
    vector<ll> ans;
    for (ll i = 0; i < n; i++)
    {
        if ((sum - arr[i]) % 2)
        {
            continue;
        }
        sum -= arr[i];
        mp[arr[i]]--;
        if (mp.count(sum / 2) && mp[sum / 2] > 0)
        {
            ans.push_back(i + 1);
        }
        mp[arr[i]]++;
        sum += arr[i];
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}