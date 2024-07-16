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
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i % 2)
            {
                arr[i] *= -1;
            }
        }
        map<ll, ll> mp;
        ll curr = 0;
        bool ans = false;
        for (ll i = 0; i < n; i++)
        {
            curr += arr[i];
            if (mp.count(curr) || curr == 0)
            {
                ans = true;
            }
            mp[curr]++;
        }
        if (ans)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}