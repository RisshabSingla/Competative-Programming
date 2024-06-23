#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n, k;
    cin >> n >> k;
    bool prime[1001];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
    vector<ll> primes;
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            primes.push_back(p);
        }
    }
    vector<ll> possible;
    for (ll i = 1; i < primes.size(); i++)
    {
        ll sum = primes[i] + primes[i - 1] + 1;
        if (sum > n)
        {
            break;
        }
        if (prime[sum])
        {
            possible.push_back(sum);
        }
    }
    if (possible.size() >= k)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}