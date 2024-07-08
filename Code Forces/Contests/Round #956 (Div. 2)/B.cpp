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

bool solve(vector<vector<ll>> &arr1, vector<vector<ll>> &arr2, ll n, ll m)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = m - 1; j > 0; j--)
        {
            if (arr1[i][j] != arr2[i][j])
            {

                ll difference = (arr2[i][j] - arr1[i][j] + 3) % 3;
                arr1[i][j] = arr2[i][j];
                arr1[i - 1][j] = (arr1[i - 1][j] + 2 * difference) % 3;
                arr1[i][j - 1] = (arr1[i][j - 1] + 2 * difference) % 3;
                arr1[i - 1][j - 1] = (arr1[i - 1][j - 1] + difference) % 3;
                // int x = -1;
                // int y = -1;
                // for (int k = 1; i + k < n; k++)
                // {
                //     if (change[i + k][j])
                //     {
                //         x = i + k;
                //         break;
                //     }
                // }

                // for (int k = 1; j + k < m; k++)
                // {
                //     if (change[i][j + k])
                //     {
                //         y = j + k;
                //         break;
                //     }
                // }

                // if (x == -1 || y == -1)
                // {
                //     return false;
                // }

                // if (!change[x][y])
                // {
                //     return false;
                // }
                // change[i][j] = false;
                // change[x][j] = false;
                // change[i][y] = false;
                // change[x][y] = false;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> arr1(n, vector<ll>(m, 0));
        vector<vector<ll>> arr2(n, vector<ll>(m, 0));
        // vector<vector<bool>> change(n, vector<bool>(m, false));
        char ch;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                cin >> ch;
                arr1[i][j] = ch - '0';
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> ch;
                arr2[i][j] = ch - '0';
            }
        }

        if (solve(arr1, arr2, n, m))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
