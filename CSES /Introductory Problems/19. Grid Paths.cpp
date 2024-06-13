#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

const int n = 7;
const int total_steps = 48;
bool visited[n][n];

string path;

void move(int row, int col, int &ans, int &steps)
{
    if (row == n - 1 && col == 0)
    {
        // Optimization 1
        // If at end point consider only if all explored
        if (steps == total_steps)
        {
            ans++;
        }
        return;
    }

    // if you hit a wall or a path (can only go left or right); return
    if (((row + 1 == n || (visited[row - 1][col] && visited[row + 1][col])) && col - 1 >= 0 && col + 1 < n && !visited[row][col - 1] && !visited[row][col + 1]))
    {
        // Wall Hit or Surrounded by Pocket
        return;
    }
    if (((col + 1 == n || (visited[row][col - 1] && visited[row][col + 1])) && row - 1 >= 0 && row + 1 < n && !visited[row - 1][col] && !visited[row + 1][col]))
    {
        // Wall Hit or Surrounded by Pocket
        return;
    }
    if (((row == 0 || (visited[row + 1][col] && visited[row - 1][col])) && col - 1 >= 0 && col + 1 < n && !visited[row][col - 1] && !visited[row][col + 1]))
    {
        // Wall Hit or Surrounded by Pocket
        return;
    }
    if (((col == 0 || (visited[row][col + 1] && visited[row][col - 1])) && row - 1 >= 0 && row + 1 < n && !visited[row - 1][col] && !visited[row + 1][col]))
    {
        // Wall Hit or Surrounded by Pocket
        return;
    }

    visited[row][col] = true;
    if (path[steps] == 'U' && row - 1 >= 0 && !visited[row - 1][col])
    {
        steps++;
        move(row - 1, col, ans, steps);
        steps--;
    }

    if (path[steps] == 'R' && col + 1 < n && !visited[row][col + 1])
    {
        steps++;
        move(row, col + 1, ans, steps);
        steps--;
    }

    if (path[steps] == 'D' && row + 1 < n && !visited[row + 1][col])
    {
        steps++;
        move(row + 1, col, ans, steps);
        steps--;
    }

    if (path[steps] == 'L' && col - 1 >= 0 && !visited[row][col - 1])
    {
        steps++;
        move(row, col - 1, ans, steps);
        steps--;
    }

    if (path[steps] == '?')
    {
        if (row + 1 < n && !visited[row + 1][col])
        {
            steps++;
            move(row + 1, col, ans, steps);
            steps--;
        }

        // move right
        if (col + 1 < n && !visited[row][col + 1])
        {
            steps++;
            move(row, col + 1, ans, steps);
            steps--;
        }

        // move up
        if (row - 1 >= 0 && !visited[row - 1][col])
        {
            steps++;
            move(row - 1, col, ans, steps);
            steps--;
        }

        // move left
        if (col - 1 >= 0 && !visited[row][col - 1])
        {
            steps++;
            move(row, col - 1, ans, steps);
            steps--;
        }
    }
    visited[row][col] = false;
}

int main()
{
    cin >> path;
    int ans = 0, steps = 0;
    move(0, 0, ans, steps);
    cout << ans << endl;
    return 0;
}