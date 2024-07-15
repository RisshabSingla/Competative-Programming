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
        ll diff = a - b;
        if (diff < 2)
        {
            cout << "NO\n";
            continue;
        }
        bool possible = true;
        ll twos = diff / 2;
        diff = diff % 2;
        if (diff == 1)
        {
            if (twos == 0)
            {
                possible = false;
            }
        }
        if (possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}