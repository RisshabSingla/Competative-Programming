#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
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
        map<ll, ll> last;
        set<ll> elem;
        set<ll> first;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (!elem.count(arr[i]))
            {
                first.insert(i);
                elem.insert(arr[i]);
            }
            last[arr[i]] = i;
        }
        set<ll> lastIndex;
        for (auto i : last)
        {
            lastIndex.insert(i.second);
        }
        ll count = 0;
        ll ans = 0;
        for (ll i = n - 1; i >= 0; i--)
        {
            if (lastIndex.count(i))
            {
                count++;
            }
            if (first.count(i))
            {
                ans += count;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}