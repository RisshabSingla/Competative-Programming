#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
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
        // n *= 2;
        ll openReq = 0;
        ll closeReq = 0;
        bool color1 = false;
        bool color2 = false;
        vector<ll> colors(n, 0);
        for (ll i = 0; i < n; i++)
        {
            if (str[i] == '(')
            {
                if (closeReq == 0)
                {
                    openReq++;
                    colors[i] = 1;
                    color2 = true;
                }
                else
                {
                    closeReq--;
                    colors[i] = 2;
                    color1 = true;
                }
            }
            else
            {
                if (openReq == 0)
                {
                    closeReq++;
                    colors[i] = 2;
                }
                else
                {
                    openReq--;
                    colors[i] = 1;
                }
            }
        }
        if (openReq != 0 || closeReq != 0)
        {
            cout << -1 << "\n";
        }
        else if (color1 && color2)
        {
            cout << 2 << "\n";
            for (auto i : colors)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << 1 << "\n";
            for (auto i : colors)
            {
                cout << 1 << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}