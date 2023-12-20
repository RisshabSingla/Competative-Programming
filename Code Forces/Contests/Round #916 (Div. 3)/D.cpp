#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool comp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.first > b.first;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll days;
        cin >> days;
        vector<vector<pair<ll, ll>>> number(3, vector<pair<ll, ll>>(days));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < days; j++)
            {
                cin >> number[i][j].first;
                number[i][j].second = j;
            }
        }
        sort(number[0].begin(), number[0].end(), comp);
        sort(number[1].begin(), number[1].end(), comp);
        sort(number[2].begin(), number[2].end(), comp);

        int result = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (number[0][i].second != number[1][j].second && number[1][j].second != number[2][k].second && number[0][i].second != number[2][k].second)
                    {
                        int pos = number[0][i].first + number[1][j].first + number[2][k].first;
                        result = max(result, pos);
                    }
                }
            }
        }
        cout << result << "\n";
    }
    return 0;
}
