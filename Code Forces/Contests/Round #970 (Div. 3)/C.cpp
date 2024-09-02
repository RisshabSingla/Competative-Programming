#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll l, r;
        cin >> l >> r;
        ll num = 0;
        ll current = l;
        while (current <= r)
        {
            // current += l;
            num++;
            current += num;
        }
        cout << num << "\n";
    }
    return 0;
}
