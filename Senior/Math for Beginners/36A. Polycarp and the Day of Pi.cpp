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
    string pie = "314159265358979323846264338327";

    int cases;
    cin >> cases;
    while (cases--)
    {
        string str;
        cin >> str;
        int i = 0;
        for (i = 0; i < str.length(); i++)
        {
            if (str[i] != pie[i])
            {
                break;
            }
        }
        cout << i << "\n";
    }
    return 0;
}