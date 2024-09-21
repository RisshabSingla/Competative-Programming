#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
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
        string password = "";
        bool done = false;
        ll res;
        ll i = 0;
        for (i = 0; i < n; i++)
        {
            string curr = password + "0";
            cout << "? " << curr << endl;
            cin >> res;
            if (res == 1)
            {
                password += '0';
            }
            else
            {
                curr = password + "1";
                cout << "? " << curr << endl;
                cin >> res;
                if (res == 1)
                {
                    password += '1';
                }
                else
                {
                    break;
                }
            }
        }
        for (; i < n; i++)
        {
            string curr = "0" + password;
            cout << "? " << curr << endl;
            cin >> res;
            if (res == 1)
            {
                password = "0" + password;
            }
            else
            {
                if (i != n - 1)
                {
                    curr = "1" + password;
                    cout << "? " << curr << endl;
                    cin >> res;
                    if (res == 1)
                    {
                        password = "1" + password;
                    }
                }
                else
                {
                    password = "1" + password;
                }
            }
        }
        cout << "! " << password << "\n";
    }
    return 0;
}