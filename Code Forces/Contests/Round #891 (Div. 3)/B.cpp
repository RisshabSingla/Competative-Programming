#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
        int len = str.length();
        int index = len - 1;
        int pos = len;
        while (index > -1)
        {
            if (str[index] - '0' >= 5)
            {
                int next = index - 1;
                while (next > -1 && str[next] == '9')
                {
                    next--;
                }
                if (next == -1)
                {
                    pos = 1;
                    str = '1' + str;
                    break;
                }
                else
                {
                    index = next;
                    pos = next + 1;
                    int c = str[index] - '0';
                    c++;
                    str[index] = (char)(c + '0');
                }
            }
            else
            {
                index--;
            }
        }
        for (int i = pos; i < str.length(); i++)
        {
            str[i] = '0';
        }
        cout << str << "\n";
    }
    return 0;
}
