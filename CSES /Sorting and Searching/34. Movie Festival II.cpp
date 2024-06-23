#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool comp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> arr(n);
    set<pair<ll, ll>> st;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), comp);
    // for (auto i : arr)
    // {
    //     cout << i.first << " " << i.second << "\n";
    // }

    for (ll i = 0; i < k; i++)
    {
        st.insert({0, i + n + 1});
    }
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        auto itr = st.lower_bound({arr[i].first * -1, -1});
        if (itr == st.end())
        {
            count++;
        }
        else
        {
            st.erase(itr);
            st.insert({arr[i].second * -1, i});
        }
    }
    cout << n - count << "\n";

    return 0;
}