#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <cmath>

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
        ll n, m, k;
        cin >> n >> m >> k;
        priority_queue<ll> pq;
        // vector<vector<ll>> count(n, vector<ll>(m, 0));
        for (ll i = 0; i < n; ++i)
        {
            for (ll j = 0; j < m; ++j)
            {
                ll top = max(0LL, i - k + 1);
                ll bottom = min(n - k, i);
                ll left = max(0LL, j - k + 1);
                ll right = min(m - k, j);
                ll num = (bottom - top + 1) * (right - left + 1);
                pq.push(num);
            }
        }
        ll w;
        cin >> w;
        vector<ll> arr(w);
        for (ll i = 0; i < w; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        ll sum = 0;
        for (ll i = w - 1; i >= 0; i--)
        {
            ll a = arr[i] * pq.top();
            // cout<<"Adding: "<<a<<"\n";
            pq.pop();
            sum += a;
        }
        cout << sum << "\n";
    }
    return 0;
}
