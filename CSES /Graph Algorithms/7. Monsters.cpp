#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, -1));
    char ch;
    int startX = -1;
    int startY = -1;

    queue<vector<ll>> q;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> ch;
            if (ch == 'M')
            {
                arr[i][j] = 1;
                q.push({i, j, 1});
            }
            if (ch == 'A')
            {
                arr[i][j] = 2;
                startX = i;
                startY = j;
            }
            if (ch == '.')
            {
                arr[i][j] = 0;
            }
        }
    }

    if (startX == 0 || startY == 0 || startX == n - 1 || startY == m - 1)
    {
        cout << "YES\n0";
        return 0;
    }

    q.push({startX, startY, 2});

    // for (auto i : arr)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }

    vector<vector<int>> person(n, vector<int>(m, -1));

    int dirX[4] = {0, 0, 1, -1};
    int dirY[4] = {1, -1, 0, 0};
    int userPos = 1;
    bool possible = false;
    int endX = -1;
    int endY = -1;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size - userPos; i++)
        {
            int frontX = q.front()[0];
            int frontY = q.front()[1];
            q.pop();
            // cout << "Mons X: " << frontX << " Y: " << frontY << "\n";
            for (int k = 0; k < 4; k++)
            {
                int x = frontX + dirX[k];
                int y = frontY + dirY[k];

                if (x < 0 || y < 0 || x >= n || y >= m || arr[x][y] == -1)
                {
                    continue;
                }
                // cout << "nX: " << x << " nY: " << y << "\n";
                if (arr[x][y] != 1)
                {
                    arr[x][y] = 1;
                    q.push({x, y, 2});
                }
            }
        }
        // cout << "\n";
        int temp = 0;
        for (int i = 0; i < userPos; i++)
        {
            int frontX = q.front()[0];
            int frontY = q.front()[1];
            q.pop();
            // cout << "User X: " << frontX << " Y: " << frontY << "\n";
            for (int k = 0; k < 4; k++)
            {
                int x = frontX + dirX[k];
                int y = frontY + dirY[k];
                // cout << "X: " << x << " Y: " << y << "\n";
                if (x < 0 || y < 0 || x >= n || y >= m)
                {
                    // cout << "y is: " << y << "x is: " << x << " m: " << m << " n is: " << n << "\n";
                    // cout << "Invalid\n";
                    continue;
                }
                if (arr[x][y] == -1 || arr[x][y] == 1 || person[x][y] != -1)
                {
                    // cout << "Already\n";
                    continue;
                }
                // if (x < 0 || y < 0 || x >= n || y >= m || arr[x][y] == -1 || arr[x][y] == 1 || person[x][y] != -1)
                // {
                //     continue;
                // }
                // cout << " X: " << x << " Y: " << y << "\n";
                person[x][y] = k;
                q.push({x, y, 1});
                temp++;
                if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
                {
                    // cout << "Done\n";
                    possible = true;
                    endX = x;
                    endY = y;
                    // q = {};
                    break;
                }
            }
        }
        userPos = temp;
        // cout << "\n";
    }

    if (possible)
    {
        // cout << "YES\n";
        vector<int> ans;
        int x = endX;
        int y = endY;
        while (x != startX || y != startY)
        {
            // cout << "X is: " << x << " Y is: " << y << "\n";
            int k = person[x][y];
            // cout << "k is: " << k << "\n";
            ans.push_back(k);
            x = x - dirX[k];
            y = y - dirY[k];
            // cout << "nX is: " << x << " nY is: " << y << "\n";
        }
        // cout << "\n";
        reverse(ans.begin(), ans.end());

        if (ans.size() == 0)
        {
            cout << "NO";
            return 0;
        }
        cout << "YES\n";
        cout << ans.size() << "\n";

        for (auto i : ans)
        {
            if (i == 0)
            {
                cout << 'R';
            }
            else if (i == 1)
            {
                cout << 'L';
            }
            else if (i == 2)
            {
                cout << 'D';
            }
            else
            {
                cout << 'U';
            }
        }
    }
    else
    {
        cout << "NO";
    }

    // for (auto i : person)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }

    return 0;
}