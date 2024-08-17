#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

vector<ll> findFactors(ll n)
{
    vector<ll> arr;
    for (ll i = 2; i < sqrt(n); i++)
    {
        while (n % i == 0)
        {
            arr.push_back(i);
            n = n / i;
        }
    }
    if (n != 1)
    {
        arr.push_back(n);
    }
    return arr;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;

        set<ll> used;
        for (ll i = 2; i * i <= n; ++i)
        {
            if (n % i == 0 && !used.count(i))
            {
                used.insert(i);
                n /= i;
                break;
            }
        }
        for (ll i = 2; i * i <= n; ++i)
        {
            if (n % i == 0 && !used.count(i))
            {
                used.insert(i);
                n /= i;
                break;
            }
        }

        if (used.size() < 2 || used.count(n) || n == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            used.insert(n);
            for (auto it : used)
            {
                cout << it << " ";
            }
            cout << "\n";
        }

        // vector<ll> arr = findFactors(n);
        // ll a = 1;
        // ll b = 1;
        // ll c = 1;
        // for (ll index = 0; index < arr.size(); index++)
        // {
        //     if (a <= b && a <= c)
        //     {
        //         a *= arr[index];
        //     }
        //     else if (b <= a && b <= c)
        //     {
        //         b *= arr[index];
        //     }
        //     else
        //     {
        //         c *= arr[index];
        //     }
        // }
        // cout << a << " " << b << " " << c << "\n";
        // if (a != 1 && b != 1 && c != 1 && a != b && b != c && a != c)
        // {
        //     cout << "YES\n";
        //     cout << a << " " << b << " " << c << "\n";
        // }
        // else
        // {
        //     cout << "NO\n";
        // }
    }
    return 0;
}