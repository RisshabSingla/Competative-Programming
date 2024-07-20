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
    ll win = 0;
    ll lose = 0;
    for (ll i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str[0] == 'F')
        {
            win++;
        }
        else
        {
            lose++;
        }
    }
    if (win > lose)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}