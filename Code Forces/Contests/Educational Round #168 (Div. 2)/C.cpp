#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
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
        string str;
        cin >> str;
        ll open = 0;
        for (ll i = 0; i < n; i++)
        {
            if (str[i] == '(')
            {
                open++;
            }
            else if (str[i] == ')')
            {
                open--;
            }
            else
            {
                if (open == 0)
                {
                    str[i] = '(';
                    open++;
                }
                else
                {
                    str[i] = ')';
                    open--;
                }
            }
        }
        ll cost = 0;
        stack<ll> stk;
        for (ll i = 0; i < n; i++)
        {
            if (str[i] == '(')
            {
                stk.push(i);
            }
            else
            {
                cost += (i - stk.top());
                stk.pop();
            }
        }
        cout << cost << "\n";
    }
    return 0;
}
