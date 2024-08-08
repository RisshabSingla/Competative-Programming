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
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        ll curr = 0;
        for (ll i = 0; i < k; i++)
        {
            vector<ll> indexes;
            for (ll j = i; j < n; j += k)
            {
                indexes.push_back(j);
            }
            if (i % 2)
            {
                reverse(indexes.begin(), indexes.end());
            }
            for (auto index : indexes)
            {
                arr[index] = curr;
                curr++;
            }
        }
        for (auto i : arr)
        {
            cout << i + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}