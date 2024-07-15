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
    string str;
    cin >> str;
    ll maxi = str[0];
    ll index1 = 0;
    ll index2 = -1;

    for (int i = 1; i < n; i++)
    {
        if (str[i] < maxi)
        {
            index2 = i;
            break;
        }
        else
        {
            index1 = i;
            maxi = str[i];
        }
    }
    if (index2 == -1)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << index1 + 1 << " " << index2 + 1 << "\n";
    return 0;
}