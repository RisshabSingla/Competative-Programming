#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
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
        }
        vector<pll> brr;
        vector<pll> ans;
        for (ll i = 1; i < n; i += 2)
        {
            if (arr[i] != arr[i - 1])
            {
                brr.push_back({arr[i - 1], i - 1});
                brr.push_back({arr[i], i});
            }
            else
            {
                ans.push_back({i - 1, i});
            }
        }
        if (n % 2)
        {
            brr.push_back({arr[n - 1], n - 1});
        }
        if (brr.size() % 2)
        {
            cout << -1 << "\n";
            continue;
        }
        ll sum = 0;
        for (auto i : brr)
        {
            sum += i.first;
        }
        if (sum != 0)
        {
            cout << -1 << "\n";
            continue;
        }
        for (auto i : brr)
        {
            ans.push_back({i.second, i.second});
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto i : ans)
        {
            cout << i.first + 1 << " " << i.second + 1 << "\n";
        }
        // cout << "\n";
    }
    return 0;
}