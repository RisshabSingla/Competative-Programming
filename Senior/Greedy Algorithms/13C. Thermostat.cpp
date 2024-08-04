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
        ll l, r, x, a, b;
        cin >> l >> r >> x >> a >> b;
        if (a == b)
        {
            cout << 0 << "\n";
            continue;
        }
        if (a < b)
        {
            if (b - a >= x)
            {
                cout << 1 << "\n";
            }
            else if (r - b >= x)
            {
                cout << 2 << "\n";
            }
            else if (a - l >= x)
            {
                cout << 2 << "\n";
            }
            else if (r - a >= x && b - l >= x)
            {
                cout << 3 << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        else
        {
            if (a - b >= x)
            {
                cout << 1 << "\n";
            }
            else if (r - a >= x)
            {
                cout << 2 << "\n";
            }
            else if (b - l >= x)
            {
                cout << 2 << "\n";
            }
            else if (r - b >= x && a - l >= x)
            {
                cout << 3 << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}