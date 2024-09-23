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
        ll n, k, m;
        cin >> n >> k >> m;
        vector<ll> visit(n + 2, 0);
        for (ll i = 0; i < m; i++)
        {
            ll a, b;
            cin >> a >> b;
            visit[max(a - k + 1, 0LL)]++;
            visit[b + 1]--;
        }
        for (ll i = 1; i <= n; i++)
        {
            visit[i] += visit[i - 1];
        }
        ll mini = LLONG_MAX;
        ll maxi = LLONG_MIN;
        ll minIndex = -1;
        ll maxIndex = -1;
        // for (auto i : visit)
        // {
        //     cout << i << ' ';
        // }
        // cout << "\n";
        for (ll i = 1; i <= n - k + 1; i++)
        {
            if (visit[i] < mini)
            {
                mini = visit[i];
                minIndex = i;
            }
            if (visit[i] > maxi)
            {
                maxi = visit[i];
                maxIndex = i;
            }
        }
        if (maxIndex == -1)
        {
            maxIndex = 1;
        }
        if (minIndex == -1)
        {
            minIndex = 1;
        }
        cout << maxIndex << " " << minIndex << " \n";
    }
    return 0;
}
