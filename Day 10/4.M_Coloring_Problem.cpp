#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(bool graph[101][101], int n, int ind, int color[], int col)
    {
        for (int i = 0; i < n; i++)
        {
            if (graph[ind][i] == 1 && color[i] == col)
            {
                return false;
            }
        }

        return true;
    }

    bool graphColoringUtil(bool graph[101][101], int m, int n, int color[], int ind)
    {
        if (ind == n)
        {
            return true;
        }
        
        for (int c = 1; c <= m; c++)
        {
            if (isSafe(graph, n, ind, color, c))
            {
                color[ind] = c;

                if (graphColoringUtil(graph, m, n, color, ind+1))
                {
                    return true;
                }
                
                color[ind] = 0;
            }
        }
        
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n)
    {
        int color[n];
        memset(color, 0, n);

        if (!graphColoringUtil(graph, m, n, color, 0))
        {
            return false;
        }
        
        return true;
    }
};   


int main()
{
    int n = 4; // Row size
    int m = 3; // Number of colors

    bool graph[101][101] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };

    Solution sol;
    cout << sol.graphColoring(graph, m, n) << endl;

    return 0;
}

// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1