#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

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
        ll n, q;
        cin >> n >> q;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        while (q--)
        {
            ll s, d, k;
            cin >> s >> d >> k;
            s--;
            ll sum = 0;
            ll mul = 1;
            while (k > 0)
            {
                // cout << "index: " << (s + ((mul - 1) * d)) << "\n";
                // cout << "Adding: " << (arr[s + (mul - 1) * d] * (mul)) << "\n";
                sum += (arr[(s + ((mul - 1) * d))] * (mul));
                mul++;
                k--;
            }
            cout << sum << " ";
        }
        cout << "\n";
    }
    return 0;
}
