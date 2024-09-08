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
        stack<char> stk1;
        stack<char> stk2;
        ll color1 = 0;
        ll color2 = 0;
        vector<ll> colors(n, 0);
        for (ll i = 0; i < n; i++)
        {
            if (str[i] == '(')
            {
                if (stk2.empty())
                {
                    stk1.push(str[i]);
                    colors[i] = 1;
                    color2++;
                }
                else
                {
                    stk2.pop();
                    colors[i] = 2;
                    color1++;
                }
            }
            else
            {
                if (stk1.empty())
                {
                    stk2.push(str[i]);
                    colors[i] = 2;
                }
                else
                {
                    stk1.pop();
                    colors[i] = 1;
                }
            }
        }

        if (!stk1.empty() || !stk2.empty())
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
            for (ll i = 0; i < n; i++)
            {
                cout << 1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}