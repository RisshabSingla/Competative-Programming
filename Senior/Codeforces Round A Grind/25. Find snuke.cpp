#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int dirX[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dirY[8] = {0, 0, 1, -1, -1, 1, 1, -1};

bool isPossible(ll i, ll j, ll n, ll m, vector<vector<char>> &arr, ll k, vector<vector<ll>> &path, ll index, string &str)
{
    if (index == str.length())
    {
        return true;
    }
    // cout << "i is: " << i << " j is: " << j << "\n";
    ll x = i + dirX[k];
    ll y = j + dirY[k];
    // cout << "x is: " << x << " y is: " << y << " k is: " << k << " index: " << index << "\n";
    if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] != str[index])
    {
        return false;
    }
    // cout << "x/ is: " << x << " y is: " << y << " char is: " << arr[x][y] << "\n";
    path.push_back({x, y});
    return isPossible(x, y, n, m, arr, k, path, index + 1, str);
}

vector<vector<ll>> findPath(vector<vector<char>> &arr, ll n, ll m)
{
    string str = "snuke";
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (arr[i][j] == 's')
            {
                // cout << "found s\n";
                for (ll k = 0; k < 8; k++)
                {
                    // ll x = i + dirX[k];
                    // ll y = j + dirY[k];
                    // if (x < 0 || x >= n || y < 0 || y >= m)
                    // {
                    //     continue;
                    // }
                    vector<vector<ll>> path;
                    path.push_back({i, j});
                    if (isPossible(i, j, n, m, arr, k, path, 1, str))
                    {
                        return path;
                    }
                }
            }
        }
    }
    return {};
}
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<ll>> path = findPath(arr, n, m);
    for (auto i : path)
    {
        for (auto j : i)
        {
            cout << j + 1 << " ";
        }
        cout << '\n';
    }

    return 0;
}