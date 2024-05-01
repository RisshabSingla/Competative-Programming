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
        ll n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> c(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i].second;
        }

        ll res = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i].first;
            res += max(0ll, c[i].first - c[i].second);
        }

        sort(c.begin() + 1, c.end());

        priority_queue<int> q;

        ll ans = 0, sum = 0;
        for (int i = n; i; i--)
        {
            if (i <= n - k)
            {
                ans = max(ans, res - sum);
            }
            q.push(c[i].second);
            sum += c[i].second;
            if (q.size() > k)
            {
                sum -= q.top();
                q.pop();
            }

            res -= max(0ll, c[i].first - c[i].second);
        }

        cout << ans << "\n";
    }
    return 0;
}
