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
        vector<vector<ll>> arr(n, vector<ll>(m));
        ll curr = 1;
        for (ll i = 1; i < n; i += 2)
        {
            for (ll j = 0; j < m; j++)
            {
                arr[i][j] = curr;
                curr++;
            }
        }

        for (ll i = 0; i < n; i += 2)
        {
            for (ll j = 0; j < m; j++)
            {
                arr[i][j] = curr;
                curr++;
            }
        }

        for (auto i : arr)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}