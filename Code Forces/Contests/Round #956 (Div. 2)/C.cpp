#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

vector<ll> solve(vector<ll> &a, vector<ll> &b, vector<ll> &c, ll n, ll req)
{
    ll index = 0;
    ll sum1 = 0;
    ll sum2 = 0;
    ll sum3 = 0;
    vector<ll> ans;
    // ans.push_back(index);
    while (index < n && sum1 < req)
    {
        sum1 += a[index];
        index++;
    }
    if (sum1 < req)
    {
        return {};
    }
    ans.push_back(index);
    while (index < n && sum2 < req)
    {
        sum2 += b[index];
        index++;
    }
    ans.push_back(index);
    if (sum2 < req)
    {
        return {};
    }
    while (index < n && sum3 < req)
    {
        sum3 += c[index];
        index++;
    }
    if (sum3 < req)
    {
        return {};
    }
    ans.push_back(index);
    // if (index == n)
    // {
    // }
    // else
    // {
    //     ans.push_back(index);
    // }
    return ans;
}

// bool solve(int turn, vector<int> &sums, int req, int index, vector<vector<int>> &ans, vector<vector<ll>> &scores, ll n, vector<bool> &visited)
// {
//     cout << "Scores are: ";
//     for (auto i : sums)
//     {
//         cout << i << " ";
//     }
//     cout << " index: " << index;
//     cout << "\n";
//     if (index == n)
//     {
//         // ans[turn].push_back(index);
//         if (sums[0] >= req && sums[1] >= req && sums[2] >= req)
//         {
//             cout << "returning true\n";
//             return true;
//         }
//         cout << "returning false\n";
//         return false;
//     }
//     sums[turn] += scores[turn][index];
//     visited[turn] = true;
//     if (sums[turn] >= req)
//     {
//         // if (!visited[(turn + 1) % 3])
//         // {
//         //     ans[(turn + 1) % 3].push_back(index + 1);
//         // }
//         // else
//         // {
//         //     return solve(0, sums, req, n, ans, scores, n, visited);
//         // }

//         // sums[(turn + 1) % 3] += scores[(turn + 1) % 3][index];
//         ans[turn].push_back(index);
//         for (int i = 0; i < 3; i++)
//         {
//             if (!visited[i])
//             {
//                 ans[i].push_back(index + 1);
//                 bool a = solve(i, sums, req, index + 1, ans, scores, n, visited);
//                 if (a)
//                 {
//                     return a;
//                 }
//                 ans[i].pop_back();
//             }
//         }
//         // return solve((turn + 1) % 3, sums, req, index + 1, ans, scores, n, visited);
//     }
//     // visited[turn] = false;

//     return solve(turn, sums, req, index + 1, ans, scores, n, visited);
// }

// bool isPossible(vector<vector<ll>> &scores, ll turn, vector<bool> &visited, vector<ll> &sum, vector<vector<ll>> &ans, ll index, ll n, ll req)
// {
//     if (index == n)
//     {
//         for (int i = 0; i < 3; i++)
//         {
//             if (sum[i] < req)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
//     if (!visited[turn])
//     {
//         ans[turn].push_back(index);
//     }
//     visited[turn] = true;
//     sum[turn] += scores[turn][index];

