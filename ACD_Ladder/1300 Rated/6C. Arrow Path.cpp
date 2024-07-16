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
    int cases;
    cin >> cases;
    int dirX[4] = {0, 0, 1, -1};
    int dirY[4] = {1, -1, 0, 0};
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<vector<char>> arr(2, vector<char>(n, 0));
        for (ll i = 0; i < 2; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        if (arr[1][n - 2] == '<')
        {
            cout << "NO\n";
            continue;
        }

        ll x = 1;
        ll y = n - 2;
        bool ans = true;
        while (y > 0)
        {
            if (arr[(x + 1) % 2][y - 1] == '>')
            {
                (x += 1) %= 2;
                y--;
            }
            else if (y >= 2 && arr[x][y - 2] == '>')
            {
                y = y - 2;
            }
            else
            {
                ans = false;
                break;
            }
        }
        if (ans)
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