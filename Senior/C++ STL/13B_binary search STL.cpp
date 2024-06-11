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
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    while (q--)
    {
        string str;
        ll number;
        cin >> str >> number;
        if (str[0] == 'l')
        {
            auto index = lower_bound(arr.begin(), arr.end(), number);
            if (index == arr.end())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << *index << "\n";
            }
        }
        else if (str[0] == 'u')
        {
            auto index = upper_bound(arr.begin(), arr.end(), number);
            if (index == arr.end())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << *index << "\n";
            }
        }
        else
        {
            if (binary_search(arr.begin(), arr.end(), number))
            {
                cout << "found\n";
            }
            else
            {
                cout << "not found\n";
            }
        }
    }

    return 0;
}