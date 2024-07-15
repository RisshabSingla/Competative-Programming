#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

class Compare1
{
public:
    bool operator()(pair<ll, ll> &a, pair<ll, ll> &b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

class Compare2
{
public:
    bool operator()(pair<ll, ll> &a, pair<ll, ll> &b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        ll k;
        cin >> k;
        priority_queue<ll, vector<ll>, greater<ll>> pq0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare2> pq1;

        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            if (a % k == 0)
            {
                pq0.push(i);
            }
            else
            {
                pq1.push({a % k, i});
            }
        }
        while (!pq0.empty())
        {
            ll p = pq0.top();
            pq0.pop();
            // cout << "first is: " << p.first << " index: " << p.second << "\n";
            cout << p + 1 << " ";
        }

        while (!pq1.empty())
        {
            pair<ll, ll> p = pq1.top();
            pq1.pop();
            cout << p.second + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}