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
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> arr(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
            {
                arr[i][j] = 1;
            }
        }
    }
    vector<vector<ll>> pref(n + 1, vector<ll>(n + 1, 0));

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            pref[i][j] = pref[i][j - 1] + arr[i - 1][j - 1];
        }
    }

    for (ll j = 1; j <= n; j++)
    {
        for (ll i = 1; i <= n; i++)
        {
            pref[i][j] += pref[i - 1][j];
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
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        cout << pref[ex][ey] - pref[sx - 1][ey] - pref[ex][sy - 1] + pref[sx - 1][sy - 1] << "\n";
    }
    return 0;
}