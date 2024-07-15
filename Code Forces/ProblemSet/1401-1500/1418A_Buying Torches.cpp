#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
        ll x, y, k;
        cin >> x >> y >> k;
        ll total_req_sticks = k * (y + 1);
        ll trades_sticks = (total_req_sticks - 1) / (x - 1);
        ll extra = ((total_req_sticks - 1) % (x - 1));
        if (extra)
        {
            trades_sticks++;
        }
        ll trades_coal = k;
        cout << trades_sticks + trades_coal << "\n";
    }
    return 0;
}