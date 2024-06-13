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
        ll x, y;
        cin >> x >> y;
        if (x < y)
        {
            if (y % 2 == 1)
            {
                cout << y * y - x + 1 << endl;
            }
            else
            {
                cout << (y - 1) * (y - 1) + x << endl;
            }
        }
        else
        {
            if (x % 2 == 0)
            {
                cout << x * x - y + 1 << endl;
            }
            else
            {
                cout << (x - 1) * (x - 1) + y << endl;
            }
        }
    }
    return 0;
}