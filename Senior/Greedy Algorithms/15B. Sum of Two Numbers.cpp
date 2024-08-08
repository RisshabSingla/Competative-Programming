#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll calcSum(ll num)
{
    ll sum = 0;
    while (num)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

pll findAns(ll n)
{
    if (n % 2 == 0)
    {
        ll a = n / 2;
        return {a, n - a};
    }
    if (n < 10)
    {
        ll a = n / 2;
        return {a, n - a};
    }

    if (n % 10 != 9)
    {
        ll a = n / 2;
        return {a, n - a};
    }
    pll ans = findAns(n / 10);
    ll sum1 = calcSum(ans.first);
    ll sum2 = calcSum(ans.second);
    ans.first *= 10;
    ans.second *= 10;
    if (sum1 > sum2)
    {
        ans.first += 4;
        ans.second += 5;
    }
    else
    {
        ans.second += 4;
        ans.first += 5;
    }
    return ans;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        pll ans = findAns(n);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}