//     if (sum[turn] >= req)
//     {
//         ans[turn].push_back(index);
//         for (int i = 0; i < 3; i++)
//         {
//             if (!visited[i])
//             {
//                 bool a = isPossible(scores, i, visited, sum, ans, index + 1, n, req);
//                 if (a)
//                 {
//                     return true;
//                 }
//             }
//         }
//         // visited[turn] = false;
//         // sum[turn] -= scores[turn][index];
//         // ans[turn].pop_back();
//         return false;
//     }
//     bool a = isPossible(scores, turn, visited, sum, ans, index + 1, n, req);
//     if (a)
//     {
//         return true;
//     }
//     if (ans[turn].back() == index)
//     {
//         visited[turn] = false;
//         ans[turn].pop_back();
//     }
//     sum[turn] -= scores[turn][index];
// }

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> score(3, vector<ll>(n));
        // vector<vector<ll>> pref(3, vector<ll>(n + 1, 0));

        ll total = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> score[0][i];
            // pref[0][i + 1] = pref[0][i] + score[0][i];
            total += score[0][i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> score[1][i];
            // pref[1][i + 1] = pref[1][i] + score[1][i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> score[2][i];
            // pref[2][i + 1] = pref[2][i] + score[2][i];
        }

        ll req = (total / 3) + (total % 3 ? 1 : 0);

        if (solve(score[0], score[1], score[2], n, req).size() == 3)
        {
            // cout << 1 << '\n';
            vector<ll> ans = solve(score[0], score[1], score[2], n, req);
            cout << 1 << " " << ans[0] << " " << ans[0] + 1 << " " << ans[1] << " " << ans[1] + 1 << " " << n << "\n";
        }
        else if (solve(score[0], score[2], score[1], n, req).size() == 3)
        {
            // cout << 2 << '\n';
            vector<ll> ans = solve(score[0], score[2], score[1], n, req);
            cout << 1 << " " << ans[0] << " " << ans[1] + 1 << " " << n << " " << ans[0] + 1 << " " << ans[1] << "\n";
        }
        else if (solve(score[1], score[0], score[2], n, req).size() == 3)
        {
            // cout << 3 << '\n';
            vector<ll> ans = solve(score[1], score[0], score[2], n, req);
            cout << ans[0] + 1 << " " << ans[1] << " " << 1 << " " << ans[0] << " " << ans[1] + 1 << " " << n << "\n";
        }
        else if (solve(score[1], score[2], score[0], n, req).size() == 3)
        {
            // cout << 4 << '\n';
            vector<ll> ans = solve(score[1], score[2], score[0], n, req);
            cout << ans[1] + 1 << " " << n << " " << 1 << " " << ans[0] << " " << ans[0] + 1 << " " << ans[1] << "\n";
        }
        else if (solve(score[2], score[0], score[1], n, req).size() == 3)
        {
            // cout << 5 << '\n';
            vector<ll> ans = solve(score[2], score[0], score[1], n, req);
            cout << ans[0] + 1 << " " << ans[1] << " " << ans[1] + 1 << " " << n << " " << 1 << " " << ans[0] << "\n";
        }
        else if (solve(score[2], score[1], score[0], n, req).size() == 3)
        {
            // cout << 6 << '\n';
            vector<ll> ans = solve(score[2], score[1], score[0], n, req);
            cout << ans[1] + 1 << " " << n << " " << ans[0] + 1 << " " << ans[1] << " " << 1 << " " << ans[0] << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }

        // vector<vector<ll>> ans(3);
        // bool got = false;
        // for (ll i = 1; i < n && !got; i++)
        // {
        //     for (ll j = n - 1; j > i && !got; j--)
        //     {
        //         for (ll k = 0; k < 3; k++)
        //         {
        //             ll a = pref[k][i];
        //             ll b = pref[(k + 1) % 3][n] - pref[(k + 1) % 3][j];
        //             ll c = pref[(k + 2) % 3][j - 1] - pref[(k + 2) % 3][i];
        //             cout << a << " " << b << " " << c << "\n";
        //             if (a >= req && b >= req && c >= req)
        //             {
        //                 got = true;
        //                 ans[k].push_back(1);
        //                 ans[k].push_back(i);
        //                 ans[(k + 1) % 3].push_back(j + 1);
        //                 ans[(k + 1) % 3].push_back(n);
        //                 ans[(k + 2) % 3].push_back(i + 1);
        //                 ans[(k + 2) % 3].push_back(j);
        //                 break;
        //             }
        //         }
        //         // ll alice = pref[0][i];
        //         // ll charlie = pref[2][n] - pref[2][j];
        //         // ll bob = pref[1][j] - pref[1][i];
        //         // cout << alice << " " << bob << " " << charlie << "\n";
        //     }
        // }

        // if (got)
        // {
        //     for (auto i : ans)
        //     {
        //         for (auto j : i)
        //         {
        //             cout << j << " ";
        //         }
        //     }
        //     cout << "\n";
        // }
        // else
        // {
        //     cout << -1 << "\n";
        // }

        // bool got = false;
        // for (ll turn = 0; turn < 3 && !got; turn++)
        // {
        //     vector<bool> visited(3, false);
        //     vector<ll> sum(3, 0);
        //     vector<vector<ll>> ans(3);
        //     if (isPossible(score, turn, visited, sum, ans, 0, n, req))
        //     {
        //         got = true;
        //         for (auto i : ans)
        //         {
        //             for (auto j : i)
        //             {
        //                 cout << (j + 1) << " ";
        //             }
        //             cout << "  ";
        //         }
        //         cout << "\n";
        //     }
        //     // vector<bool> visited(3, false);
        //     //  vector<vector<int>> ans(3);
        //     //  vector<int> sum(3, 0);
        //     //  ans[turn].push_back(0);
        //     //  visited[turn] = true;
        //     //  bool solved = solve(turn, sum, req, 0, ans, score, n, visited);
        //     //  if (solved)
        //     //  {
        //     //      got = true;
        //     //      for (auto i : ans)
        //     //      {
        //     //          for (auto j : i)
        //     //          {
        //     //              cout << (j + 1) << " ";
        //     //          }
        //     //      }
        //     //      cout << "\n";
        //     //  }
        // }
        // if (!got)
        // {
        //     cout << -1 << "\n";
        // }
    }
    return 0;
}
