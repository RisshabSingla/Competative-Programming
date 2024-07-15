#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
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
        int ans = 0;
        int countOpen = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == ')')
            {
                if (countOpen == 0)
                {
                    ans++;
                }
                else
                {
                    countOpen--;
                }
            }
            else
            {
                countOpen++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}