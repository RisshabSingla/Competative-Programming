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
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(k);
        for (ll i = 0; i < k; i++)
        {
            cin >> arr[i];
        }
        if (k == 1)
        {
            cout << "YES\n";
            continue;
        }
        vector<ll> num(n, 0);
        ll index = n - 1;
        for (ll i = k - 1; i > 0; i--)
        {
            num[index] = arr[i] - arr[i - 1];
            index--;
        }
        while (index >= 0)
        {
            num[index] = num[index + 1];
            arr[0] -= num[index];
            index--;
        }
        num[0] += arr[0];
        // for (auto i : num)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";
        bool possible = true;
        for (ll i = 0; i < n - 1; i++)
        {
            if (num[i] > num[i + 1])
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

        // cout << "\n";
    }
    return 0;
}