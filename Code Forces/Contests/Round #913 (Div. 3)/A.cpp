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
        string position;
        cin >> position;

        char col = position[0];
        char row = position[1];
        for (char i = 'a'; i <= 'h'; i++)
        {
            if (i != col)
            {
                cout << i << row << endl;
            }
        }

        for (char i = '1'; i <= '8'; i++)
        {
            if (i != row)
            {
                cout << col << i << endl;
            }
        }
    }
    return 0;
}
