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

int getCost(ll req, ll pos)
{

    if (req == pos)
    {
        return 0;
    }
    if (req == 0)
    {
        return abs(9 - pos + 1);
    }
    if (pos == 0)
    {
        return abs(9 - req + 1);
    }
    return abs(req - pos);
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        string num;
        cin >> num;
        ll pos = 1;
        ll cost = 0;
        for (int i = 0; i < 4; i++)
        {
            ll req = num[i] - '0';
            ll c = getCost(req, pos);
            // cout << c + 1 << " ";
            cost += (c + 1);
            pos = num[i] - '0';
        }

        cout << cost << endl;
    }
    return 0;
}
