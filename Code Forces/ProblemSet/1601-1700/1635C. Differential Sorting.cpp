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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (arr[n - 2] > arr[n - 1])
        {
            cout << -1 << "\n";
            continue;
        }
        if (arr[n - 1] < 0)
        {
            bool ans = true;
            for (ll i = 1; i < n; i++)
            {
                if (arr[i] < arr[i - 1])
                {
                    ans = false;
                    break;
                }
            }
            if (ans)
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        else
        {
            cout << n - 2 << "\n";
            for (ll i = 1; i < n - 1; i++)
            {
                cout << i << " " << n - 1 << " " << n << "\n";
            }
        }
    }
    return 0;
}