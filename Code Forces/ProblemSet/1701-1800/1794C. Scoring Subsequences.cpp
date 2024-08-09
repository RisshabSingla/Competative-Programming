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
        ll count = 1;
        cout << count << " ";
        for (ll i = 1; i < n; i++)
        {
            if (arr[i - count] >= count + 1)
            {
                count++;
            }
            cout << count << " ";
        }
        cout << "\n";
    }
    return 0;
}