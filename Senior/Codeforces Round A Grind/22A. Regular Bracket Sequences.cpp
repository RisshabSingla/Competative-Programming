#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

void makeAns(string &str, ll open, ll closed, ll n, vector<string> &ans)
{
    if (open > n || closed > n)
    {
        return;
    }
    if (open == n && closed == n)
    {
        ans.push_back(str);
        return;
    }

    if (ans.size() == n)
    {
        return;
    }

    if (open < n)
    {
        str.push_back('(');
        makeAns(str, open + 1, closed, n, ans);
        str.pop_back();
    }

    if (closed < open)
    {
        str.push_back(')');
        makeAns(str, open, closed + 1, n, ans);
        str.pop_back();
    }
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        string str = "";
        vector<string> ans;
        makeAns(str, 0, 0, n, ans);
        for (auto i : ans)
        {
            cout << i << " \n";
        }
    }
    return 0;
}