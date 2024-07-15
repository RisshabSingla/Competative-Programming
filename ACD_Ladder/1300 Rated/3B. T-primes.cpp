#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

vector<ll> findPrimes(int n = 1e6)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
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
    return primes;
}

int main()
{
    int cases;
    cin >> cases;
    vector<ll> primes = findPrimes();
    set<ll> st;
    for (auto i : primes)
    {
        st.insert(i * i);
    }
    while (cases--)
    {
        ll n;
        cin >> n;
        if (st.count(n))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}