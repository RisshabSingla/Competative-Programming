#include <iostream>
#include <vector>
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
        vector<pair<ll, ll>> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i].first;
            arr[i].second = i;
        }
        for (ll i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            arr[i].first -= t;
        }
        sort(arr.begin(), arr.end());
        ll val = arr.back().first;
        vector<ll> ans;
        ll index = n - 1;
        while (index >= 0 && arr[index].first == val)
        {
            ans.push_back(arr[index].second);
            index--;
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto i : ans)
        {
            cout << i + 1 << ' ';
        }
        cout << "\n";
    }
    return 0;
}