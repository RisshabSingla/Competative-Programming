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

vector<int> findPrimeFactors(int n)
{
    vector<int> ans;
    while (n % 2 == 0)
    {
        ans.push_back(2);
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            ans.push_back(i);
            n /= i;
        }
    }
    if (n > 2)
    {
        ans.push_back(n);
    }
    return ans;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<int> factors = findPrimeFactors(n);
    if (factors.size() < k)
    {
        cout << -1;
        return 0;
    }
    while (factors.size() > k)
    {
        int first = factors[0];
        int last = factors.back();
        factors.erase(factors.begin());
        factors.erase(--factors.end());
        factors.push_back(first * last);
    }
    for (auto i : factors)
    {
        cout << i << " ";
    }
    return 0;
}