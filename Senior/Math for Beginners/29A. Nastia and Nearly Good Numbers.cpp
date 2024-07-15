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
        ll a, b;
        cin >> a >> b;
        if (b == 1)
        {
            cout << "NO\n";
            continue;
        }
        ll x = a;
        ll z = 2 * a * b;
        ll y = z - x;
        cout << "YES\n";
        cout << x << " " << y << " " << z << "\n";
    }
    return 0;
}