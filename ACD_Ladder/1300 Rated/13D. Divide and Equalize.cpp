#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

vector<ll> findPrimeFactors(ll n)
{
    vector<ll> ans;
    while (n % 2 == 0)
    {
        ans.push_back(2);
        n /= 2;
    }
    for (ll i = 3; i <= sqrtl(n); i++)
    {
        while (n % i == 0)
        {
            ans.push_back(i);
            n /= i;
        }
    }
    if (n > 2)
    {
        ans.push_back(n);
    }
    return ans;
}

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
        unordered_map<ll, ll> count;
        for (auto i : arr)
        {
            vector<ll> factors = findPrimeFactors(i);
            for (auto factor : factors)
            {
                count[factor]++;
            }
        }

        bool possible = true;
        for (auto i : count)
        {
            if (i.second % n)
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}