#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

vector<int> generatePrimes()
{
    ll n = 1e7;
    vector<bool> primes(n + 1, true);
    for (ll i = 2; i * i <= n; i++)
    {
        for (ll j = i * i; j <= n; j += i)
        {
            primes[j] = false;
        }
    }
    vector<int> ans;
    for (ll i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    int cases;
    cin >> cases;
    vector<int> primes = generatePrimes();
    while (cases--)
    {
        ll d;
        cin >> d;
        int num1 = 1 + d;
        int index1 = *lower_bound(primes.begin(), primes.end(), num1);
        int num2 = index1 + d;
        int index2 = *lower_bound(primes.begin(), primes.end(), num2);
        cout << index1 * index2 << "\n";
    }
    return 0;
}