#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool checkValid(vector<vector<char>> &board, int row, int col, int size)
{

    // check top up
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // check diagonal
    for (int i = 1; i <= row; i++)
    {
        if (col - i >= 0)
        {
            // left diagonal
            if (board[row - i][col - i] == 'Q')
            {
                return false;
            }
        }
        if (col + i < size)
        {
            // right diagonal
            if (board[row - i][col + i] == 'Q')
            {
                return false;
            }
        }
    }
    return true;
}

void helper(vector<vector<char>> &board, int row, int size, int &count)
{
    if (row == size)
    {
        count++;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (board[row][i] == '*')
        {
            continue;
        }
        if (checkValid(board, row, i, size))
        {
            board[row][i] = 'Q';
            helper(board, row + 1, size, count);
            board[row][i] = '.';
        }
    }
}

int main()
{
    vector<vector<char>> board(8, vector<char>(8, ' '));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> board[i][j];
        }
    }
    int count = 0;
    helper(board, 0, 8, count);
    cout << count << '\n';
}