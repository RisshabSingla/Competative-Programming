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
        ll n;
        cin >> n;
        ll neg = 0;
        ll pos = 0;
        for (ll i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            if (t == 1)
            {
                pos++;
            }
            else
            {
                neg++;
            }
        }
        ll count = 0;
        while (neg % 2 || neg > pos)
        {
            count++;
            neg--;
            pos++;
        }
        cout << count << "\n";
    }
    return 0;
}