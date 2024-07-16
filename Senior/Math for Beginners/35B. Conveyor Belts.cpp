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
        ll n;
        cin >> n;
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll level1 = min(min(n - x1 + 1, x1), min(n - y1 + 1, y1));
        ll level2 = min(min(n - x2 + 1, x2), min(n - y2 + 1, y2));

        cout << abs(level2 - level1) << "\n";
    }
    return 0;
}