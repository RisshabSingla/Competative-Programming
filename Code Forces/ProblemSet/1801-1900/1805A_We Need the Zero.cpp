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
        ll arr_xor = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr_xor = arr_xor xor arr[i];
        }
        if (n % 2)
        {
            cout << arr_xor << "\n";
        }
        else
        {
            if (arr_xor == 0)
            {
                cout << "0\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
    return 0;
}