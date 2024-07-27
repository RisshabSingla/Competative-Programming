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
        ll n, k;
        cin >> n >> k;
        vector<vector<ll>> arr(n, vector<ll>(n, 0));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                char ch;
                cin >> ch;
                if (ch == '0')
                {
                    arr[i][j] = 0;
                }
                else
                {
                    arr[i][j] = 1;
                }
            }
        }

        vector<vector<ll>> ans;
        for (ll i = 0; i < n; i += k)
        {
            vector<ll> row;
            for (ll j = 0; j < n; j += k)
            {
                if (arr[i][j] == 1)
                {
                    row.push_back(1);
                }
                else
                {
                    row.push_back(0);
                }
            }
            ans.push_back(row);
        }
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j;
            }
            cout << "\n";
        }
    }
    return 0;
}
