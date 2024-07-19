#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> arr(n, vector<ll>(m));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        if (n == 1 && m == 1)
        {
            cout << -1 << "\n";
            continue;
        }

        if (m == 1)
        {
            for (ll i = 1; i < n; i++)
            {
                cout << arr[i][0] << "\n";
            }
            cout << arr[0][0] << "\n";
            continue;
        }

        vector<vector<ll>> ans(n, vector<ll>(m));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m - 1; j++)
            {
                ans[i][j] = arr[i][j + 1];
            }
            ans[i][m - 1] = arr[i][0];
        }
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
