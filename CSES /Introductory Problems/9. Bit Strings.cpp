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
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= 2;
        ans %= mod;
    }
    cout << ans << "\n";

    return 0;
}