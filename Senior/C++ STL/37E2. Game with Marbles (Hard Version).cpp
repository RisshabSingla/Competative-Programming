#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool comp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.first > b.first;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> alice(n, 0);
        vector<ll> bob(n, 0);
        for (auto &i : alice)
        {
            cin >> i;
        }
        for (auto &i : bob)
        {
            cin >> i;
        }
        vector<pair<ll, ll>> total(n);
        for (ll i = 0; i < n; i++)
        {
            total[i].first = alice[i] + bob[i];
            total[i].second = i;
        }
        sort(total.begin(), total.end(), comp);
        ll alice_score = 0;
        ll bob_score = 0;
        int turn = 0;
        for (ll i = 0; i < n; i++)
        {
            ll index = total[i].second;
            if (turn % 2 == 0)
            {
                // alice
                alice_score += alice[index] - 1;
            }
            else
            {
                // bob
                bob_score += bob[index] - 1;
            }
            (turn += 1) %= 2;
        }
        cout << (alice_score - bob_score) << "\n";
    }
    return 0;
}