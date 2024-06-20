#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
        // set<ll> end;
        vector<ll> end(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
            end[i] = arr[i].second;
            // end.insert(arr[i].second);
        }
        sort(arr.begin(), arr.end());
        sort(end.begin(), end.end());
        // for (auto i : arr)
        // {
        //     cout << i.first << " " << i.second << "\n";
        // }
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            ll complete = arr[i].second;
            auto itr = lower_bound(end.begin(), end.end(), complete);
            ll index = itr - end.begin();
            count += index;
            end.erase(itr);
        }
        cout << count << '\n';
    }
    return 0;
}