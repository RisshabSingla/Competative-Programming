#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int dirX[4] = {0, 0, 1, -1};
int dirY[4] = {1, -1, 0, 0};

void dfs(vector<vector<char>> &arr, int i, int j, int n, int m, vector<vector<bool>> &visited)
{
    visited[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dirX[k];
        int y = j + dirY[k];
        if (x >= 0 && y >= 0 && x < n && y < m && arr[x][y] == '.' && !visited[x][y])
        {
            dfs(arr, x, y, n, m, visited);
        }
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m, ' '));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (arr[i][j] == '.' && !visited[i][j])
            {
                count++;
                dfs(arr, i, j, n, m, visited);
            }
        }
    }
    cout << count;
}