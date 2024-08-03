#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> adjMat(n, vector<ll>(n, LLONG_MAX));
    for (ll i = 0; i < n; i++)
    {
        adjMat[i][i] = 0;
    }
    // vector<vector<pair<int, int>>> neighbors(n);
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adjMat[a - 1][b - 1] = min(c, adjMat[a - 1][b - 1]);
        adjMat[b - 1][a - 1] = min(c, adjMat[b - 1][a - 1]);
        // neighbors[a - 1].push_back({b - 1, c});
        // neighbors[b - 1].push_back({a - 1, c});
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adjMat[i][j] > (adjMat[i][k] + adjMat[k][j]) && (adjMat[k][j] != LLONG_MAX && adjMat[i][k] != LLONG_MAX))
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (adjMat[a][b] != LLONG_MAX)
        {
            cout << adjMat[a][b] << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}