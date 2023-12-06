#include <iostream>
#include <vector>
#include <algorithm>
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
        string str;
        cin >> str;
        string ans = "";
        int lower = 0;
        int upper = 0;
        for (int i = str.length() - 1; i >= 0; i--)
        {
            if (str[i] == 'B')
            {
                upper++;
            }
            else if (str[i] == 'b')
            {
                lower++;
            }
            else if (islower(str[i]) && lower > 0)
            {
                lower--;
            }
            else if (isupper(str[i]) && upper > 0)
            {
                upper--;
            }
            else
            {
                ans += str[i];
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}
