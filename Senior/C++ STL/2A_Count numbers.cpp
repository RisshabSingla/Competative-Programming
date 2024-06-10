#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
    unordered_map<ll, ll> mp;
    while (q--)
    {
        ll z, x;
        cin >> z >> x;
        if (z == 1)
        {
            mp[x]++;
        }
        else
        {
            cout << mp[x] << "\n";
        }
    }
    return 0;
}