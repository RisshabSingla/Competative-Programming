#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// int recursive(vector<int> &arr, int left, int right)
// {
//     if (left > right)
//     {
//         return 0;
//     }
//     if (left == right)
//     {
//         return arr[left];
//     }

//     if (right - left == 1)
//     {
//         return max(arr[left], arr[right]);
//     }

//     int score1 = arr[left] + min(recursive(arr, left + 2, right), recursive(arr, left + 1, right - 1));
//     int score2 = arr[right] + min(recursive(arr, left + 1, right - 1), recursive(arr, left, right - 2));
//     return max(score1, score2);
// }

ll dp[5001][5001];

ll memo(vector<ll> &arr, int left, int right)
{
    if (left > right)
    {
        return 0;
    }
    if (left == right)
    {
        return arr[left];
    }

    if (right - left == 1)
    {
        return max(arr[left], arr[right]);
    }

    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }
    ll score1 = arr[left] + min(memo(arr, left + 2, right), memo(arr, left + 1, right - 1));
    ll score2 = arr[right] + min(memo(arr, left + 1, right - 1), memo(arr, left, right - 2));
    return dp[left][right] = max(score1, score2);
}

int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << recursive(arr, 0, n - 1);

    memset(dp, -1, sizeof(dp));
    cout << memo(arr, 0, n - 1);

    return 0;
}