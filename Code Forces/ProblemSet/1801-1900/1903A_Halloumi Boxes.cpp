#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool ans(vector<ll> &arr, ll k)
{
    if (k == 1)
    {
        for (ll i = 1; i < arr.size(); i++)
        {
            if (arr[i - 1] > arr[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> elem(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> elem[i];
        }
        if (ans(elem, k))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}