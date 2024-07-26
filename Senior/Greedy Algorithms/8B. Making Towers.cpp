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
        vector<ll> ans(n, 0);
        vector<ll> parity(n, -1);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (parity[arr[i] - 1] == -1)
            {
                parity[arr[i] - 1] = (i % 2);
            }
            else
            {
                if (parity[arr[i] - 1] != (i % 2))
                {
                    ans[arr[i] - 1]++;
                    parity[arr[i] - 1] = (i % 2);
                }
            }
        }

        for (ll i = 0; i < n; i++)
        {
            if (parity[i] != -1)
            {
                ans[i]++;
            }
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}