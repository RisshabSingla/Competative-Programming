#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// vector<ll> getPrimes()
// {
//     int n = 1e6;
//     bool prime[n + 1];
//     memset(prime, true, sizeof(prime));
//     for (int p = 2; p * p <= n; p++)
//     {
//         if (prime[p])
//         {
//             for (int i = p * p; i <= n; i += p)
//             {
//                 prime[i] = false;
//             }
//         }
//     }
//     vector<ll> primes;
//     for (int p = 3; p <= n; p += 2)
//     {
//         if (prime[p])
//         {
//             primes.push_back(p);
//         }
//     }
//     return primes;
// }

int main()
{
    int cases;
    cin >> cases;
    // vector<ll> oddPrimes = getPrimes();
    // ll odds = oddPrimes.size();
    while (cases--)
    {
        ll n;
        cin >> n;
        while (n % 2 == 0)
        {
            n /= 2;
        }
        if (n == 1)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
        // bool ans = false;
        // for (auto i : oddPrimes)
        // {
        //     if (n % i == 0)
        //     {
        //         ans = true;
        //         break;
        //     }
        //     if (i > n)
        //     {
        //         break;
        //     }
        // }
        // if (ans)
        // {
        //     cout << "YES\n";
        // }
        // else
        // {
        //     cout << "NO\n";
        // }
    }
    return 0;
}