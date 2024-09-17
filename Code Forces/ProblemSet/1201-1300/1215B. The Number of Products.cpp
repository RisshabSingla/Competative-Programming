#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll countNeg = 0;
    ll ansPos = 0;
    ll countEven = 0;
    ll countOdd = 0;
    for (ll i = 0; i < n; i++)
    {
        if (countNeg % 2)
        {
            countOdd++;
        }
        else
        {
            countEven++;
        }
        if (arr[i] < 0)
        {
            countNeg++;
        }
        if (countNeg % 2)
        {
            ansPos += countOdd;
        }
        else
        {
            ansPos += countEven;
        }
    }
    ll total = ((n) * (n + 1)) / 2;
    ll ansNeg = total - ansPos;
    cout << ansNeg << " " << ansPos << "\n";
    return 0;
}