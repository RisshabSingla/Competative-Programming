#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        unordered_map<ll, ll> mp;
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] -= (i + 1);
            if (mp.count(arr[i]))
            {
                count += mp[arr[i]];
            }
            mp[arr[i]]++;
        }
        cout << count << '\n';
    }
    return 0;
}