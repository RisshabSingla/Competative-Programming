#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    vector<ll> arr{4, 8, 15, 16, 23, 42};
    vector<ll> prod(4);
    for (ll i = 0; i < 4; i++)
    {
        cout << "? " << i + 1 << " " << i + 2 << '\n';
        cin >> prod[i];
    }

    for (ll j = 0; j < 720; j++)
    {
        bool ans = true;
        for (ll i = 0; i < 4; i++)
        {
            if (arr[i] * arr[i + 1] != prod[i])
            {
                ans = false;
                break;
            }
        }
        if (ans)
        {
            break;
        }
        next_permutation(arr.begin(), arr.end());
    }
    cout << "! ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}