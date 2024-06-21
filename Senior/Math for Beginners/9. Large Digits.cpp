#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll sum(ll num)
{
    ll count = 0;
    while (num)
    {
        count += (num % 10);
        num /= 10;
    }
    return count;
}
int main()
{
    ll a, b;
    cin >> a >> b;
    cout << max(sum(a), sum(b)) << "\n";
    return 0;
}