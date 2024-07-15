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
        ll n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        int index = n;
        for (int i = 0; i < n; i++)
        {
            if (str[i] - '0' < k)
            {
                index = i;
                break;
            }
        }

        for (int i = 0; i < index; i++)
        {
            cout << str[i];
        }
        cout << k;
        for (int i = index; i < n; i++)
        {
            cout << str[i];
        }
        cout << '\n';
    }
    return 0;
}