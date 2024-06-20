#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

class Compare
{
public:
    bool operator()(pair<ll, ll> a, pair<ll, ll> b)
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
    ll q;
    cin >> q;
    ll served = 0;
    ll number = 1;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> pq;
    set<ll> done;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll m;
            cin >> m;
            pq.push({m, number});
            number++;
        }
        if (t == 2)
        {
            while (done.count(served + 1))
            {
                served++;
            }
            cout << served + 1 << " ";
            done.insert(served + 1);
            served++;
        }
        if (t == 3)
        {
            while (done.count(pq.top().second))
            {
                pq.pop();
            }
            cout << pq.top().second << " ";
            done.insert(pq.top().second);
            pq.pop();
        }
    }
    return 0;
}