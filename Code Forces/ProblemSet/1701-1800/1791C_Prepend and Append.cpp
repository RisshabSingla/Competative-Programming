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
        ll len;
        cin >> len;
        string str;
        cin >> str;
        ll front = 0;
        ll back = len - 1;
        while (front < back)
        {
            if ((str[front] == '0' && str[back] == '1') || (str[front] == '1' && str[back] == '0'))
            {
                front++;
                back--;
            }
            else
            {
                break;
            }
        }
        cout << back - front + 1 << "\n";
    }
    return 0;
}