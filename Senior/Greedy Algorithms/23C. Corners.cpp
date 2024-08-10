#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// bool zerosTogether(vector<vector<ll>> arr, ll n, ll m)
// {
//     bool togetherZero = false;
//     int dirX[] = {-1, 1, 0, 0};
//     int dirY[] = {0, 0, -1, 1};
//     for (ll i = 0; i < n; i++)
//     {
//         for (ll j = 0; j < m; j++)
//         {
//             if (arr[i][j] == 1)
//             {
//                 continue;
//             }
//             for (ll k = 0; k < 4; k++)
//             {
//                 ll oX = i + dirX[k];
//                 ll oY = j + dirY[k];
//                 if (oX < 0 || oX >= n || oY < 0 || oY >= m || arr[oX][oY] == 1)
//                 {
//                     continue;
//                 }
//                 return true;
//             }
//         }
//     }
//     return false;
// }

ll findAns(vector<vector<ll>> arr, ll n, ll m)
{
    ll count = LLONG_MAX;
    for (ll i = 0; i < n - 1; i++)
    {
        for (ll j = 0; j < m - 1; j++)
        {
            ll c = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
            if (c == 0)
            {
                continue;
            }
            c -= 1;
            count = min(count, max(1LL, c));
        }
    }

    return count;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> arr(n, vector<ll>(m, 0));
        ll oneCount = 0;
        for (ll i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            for (ll j = 0; j < m; j++)
            {
                if (str[j] == '1')
                {
                    arr[i][j] = 1;
                    oneCount++;
                }
            }
        }
        if (oneCount == 0)
        {
            cout << 0 << "\n";
            continue;
        }

        // if (zerosTogether(arr, n, m))
        // {
        //     cout << oneCount << '\n';
        //     continue;
        // }
        cout << oneCount + 1 - findAns(arr, n, m) << "\n";
    }
    return 0;
}