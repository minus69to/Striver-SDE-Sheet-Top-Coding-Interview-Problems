#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(vector<vector<char>> &board, int r, int c, char num)
    {
        for (int i = 0; i < board.size(); i++)
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

        int smallN = sqrt(board.size());
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

    bool utility(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isSafe(board, i, j, c))
                        {
                            board[i][j] = c;

                            bool furtherSolvable = utility(board);

                            if (furtherSolvable)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        bool ans = utility(board);
    }
};

int main()
{
    Solution sol;
    
    return 0;
}

// https://leetcode.com/problems/sudoku-solver/description/