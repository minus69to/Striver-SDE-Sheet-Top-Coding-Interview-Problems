#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int blackBoxes(vector<vector<int>> &matrix, int R, int C, int mid)
    {
        int count = 0;
        for (int i = 0; i < R; i++)
        {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        return count;
    }

    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < R; i++)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C - 1]);
        }

        // cout << "Low: " << low << " High: " << high << endl;

        int desired = (R * C) / 2;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            int smallOrEqual = blackBoxes(matrix, R, C, mid);

            if(smallOrEqual <= desired)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low;
    }
};

void printMatrix(vector<vector<int>> &matrix, int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int R, C;
    cin >> R >> C;

    vector<vector<int>> matrix(R, vector<int>(C));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> matrix[i][j];
        }
    }

    printMatrix(matrix, R, C);

    Solution obj;
    cout << obj.median(matrix, R, C) << endl;

    return 0;
}

// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=median-in-a-row-wise-sorted-matrix