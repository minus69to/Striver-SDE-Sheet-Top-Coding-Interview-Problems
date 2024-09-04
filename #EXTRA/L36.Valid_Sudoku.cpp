#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int n = board.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                else
                {
                    if (isSafe(board, i, j, n, board[i][j]))
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                
            }
            
        }
        
        return true;
    }

    bool isSafe(vector<vector<char>> &board, int r, int c, int n, char num)
    {
        for (int i = 0; i < n; i++)
        {
            if (i != c && board[r][i] == num) // Row
            {
                return false;
            }

            if (i != r && board[i][c] == num) // Column
            {
                return false;
            }
        }

        int smallN = sqrt(n);
        int startRow = r - r % smallN;
        int startCol = c - c % smallN;

        for (int i = startRow; i < startRow + smallN; i++)
        {
            for (int j = startCol; j < startCol + smallN; j++)
            {
                if ((i != r && j != c) && board[i][j] == num)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};

int main()
{
    return 0;
}

// https://leetcode.com/problems/valid-sudoku/description/