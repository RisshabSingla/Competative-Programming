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
    ll power;
    cin >> power;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());
    ll players = n;
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        ll req = (power / arr[i]) + 1;
        if (req > players)
        {
            break;
        }
        players -= req;
        count++;
    }
    cout << count << "\n";
    return 0;
}