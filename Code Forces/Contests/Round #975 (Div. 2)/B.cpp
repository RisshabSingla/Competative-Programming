#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            ll back = i + 1;
            ll front = n - i;
            ll partOf1 = front * back - 1;
            mp[partOf1]++;
            if (i > 0)
            {
                // for elements in between
                ll noOfElem = arr[i] - arr[i - 1] - 1;
                ll before = i;
                ll after = n - i;
                ll partOf2 = before * after;
                mp[partOf2] += noOfElem;
            }
        }
        while (q--)
        {
            ll a;
            cin >> a;
            if (mp.count(a))
            {
                cout << mp[a] << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
