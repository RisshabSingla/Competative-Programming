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
        ll curr = 0;
        for (ll i = 0; i < n; i++)
        {
            char ch;
            cin >> ch;
            if (ch == 'L')
            {
                arr[i] = i;
            }
            else
            {
                arr[i] = n - i - 1;
            }
            curr += arr[i];
        }
        vector<ll> diff(n, 0);
        for (ll i = 0; i < n; i++)
        {
            ll lft = i;
            ll rgt = n - i - 1;
            diff[i] = max((lft - arr[i]), (rgt - arr[i]));
        }
        // cout << "Curr is: " << curr << "\n";
        sort(diff.begin(), diff.end(), greater<ll>());
        for (auto i : diff)
        {
            curr += i;
            cout << curr << " ";
        }
        cout << "\n";
    }
    return 0;
}