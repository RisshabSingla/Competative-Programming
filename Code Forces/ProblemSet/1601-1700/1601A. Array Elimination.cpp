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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<ll> bits(32, 0);
        for (ll i = 0; i < n; i++)
        {
            for (ll bit = 0; bit < 32; bit++)
            {
                if (arr[i] & (1 << bit))
                {
                    bits[bit]++;
                }
            }
        }
        vector<ll> ans;
        ans.push_back(1);
        for (ll i = 2; i <= n; i++)
        {
            bool possible = true;
            for (auto count : bits)
            {
                if (count % i)
                {
                    possible = false;
                    break;
                }
            }
            if (possible)
            {
                ans.push_back(i);
            }
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}