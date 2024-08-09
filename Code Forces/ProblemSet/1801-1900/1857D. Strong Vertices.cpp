#include <iostream>
#include <vector>
#include <algorithm>

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
        ll n;
        cin >> n;
        vector<ll> arr(n);
        vector<ll> brr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> brr[i];
        }
        vector<pair<ll, ll>> diff(n);
        for (ll i = 0; i < n; i++)
        {
            diff[i].first = arr[i] - brr[i];
            diff[i].second = i;
        }
        sort(diff.begin(), diff.end(), greater<pll>());
        vector<ll> ans;
        ll maxi = diff[0].first;
        for (ll i = 0; i < n; i++)
        {
            if (diff[i].first == maxi)
            {
                ans.push_back(diff[i].second);
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto i : ans)
        {
            cout << i + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}