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
        ll n, r, b;
        cin >> n >> r >> b;

        ll minR = r / (b + 1);
        ll extra = r % (b + 1);
        string str = "";
        for (ll i = 0; i < (b + 1 - extra); i++)
        {
            string s(minR, 'R');
            str += s;
            str += 'B';
        }

        for (ll i = 0; i < extra; i++)
        {
            string s(minR + 1, 'R');
            str += s;
            str += 'B';
        }
        str.pop_back();
        cout << str << "\n";
    }
    return 0;
}