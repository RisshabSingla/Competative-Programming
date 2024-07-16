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
        if (k % 2)
        {
            cout << "NO\n";
            continue;
        }
        ll maxi = (n * n) / 2;
        if (k > maxi)
        {
            cout << "NO\n";
            continue;
        }
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
        ll front = 0;
        ll back = n - 1;
        while (front <= back)
        {
            ll val = 2 * abs(arr[front] - arr[back]);
            if (val <= k)
            {
                k -= val;
                swap(arr[front], arr[back]);
                back--;
            }
            front++;
            // back--;
        }
        // cout << "Val of K: " << k << "\n";
        if (k == 0)
        {
            cout << "YES\n";
            for (auto i : arr)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}