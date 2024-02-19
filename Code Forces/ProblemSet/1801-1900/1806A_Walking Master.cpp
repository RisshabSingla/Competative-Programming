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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll y_moves = d - b;
        if (y_moves < 0)
        {
            cout << "-1\n";
            continue;
        }
        ll x_after = a + y_moves;
        if (x_after >= c)
        {
            cout << y_moves + (x_after - c) << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}