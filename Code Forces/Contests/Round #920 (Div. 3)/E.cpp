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
        ll h, w;
        vector<vector<ll>> pos(2, vector<ll>(2));
        cin >> h >> w >> pos[0][0] >> pos[0][1] >> pos[1][0] >> pos[1][1];
        if (pos[0][0] >= pos[1][0])
        {
            cout << "Draw\n";
            continue;
        }
        ll winner = -1;
        ll turn = 0;
        while (pos[0][0] < pos[1][0])
        {
            ll dist = pos[0][0] - pos[1][0];
            if (dist % 2)
            {
                if (pos[turn][1] > pos[!turn][1])
                {
                    pos[turn][1]--;
                }
                if (pos[turn][1] < pos[!turn][1])
                {
                    pos[turn][1]++;
                }
            }
            else
            {
                if (pos[turn][1] > pos[!turn][1] && pos[turn][1] + 1 <= w)
                {
                    pos[turn][1]++;
                }
                if (pos[turn][1] < pos[!turn][1] && pos[turn][1] - 1 >= 1)
                {
                    pos[turn][1]--;
                }
            }
            pos[turn][0] += (turn ? -1 : 1);
            if (pos[0] == pos[1])
            {
                winner = turn;
                break;
            }
            turn++;
            turn %= 2;
        }
        if (winner == 0)
        {
            cout << "Alice\n";
        }
        else if (winner == 1)
        {
            cout << "Bob\n";
        }
        else
        {
            cout << "Draw\n";
        }
    }
    return 0;
}
