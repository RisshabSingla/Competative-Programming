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
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> arr(m, vector<ll>(n, 0));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> arr[j][i];
            }
        }
        for (ll i = 0; i < m; i++)
        {
            sort(arr[i].begin(), arr[i].end(), greater<ll>());
        }
        ll score = 0;
        for (ll i = 0; i < m; i++)
        {
            score += arr[i][0] * (n - 1);
            for (ll j = 1; j < n - 1; j++)
            {
                score += arr[i][j] * (n - 1 - j);
                score -= arr[i][j] * (j);
            }
            score -= arr[i][n - 1] * (n - 1);
        }
        cout << score << "\n";
    }
    return 0;
}