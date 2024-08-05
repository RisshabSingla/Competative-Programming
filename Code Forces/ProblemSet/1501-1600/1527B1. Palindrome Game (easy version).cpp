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
        string str;
        cin >> str;
        ll zeroCount = 0;
        for (ll i = 0; i < n; i++)
        {
            if (str[i] == '0')
            {
                zeroCount++;
            }
        }
        if (n % 2 && str[n / 2] == '0' && zeroCount > 1)
        {
            cout << "ALICE\n";
        }
        else
        {
            cout << "BOB\n";
        }
    }
    return 0;
}