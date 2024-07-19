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
        ll val = 0;
        if (str[0] == '1')
        {
            val = 1;
        }
        for (ll i = 1; i < n; i++)
        {
            if (str[i] == '1')
            {
                if (val > 0)
                {
                    cout << '-';
                    val--;
                }
                else
                {
                    cout << "+";
                    val++;
                }
            }
            else
            {
                cout << '+';
            }
        }
        cout << "\n";
    }
    return 0;
}