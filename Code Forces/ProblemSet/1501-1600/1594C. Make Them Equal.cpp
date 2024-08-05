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

// vector<ll> getPrimes()
// {
//     int n = 3e5 + 3;
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
//     for (int p = 2; p <= n; p++)
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
    // vector<ll> primes = getPrimes();
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        char ch;
        cin >> ch;
        string str;
        cin >> str;

        ll lastIndex = -1;
        bool other = false;
        for (ll i = 0; i < n; i++)
        {
            if (str[i] == ch)
            {
                lastIndex = i;
            }
            else
            {
                other = true;
            }
        }
        if (!other)
        {
            cout << 0 << "\n";
            continue;
        }
        if (lastIndex == -1)
        {
            cout << 2 << "\n";
            cout << n - 1 << " " << n << "\n";
            continue;
        }
        if (lastIndex >= n / 2)
        {
            cout << 1 << "\n";
            cout << lastIndex + 1 << "\n";
            continue;
        }
        cout << 2 << "\n";
        cout << n - 1 << " " << n << "\n";
        // vector<ll> freq(26, 0);
        // for (char c : str)
        // {
        //     freq[c - 'a']++;
        // }

        // if (freq[ch - 'a'] == n)
        // {
        //     cout << 0 << "\n";
        //     continue;
        // }
        // auto itr = upper_bound(primes.begin(), primes.end(), n);
        // while (*itr >= n)
        // {
        //     itr--;
        // }
        // // itr--;
        // ll number = *itr;

        // // cout << "num is: " << number << "\n";
        // if (str[number - 1] == ch)
        // {
        //     cout << 1 << "\n";
        //     cout << number << "\n";
        // }
        // else
        // {
        //     if (freq[ch - 'a'] == n - 1)
        //     {
        //         cout << 1 << "\n";
        //         cout << number + 1 << "\n";
        //     }
        //     else
        //     {
        //         cout << 2 << "\n";
        //         cout << number << " " << number + 1 << "\n";
        //     }
        // }
        // cout << number << "\n";
    }
    return 0;
}