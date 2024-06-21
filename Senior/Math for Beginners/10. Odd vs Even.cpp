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
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        if (n % 2 == 1)
        {
            cout << "Odd\n";
        }
        else if (n % 4 == 0)
        {
            cout << "Even\n";
        }
        else
        {
            cout << "Same\n";
        }
        // ll odd = 0;
        // ll even = 0;
        // for (ll i = 1; i * i <= n; i++)
        // {
        //     if (n % i == 0)
        //     {
        //         if (i % 2)
        //         {
        //             odd++;
        //         }
        //         else
        //         {
        //             even++;
        //         }
        //     }
        // }
        // if (odd > even)
        // {
        //     cout << "Odd\n";
        // }
        // else if (even > odd)
        // {
        //     cout << "Even\n";
        // }
        // else
        // {
        //     cout << "Same\n";
        // }
    }
    return 0;
}