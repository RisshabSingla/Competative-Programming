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
        if (b < 2 * a)
        {
            cout << "-1 -1\n";
            continue;
        }
        cout << a << " " << 2 * a << "\n";
    }
    return 0;
}