#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll countDigits(ll n)
{
    ll count = 0;
    while (n > 0)
    {
        count++;
        n /= 10;
    }
    return count;
}

ll countZeros(ll n)
{
    ll count = 0;
    while (n > 0)
    {
        if (n % 10)
        {
            break;
        }
        count++;
        n /= 10;
    }
    return count;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> arr(n);
        vector<ll> zeros(n);
        ll totalDigits = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            totalDigits += countDigits(arr[i]);
            zeros[i] = countZeros(arr[i]);
        }
        sort(zeros.begin(), zeros.end(), greater<ll>());
        for (ll i = 0; i < n; i += 2)
        {
            totalDigits -= zeros[i];
        }
        if (totalDigits >= m + 1)
        {
            cout << "Sasha\n";
        }
        else
        {
            cout << "Anna\n";
        }
    }
    return 0;
}