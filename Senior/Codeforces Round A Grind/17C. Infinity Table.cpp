#include <iostream>
#include <vector>
#include <cmath>
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
        ll x = sqrtl(n);
        if (x * x == n)
        {
            cout << x << " " << 1 << "\n";
            continue;
        }
        x++;
        ll diff = x * x - n + 1;
        ll y = diff;
        // cout << x << " " << y << " " << diff << "\n";
        if (diff > x)
        {
            y = diff - (diff - x);
            x -= (diff - x);
        }
        cout << x << " " << y << "\n";
    }
    return 0;
}