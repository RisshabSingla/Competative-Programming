#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
                arr[i] = -arr[i];
            }
        }
        map<ll, ll> mp;
        ll total = 0;
        mp[total] = 0;
        bool possible = false;
        for (ll i = 0; i < n; i++)
        {
            total += arr[i];
            if (mp.count(total))
            {
                possible = true;
                break;
            }
            mp[total]++;
        }
        if (possible)
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