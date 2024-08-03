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
        ll n;
        cin >> n;
        string str;
        cin >> str;

        int x = 0;
        int y = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'N')
            {
                y++;
            }
            else if (str[i] == 'E')
            {
                x++;
            }
            else if (str[i] == 'W')
            {
                x--;
            }
            else
            {
                y--;
            }
        }

        if (x % 2 || y % 2)
        {
            cout << "NO\n";
            continue;
        }
        if (n == 2 && x == 0 && y == 0)
        {
            cout << "NO\n";
            continue;
        }

        char ins[2] = {'R', 'H'};
        bool north = false;
        bool south = false;
        bool east = true;
        bool west = true;
        string ans = "";
        for (char ch : str)
        {
            if (ch == 'N')
            {
                ans += ins[north];
                north = !north;
            }
            else if (ch == 'E')
            {
                ans += ins[east];
                east = !east;
            }
            else if (ch == 'W')
            {
                ans += ins[west];
                west = !west;
            }
            else
            {
                ans += ins[south];
                south = !south;
            }
        }

        cout << ans << "\n";
        // int roverExec = 0;
        // int heliExec = 0;
        // int hX = 0;
        // int hY = 0;
        // int rX = 0;
        // int rY = 0;
        // string ans = "";
        // for (int i = 0; i < n; i++)
        // {
        //     if (str[i] == 'N')
        //     {
        //         // y++
        //         if (rY < hY)
        //         {
        //             roverExec++;
        //             rY++;
        //             ans.push_back('R');
        //         }
        //         else
        //         {
        //             heliExec++;
        //             hY++;
        //             ans.push_back('H');
        //         }
        //     }
        //     else if (str[i] == 'E')
        //     {
        //         // x++
        //         if (rX < hX)
        //         {
        //             roverExec++;
        //             rX++;
        //             ans.push_back('R');
        //         }
        //         else
        //         {
        //             heliExec++;
        //             hX++;
        //             ans.push_back('H');
        //         }
        //     }
        //     else if (str[i] == 'W')
        //     {
        //         // x--
        //         if (rX > hX)
        //         {
        //             roverExec++;
        //             rX--;
        //             ans.push_back('R');
        //         }
        //         else
        //         {
        //             heliExec++;
        //             hX--;
        //             ans.push_back('H');
        //         }
        //     }
        //     else
        //     {
        //         // y--
        //         if (rY > hY)
        //         {
        //             roverExec++;
        //             rY--;
        //             ans.push_back('R');
        //         }
        //         else
        //         {
        //             heliExec++;
        //             hY--;
        //             ans.push_back('H');
        //         }
        //     }
        // }
        // if (roverExec == 0 || heliExec == 0)
        // {
        //     cout << "NO" << "\n";
        // }
        // else if (rX == hX && rY == hY)
        // {
        //     cout << "NO\n";
        // }
        // else
        // {
        //     cout << ans << "\n";
        // }
    }
    return 0;
}