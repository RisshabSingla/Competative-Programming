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
        string str;
        cin >> str;
        ll ones = 0;
        ll zeros = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '1')
            {
                ones++;
            }
            else
            {
                zeros++;
            }
        }
        int i = 0;
        for (i = 0; i < str.length(); i++)
        {
            if (str[i] == '1')
            {
                zeros--;
            }
            else
            {
                ones--;
            }
            if (zeros < 0 || ones < 0)
            {
                break;
            }
        }
        cout << str.length() - i << "\n";
    }
    return 0;
}