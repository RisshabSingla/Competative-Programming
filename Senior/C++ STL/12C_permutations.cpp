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
    ll n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    while (q--)
    {
        string comm;
        ll number;
        cin >> comm >> number;
        if (comm[0] == 'p')
        {
            for (int i = 0; i < number; i++)
            {
                prev_permutation(str.begin(), str.end());
            }
            cout << str << "\n";
        }
        else
        {
            for (int i = 0; i < number; i++)
            {
                next_permutation(str.begin(), str.end());
            }
            cout << str << "\n";
        }
    }
    return 0;
}