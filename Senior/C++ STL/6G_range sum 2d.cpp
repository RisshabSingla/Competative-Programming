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

    // Approach 2: Using Prefix Sum O(M*Q)
    // ll n, m, q;
    // cin >> n >> m >> q;
    // vector<vector<ll>> arr(n, vector<ll>(m, 0));
    // vector<vector<ll>> pref(n + 1, vector<ll>(m + 1, 0));

    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j < m; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }

    // for (ll i = 1; i <= m; i++)
    // {
    //     pref[1][i] = pref[1][i - 1] + arr[0][i - 1];
    // }

    // for (ll j = 2; j <= n; j++)
    // {
    //     pref[j][0] = pref[j - 1][m];
    //     for (ll i = 1; i <= m; i++)
    //     {
    //         pref[j][i] = pref[j][i - 1] + arr[j - 1][i - 1];
    //     }
    // }

    // // for (auto i : pref)
    // // {
    // //     for (auto j : i)
    // //     {
    // //         cout << j << ' ';
    // //     }
    // //     cout << "\n";
    // // }

    // while (q--)
    // {
    //     ll x1, y1, x2, y2;
    //     cin >> x1 >> y1 >> x2 >> y2;
    //     ll ans = 0;
    //     for (ll x = x1; x <= x2; x++)
    //     {
    //         // cout << "Adding: " << (pref[x][y2] - pref[x][y1 - 1]) << "\n";
    //         ans += (pref[x][y2] - pref[x][y1 - 1]);
    //     }
    //     cout << ans << "\n";
    // }

    // Using Area Approach

    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> arr(n, vector<ll>(m, 0));
    vector<vector<ll>> pref(n + 1, vector<ll>(m + 1, 0));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (ll i = 1; i <= m; i++)
    {
        pref[1][i] = pref[1][i - 1] + arr[0][i - 1];
    }

    for (ll i = 1; i <= n; i++)
    {
        pref[i][1] = pref[i - 1][1] + arr[i - 1][0];
    }

    for (ll i = 2; i <= n; i++)
    {
        for (ll j = 2; j <= m; j++)
        {
            pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + arr[i - 1][j - 1];
        }
    }

    // for (auto i : pref)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << ' ';
    //     }
    //     cout << "\n";
    // }

    while (q--)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1] << "\n";
    }

    return 0;
}