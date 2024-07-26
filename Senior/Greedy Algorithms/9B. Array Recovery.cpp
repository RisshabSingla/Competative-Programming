#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool solve(vector<ll> &diff, vector<ll> &arr, ll index, ll n)
{
    if (index == n)
    {
        return true;
    }
    if (diff[index] == 0)
    {
        arr[index] = arr[index - 1];
        return solve(diff, arr, index + 1, n);
    }
    ll possible1 = arr[index - 1] + diff[index];
    ll possible2 = arr[index - 1] - diff[index];
    if (possible1 >= 0 && possible2 >= 0)
    {
        return false;
    }
    if (possible1 >= 0)
    {
        arr[index] = possible1;
        return solve(diff, arr, index + 1, n);
    }
    if (possible2 >= 0)
    {
        arr[index] = possible2;
        return solve(diff, arr, index + 1, n);
    }
    return false;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> diff(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> diff[i];
        }
        vector<ll> arr(n);
        arr[0] = diff[0];
        if (solve(diff, arr, 1, n))
        {
            for (auto i : arr)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}