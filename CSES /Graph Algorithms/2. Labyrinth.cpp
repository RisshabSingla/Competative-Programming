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
    // ll n, m;
    // cin >> n >> m;
    // vector<vector<char>> arr(n, vector<char>(m, ' '));
    // int startX = -1;
    // int startY = -1;
    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j < m; j++)
    //     {
    //         cin >> arr[i][j];
    //         if (arr[i][j] == 'A')
    //         {
    //             startX = i;
    //             startY = j;
    //         }
    //     }
    // }

    // vector<vector<bool>> visited(n, vector<bool>(m, false));

    // queue<pair<pair<ll, ll>, vector<int>>> q;

    // q.push({{startX, startY}, {}});
    // visited[startX][startY] = true;

    // int dirX[4] = {0, 0, 1, -1};
    // int dirY[4] = {1, -1, 0, 0};

    // vector<int> ans;
    // bool found = false;
    // while (!q.empty() && !found)
    // {
    //     pair<pair<ll, ll>, vector<int>> front = q.front();
    //     // cout << front.first.first << " " << front.first.second << "\n";
    //     q.pop();
    //     for (int k = 0; k < 4; k++)
    //     {
    //         int x = front.first.first + dirX[k];
    //         int y = front.first.second + dirY[k];
    //         if (x >= 0 && y >= 0 && x < n && y < m && arr[x][y] != '#' && !visited[x][y])
    //         {
    //             visited[x][y] = true;
    //             front.second.push_back(k);
    //             if (arr[x][y] == 'B')
    //             {
    //                 ans = front.second;
    //                 found = true;
    //                 break;
    //             }
    //             q.push({{x, y}, front.second});
    //             front.second.pop_back();
    //         }
    //     }
    // }

    // if (found)
    // {
    //     cout << "YES\n";
    //     cout << ans.size() << "\n";
    //     for (auto i : ans)
    //     {
    //         if (i == 0)
    //         {
    //             cout << 'R';
    //         }
    //         else if (i == 1)
    //         {
    //             cout << 'L';
    //         }
    //         else if (i == 2)
    //         {
    //             cout << 'D';
    //         }
    //         else
    //         {
    //             cout << 'U';
    //         }
    //     }
    // }
    // else
    // {
    //     cout << "NO\n";
    // }

    // Approach 2

    ll n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m, ' '));
    int startX = -1;
    int startY = -1;
    int endX = -1;
    int endY = -1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
            {
                startX = i;
                startY = j;
            }
            if (arr[i][j] == 'B')
            {
                endX = i;
                endY = j;
            }
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, -1));

    queue<pair<ll, ll>> q;

    q.push({startX, startY});
    visited[startX][startY] = 0;

    int dirX[4] = {0, 0, 1, -1};
    int dirY[4] = {1, -1, 0, 0};
    bool found = false;
    while (!q.empty())
    {
        pair<ll, ll> front = q.front();
        // cout << front.first << " " << front.second << "\n";
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int x = front.first + dirX[k];
            int y = front.second + dirY[k];
            if (x >= 0 && y >= 0 && x < n && y < m && arr[x][y] != '#' && visited[x][y] == -1)
            {
                visited[x][y] = k;
                q.push({x, y});
                if (arr[x][y] == 'B')
                {
                    found = true;
                }
            }
        }
    }

    if (!found)
    {
        cout << "NO\n";
        return 0;
    }

    // for (auto i : visited)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }

    vector<int> ans;
    int x = endX;
    int y = endY;
    while (arr[x][y] != 'A')
    {
        // cout << "X is: " << x << " Y is: " << y << "\n";
        int k = visited[x][y];
        ans.push_back(k);
        x = x - dirX[k];
        y = y - dirY[k];
    }

    reverse(ans.begin(), ans.end());
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

    return 0;
}