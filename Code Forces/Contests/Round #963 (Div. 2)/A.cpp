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
        ll len = 4 * n;
        string str;
        cin >> str;
        ll a = 0;
        ll b = 0;
        ll c = 0;
        ll d = 0;
        for (ll i = 0; i < len; i++)
        {
            if (str[i] == 'A')
            {
                a++;
            }
            if (str[i] == 'B')
            {
                b++;
            }
            if (str[i] == 'C')
            {
                c++;
            }
            if (str[i] == 'D')
            {
                d++;
            }
        }
        ll score = 0;

        score += min(a, n);
        score += min(b, n);
        score += min(c, n);
        score += min(d, n);
        // cout << a << " " << b << " " << c << " " << d << "\n";
        cout << score << "\n";
    }
    return 0;
}
