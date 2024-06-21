#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int findGCD(int a, int b, int c)
{
    return __gcd(a, __gcd(b, c));
}

int main()
{
    ll n;
    cin >> n;
    ll count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                count += findGCD(i, j, k);
            }
        }
    }
    cout << count << "\n";
    return 0;
}