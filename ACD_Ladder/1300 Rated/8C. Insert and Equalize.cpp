#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

long long GCD(long long a, long long b)
{
    if (a == 0)
        return b;
    return GCD(b % a, a);
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
        if (n == 1)
        {
            cout << n << '\n';
            continue;
        }
        sort(arr.begin(), arr.end());
        vector<ll> arr2(n);
        ll val = arr[0];
        for (ll i = 0; i < n; i++)
        {
            arr2[i] = arr[i] - val;
        }
        ll gcd = 0;
        for (ll i = 0; i < n; i++)
        {
            gcd = GCD(gcd, arr2[i]);
        }

        ll last = arr.back();
        ll elem = last;
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ans += ((arr[n - 1] - arr[i]) / gcd);
        }
        ll newVal = arr[n - 1];
        set<ll> st;
        for (auto i : arr)
            st.insert(i);

        while (st.count(newVal))
        {
            newVal -= gcd;
        }
        ans += (arr[n - 1] - newVal) / gcd;
        cout << ans << '\n';
    }
    return 0;
}