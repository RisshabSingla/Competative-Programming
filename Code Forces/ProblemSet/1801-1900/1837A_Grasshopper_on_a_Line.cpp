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
        ll n, k;
        cin >> n >> k;
        vector<ll> jumps;
        while (n != 0)
        {
            int jump = n;
            while ((jump + k) % k == 0)
            {
                jump--;
            }
            jumps.push_back(jump);
            n -= jump;
        }
        cout << jumps.size() << "\n";
        for (auto i : jumps)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}