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
    ll n;
    cin >> n;
    bool ans = true;
    char ch;
    cin >> ch;
    for (ll i = 1; i < n; i++)
    {
        char t;
        cin >> t;
        if (t == ch)
        {
            ans = false;
        }
        ch = t;
    }
    if (ans)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}