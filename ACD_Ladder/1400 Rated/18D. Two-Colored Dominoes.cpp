#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
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
        vector<vector<char>> arr(n, vector<char>(m, ' '));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        vector<vector<char>> ans(n, vector<char>(m, '.'));
        // for (ll i = 0; i < n; i++)
        // {
        //     for (ll j = 0; j < m; j++)
        //     {
        //         if (arr[i][j] == '.')
        //         {
        //             continue;
        //         }
        //         if (ans[i][j] != -1)
        //         {
        //             continue;
        //         }
        //         if (arr[i][j] == 'L')
        //         {
        //             if (colSum[i] > 0)
        //             {
        //                 // place 0
        //                 ans[i][j] = 0;
        //                 ans[i][j + 1] = 1;
        //                 rowSum[j + 1]++;
        //                 rowSum[j]--;
        //             }
        //             else if (colSum[i] < 0)
        //             {
        //                 // place 1
        //                 ans[i][j] = 1;
        //                 ans[i][j + 1] = 0;
        //                 rowSum[j + 1]--;
        //                 rowSum[j]++;
        //             }
        //             else if (rowSum[j] > 0)
        //             {
        //                 // place 0
        //                 ans[i][j] = 0;
        //                 ans[i][j + 1] = 1;
        //                 rowSum[j + 1]++;
        //                 rowSum[j]--;
        //             }
        //             else
        //             {
        //                 // place 1
        //                 ans[i][j] = 1;
        //                 ans[i][j + 1] = 0;
        //                 rowSum[j + 1]--;
        //                 rowSum[j]++;
        //             }
        //         }
        //         if (arr[i][j] == 'U')
        //         {
        //             if (colSum[i] > 0)
        //             {
        //                 // place 0
        //                 ans[i][j] = 0;
        //                 ans[i + 1][j] = 1;
        //                 colSum[i]--;
        //                 colSum[i + 1]++;
        //             }
        //             else if (colSum[i] < 0)
        //             {
        //                 // place 1
        //                 ans[i][j] = 1;
        //                 ans[i + 1][j] = 0;
        //                 colSum[i]++;
        //                 colSum[i + 1]--;
        //             }
        //             else if (rowSum[j] > 0)
        //             {
        //                 // place 0
        //                 ans[i][j] = 0;
        //                 ans[i + 1][j] = 1;
        //                 colSum[i]--;
        //                 colSum[i + 1]++;
        //             }
        //             else
        //             {
        //                 // place 1
        //                 ans[i][j] = 1;
        //                 ans[i + 1][j] = 0;
        //                 colSum[i]++;
        //                 colSum[i + 1]--;
        //             }
        //         }
        //     }
        // }

        bool flag = true;
        ll currScore = 0;
        for (ll j = 0; j < m; j++)
        {
            for (ll i = 0; i < n; i++)
            {
                if (arr[i][j] == 'L')
                {
                    if (currScore == 0)
                    {
                        ans[i][j] = 'B';
                    }
                    else
                    {
                        ans[i][j] = 'W';
                    }
                    currScore = 1 - currScore;
                }
            }
            if (currScore != 0)
            {
                flag = false;
                break;
            }
        }

        currScore = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (arr[i][j] == 'U')
                {
                    if (currScore == 0)
                    {
                        ans[i][j] = 'B';
                    }
                    else
                    {
                        ans[i][j] = 'W';
                    }
                    currScore = 1 - currScore;
                }
            }
            if (currScore != 0)
            {
                flag = false;
                break;
            }
        }

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (arr[i][j] == 'R')
                {
                    if (ans[i][j - 1] == 'B')
                    {
                        ans[i][j] = 'W';
                    }
                    else
                    {
                        ans[i][j] = 'B';
                    }
                }
                if (arr[i][j] == 'D')
                {
                    if (ans[i - 1][j] == 'B')
                    {
                        ans[i][j] = 'W';
                    }
                    else
                    {
                        ans[i][j] = 'B';
                    }
                }
            }
        }

        if (!flag)
        {
            cout << "-1\n";
            continue;
        }

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}