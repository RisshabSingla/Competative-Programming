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

ll query(int x, int y)
{
    cout << "? " << x << " " << y << "\n";
    ll q;
    cin >> q;
    return q;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, m;
        cin >> n >> m;
        ll q1 = query(1, 1);
        ll Xcord = min(n, 1 + q1);
        ll Ycord = min(m, 1 + q1);

        ll q2 = query(Xcord, q1 - Xcord + 2);
        ll q3 = query(q1 - Ycord + 2, Ycord);
        ll ans = 0;
        if (Xcord - q2 / 2 <= n && q1 - Xcord + 2 + q2 / 2 <= m && q2 % 2 == 0)
        {
            int q4 = query(Xcord - q2 / 2, q1 - Xcord + 2 + q2 / 2);
            ans = (q4 != 0);
        }
        else
        {
            ans = 1;
        }

        if (ans == 0)
        {
            cout << "! " << Xcord - q2 / 2 << " " << q1 - Xcord + 2 + q2 / 2 << "\n";
        }
        else
        {
            cout << "! " << q1 - Ycord + 2 + q3 / 2 << " " << Ycord - q3 / 2 << "\n";
        }
    }

    return 0;
}
