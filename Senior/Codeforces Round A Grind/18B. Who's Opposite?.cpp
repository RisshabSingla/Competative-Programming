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
        ll a, b, c;
        cin >> a >> b >> c;
        ll diff = abs(b - a);
        ll total = 2 * diff;
        if (c > total || a > total || b > total)
        {
            cout << -1 << "\n";
            continue;
        }
        ll person = (c + diff) % (total);
        if (person == 0)
        {
            person = total;
        }
        cout << person << "\n";
    }
    return 0;
}