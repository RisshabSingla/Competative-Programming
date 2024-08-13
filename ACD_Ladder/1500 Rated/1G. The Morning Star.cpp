#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
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
        vector<pll> arr(n);
        map<ll, ll> slope1;
        map<ll, ll> slopeNeg1;
        map<ll, ll> xCor;
        map<ll, ll> yCor;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
            slope1[arr[i].first - arr[i].second]++;
            slopeNeg1[arr[i].first + arr[i].second]++;
            xCor[arr[i].first]++;
            yCor[arr[i].second]++;
        }
        ll count = 0;
        // sort(arr.begin(), arr.end());
        for (auto [i, x] : slope1)
        {
            count += ((x) * (x - 1));
        }
        for (auto [i, x] : slopeNeg1)
        {
            count += ((x) * (x - 1));
        }

        for (auto [i, x] : xCor)
        {
            count += ((x) * (x - 1));
        }
        for (auto [i, x] : yCor)
        {
            count += ((x) * (x - 1));
        }

        cout << count << endl;
    }
    return 0;
}