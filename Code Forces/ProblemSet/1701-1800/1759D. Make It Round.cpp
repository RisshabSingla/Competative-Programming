#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, m;
        cin >> n >> m;
        ll number = n;
        ll num2 = 0;
        ll num5 = 0;
        while (number % 2 == 0)
        {
            num2++;
            number /= 2;
        }
        while (number % 5 == 0)
        {
            num5++;
            number /= 5;
        }
        ll ans = n;
        bool changed = false;
        for (ll zeros = 18; zeros >= 1; zeros--)
        {
            ll twoReq = max(zeros - num2, 0LL);
            ll fiveReq = max(zeros - num5, 0LL);
            ll num = pow(2, twoReq) * pow(5, fiveReq);
            // cout << "Num is: " << num << "\n";
            ll highestNum = num;
            while (highestNum <= m)
            {
                if (ans < highestNum * n)
                {
                    ans = highestNum * n;
                    changed = true;
                }
                highestNum += num;
            }
            if (changed)
            {
                break;
            }
        }
        if (!changed)
        {
            ans = n * m;
        }
        cout << ans << "\n";
    }
    return 0;
}