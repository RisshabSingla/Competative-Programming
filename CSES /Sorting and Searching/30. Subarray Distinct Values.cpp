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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_map<ll, ll> mp;
    ll count = 0;
    ll end = 0;
    for (ll i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[arr[end]]--;
                if (mp[arr[end]] == 0)
                {
                    mp.erase(arr[end]);
                }
                end++;
            }
        }
        count += (i - end + 1);
    }
    cout << count;

    return 0;
}