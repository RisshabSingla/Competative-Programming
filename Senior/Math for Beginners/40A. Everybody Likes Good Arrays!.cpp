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
        ll par = arr[0] % 2;
        ll count = 0;
        for (ll i = 1; i < n; i++)
        {
            if (arr[i] % 2 == par)
            {
                count++;
            }
            else
            {
                (par += 1) %= 2;
            }
        }
        cout << count << "\n";
    }
    return 0;
}