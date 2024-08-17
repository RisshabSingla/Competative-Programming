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
        ll n;
        cin >> n;
        vector<ll> arr(n);
        bool neg = false;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] <= 0)
            {
                neg = true;
            }
        }
        if (!neg)
        {
            cout << "YES\n";
            continue;
        }
        bool possible = true;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum <= 0)
            {
                possible = false;
            }
        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum += arr[i];
            if (sum <= 0)
            {
                possible = false;
            }
        }
        if (!possible)
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