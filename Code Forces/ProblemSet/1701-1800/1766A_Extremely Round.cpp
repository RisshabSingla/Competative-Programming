#include <iostream>
#include <vector>
#include <algorithm>
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
        ll count = 0;
        ll num = 0;
        ll add = 1;
        while (num <= n)
        {
            num += add;
            if (count != 0 && count % 9 == 0)
            {
                add *= 10;
            }
            count++;
        }
        cout << count - 1 << "\n";
    }
    return 0;
}