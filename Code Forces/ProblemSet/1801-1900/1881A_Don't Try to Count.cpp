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
        ll n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        int index = 0;
        for (index = 0; index < 6; index++)
        {
            if (s1.find(s2) != string::npos)
            {
                cout << index << "\n";
                break;
            }
            s1 += s1;
        }
        if (index == 6)
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}