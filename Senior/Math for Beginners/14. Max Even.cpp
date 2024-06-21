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
    ll n;
    cin >> n;
    vector<ll> even;
    vector<ll> odd;
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        if (t % 2)
        {
            odd.push_back(t);
        }
        else
        {
            even.push_back(t);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    ll largest = -1;
    ll evenSize = even.size();
    ll oddSize = odd.size();
    if (evenSize > 1)
    {
        largest = even[evenSize - 1] + even[evenSize - 2];
    }

    if (oddSize > 1)
    {
        largest = max(largest, odd[oddSize - 1] + odd[oddSize - 2]);
    }
    cout << largest << "\n";
    return 0;
}