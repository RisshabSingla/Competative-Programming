#include <iostream>
#include <vector>
#include <algorithm>

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
        ll n, k, x;
        cin >> n >> k >> x;
        if (k == 1)
        {
            cout << "No\n";
            continue;
        }
        if (x != 1)
        {
            cout << "YES\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++)
            {
                cout << "1 ";
            }
            cout << "\n";
            continue;
        }

        if (n % 2 && k == 2)
        {
            cout << "No\n";
            continue;
        }
        if (n % 2 == 0)
        {
            cout << "YES\n";
            cout << (n / 2) << "\n";
            for (ll i = 0; i < n / 2; i++)
            {
                cout << "2 ";
            }
            cout << "\n";
            continue;
        }
        ll total = n / 2;
        cout << "YES\n";
        cout << total << "\n";
        for (ll i = 0; i < total - 1; i++)
        {
            cout << "2 ";
        }
        cout << "3 \n";
    }

    return 0;
}