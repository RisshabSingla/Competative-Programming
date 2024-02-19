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
        vector<int> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> number(n, 0);
        if (arr[0] == 2)
        {
            number[0] = 1;
        }
        for (ll i = 1; i < n; i++)
        {
            if (arr[i] == 2)
            {
                number[i] = number[i - 1] + 1;
            }
            else
            {
                number[i] = number[i - 1];
            }
        }
        if (number[n - 1] == 0)
        {
            cout << 1 << "\n";
            continue;
        }
        if (number[n - 1] % 2)
        {
            cout << -1 << "\n";
            continue;
        }
        for (ll i = 0; i < n; i++)
        {
            if (number[i] == number[n - 1] / 2)
            {
                cout << (i + 1) << "\n";
                break;
            }
        }
    }
    return 0;
}