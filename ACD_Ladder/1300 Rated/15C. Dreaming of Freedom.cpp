#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

vector<ll> getPrimes()
{
    int n = 1e6;
    vector<ll> prime(n + 1, -1);
    prime[1] = 1;
    // memset(prime, true, sizeof(prime));
    for (int p = 2; p <= n; p++)
    {
        if (prime[p] == -1)
        {
            for (int i = p; i <= n; i += p)
            {
                if (prime[i] == -1)
                {
                    prime[i] = p;
                }
            }
        }
    }
    return prime;
    // vector<ll> primes;
    // for (int p = 2; p <= n; p++)
    // {
    //     if (prime[p])
    //     {
    //         primes.push_back(p);
    //     }
    // }
    // return primes;
}

int main()
{
    vector<ll> primes = getPrimes();
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, m;
        cin >> n >> m;
        if (n == 1)
        {
            cout << "YES\n";
            continue;
        }

        if (primes[n] <= m)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}