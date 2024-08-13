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
        vector<vector<ll>> arr(n);
        vector<pair<ll, ll>> minReq(n);
        for (ll i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            ll minPow = 0;
            for (ll j = 0; j < t; j++)
            {
                ll num;
                cin >> num;
                arr[i].push_back(num);
                minPow = max(minPow, num - j + 1);
            }
            minReq[i] = {minPow, t};
        }
        sort(minReq.begin(), minReq.end());

        // for (auto i : minReq)
        // {
        //     cout << i.first << " ";
        // }
        // cout << "\n";
        ll currPow = 0;
        ll startPow = 0;
        for (ll i = 0; i < n; i++)
        {
            if (minReq[i].first > currPow)
            {
                startPow += minReq[i].first - currPow;
                currPow = minReq[i].first;
            }
            currPow += minReq[i].second;
        }
        currPow -= minReq[n - 1].second;
        cout << startPow << "\n";
    }
    return 0;
}