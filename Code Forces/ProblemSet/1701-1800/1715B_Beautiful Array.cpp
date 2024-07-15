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
        ll n, k, b, sum;
        cin >> n >> k >> b >> sum;
        ll min_sum = k * b;
        ll max_sum = k * b + (k - 1) * n;
        if (sum < min_sum || sum > max_sum)
        {
            cout << "-1\n";
            continue;
        }
        vector<ll> ans(n);
        ans[0] = k * b;
        sum -= k * b;
        for (int i = 0; i < n; ++i)
        {
            ll now = min(k - 1, sum);
            ans[i] += now;
            sum -= now;
        }

        for (auto &i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}