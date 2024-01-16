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

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        string initial;
        string req;
        cin >> initial >> req;

        // ll count = 0;
        // ll req_ones = 0;
        // for (ll i = 0; i < n; i++)
        // {
        //     count += ((initial[i] - '0') or (req[i] - '0'));
        //     if (initial[i] == '1')
        //     {
        //         req_ones++;
        //     }
        // }
        // cout << count - req_ones << "\n";

        ll ones_req = 0;
        ll ones_present = 0;
        for (ll i = 0; i < n; i++)
        {
            if (initial[i] == '1')
            {
                ones_present++;
            }
            if (req[i] == '1')
            {
                ones_req++;
            }
        }
        if (ones_present == ones_req)
        {
            ll corrections = 0;
            for (ll i = 0; i < n; i++)
            {
                if (initial[i] == '0' && req[i] != '0')
                {
                    corrections++;
                }
            }
            cout << corrections << "\n";
        }
        else
        {
            vector<ll> ones_req;
            vector<ll> ones_not_req;
            for (ll i = 0; i < n; i++)
            {
                if (req[i] == '1' && initial[i] == '0')
                {
                    ones_req.push_back(i);
                }
                if (req[i] == '0' && initial[i] == '1')
                {
                    ones_not_req.push_back(i);
                }
            }
            ll d = ones_req.size() - ones_not_req.size();
            cout << min(ones_req.size(), ones_not_req.size()) +
                        abs(d)
                 << "\n";
        }
    }
    return 0;
}
