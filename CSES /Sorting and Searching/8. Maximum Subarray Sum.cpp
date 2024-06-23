#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll maxi = LLONG_MIN;
    ll curr = 0;
    for (ll i = 0; i < n; i++)
    {
        curr += arr[i];
        maxi = max(maxi, curr);
        if (curr < 0)
        {
            curr = 0;
        }
    }
    cout << maxi << "\n";
    return 0;
}