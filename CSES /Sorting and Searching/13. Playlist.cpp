#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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
    map<ll, ll> mp;
    ll front = 0;
    ll end = 0;
    ll ans = 0;
    while (front < n)
    {
        if (mp[arr[front]] == 0)
        {
            mp[arr[front]]++;
            front++;
            ans = max(ans, front - end);
        }
        else
        {
            while (mp[arr[front]] != 0)
            {
                mp[arr[end]]--;
                end++;
            }
        }
    }
    ans = max(ans, front - end);
    cout << ans << "\n";
    return 0;
}