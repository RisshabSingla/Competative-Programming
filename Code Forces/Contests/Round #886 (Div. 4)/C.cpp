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
        char inp[8][8];
        int x = -1;
        int y = -1;
        for (int i = 0; i < 8; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < 8; j++)
            {
                inp[i][j] = str[j];
                // cin >> inp[i][j];
                if (inp[i][j] != '.' && x == -1)
                {
                    x = i;
                    y = j;
                }
            }
        }
        // for (int i = 0; i < 8; i++)
        // {
        //     for (int j = 0; j < 8; j++)
        //     {
        //         cout << inp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // // cout << "x is: " << x << " y is: " << y << endl;

        for (int i = x; i < 8 && inp[i][y] != '.'; i++)
        {
            cout << inp[i][y];
        }
        cout << "\n";
    }

    return 0;
}
