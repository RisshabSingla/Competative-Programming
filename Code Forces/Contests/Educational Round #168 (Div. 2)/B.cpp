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
        ll n;
        cin >> n;
        vector<vector<ll>> arr(2, vector<ll>(n, 0));
        vector<pair<ll, ll>> points;
        for (ll i = 0; i < 2; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                char ch;
                cin >> ch;
                if (ch != '.')
                {
                    arr[i][j] = -1;
                }
                else
                {
                    points.push_back({i, j});
                }
            }
        }
        int count = 0;
        for (auto &point : points)
        {
            int x = point.first;
            int y = point.second;
            if (y - 1 >= 0 && y + 1 < n)
            {
                if (arr[x][y - 1] == 0 && arr[x][y + 1] == 0)
                {
                    if (x == 0)
                    {
                        if (arr[1][y - 1] == -1 && arr[1][y + 1] == -1 && arr[1][y] == 0)
                        {
                            // cout << x << " " << y << "\n";
                            count++;
                        }
                    }
                    if (x == 1)
                    {
                        if (arr[0][y - 1] == -1 && arr[0][y + 1] == -1 && arr[0][y] == 0)
                        {
                            // cout << x << " " << y << "\n";
                            count++;
                        }
                    }
                }
            }
        }
        cout << count << '\n';
    }

    return 0;
}
