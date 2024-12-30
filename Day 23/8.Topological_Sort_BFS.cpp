#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        // Initialize
        vector<int> inDegree(adj.size(), 0);
        vector<int> result;
        queue<int> q;

        // Calculate indegree for each vertex
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                int neighbour = adj[i][j];
                inDegree[neighbour] += 1;
            }
        }

        // Store inorder 0 nodes in a queue
        for (int i = 0; i < inDegree.size(); i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            result.push_back(current);

            for (int i = 0; i < adj[current].size(); i++)
            {
                int neighbour = adj[current][i];
                inDegree[neighbour] -= 1;

                if (inDegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        return result;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        // for (int i = 0; i < adj.size(); i++)
        // {
        //     for (int j = 0; j < adj[i].size(); j++)
        //     {
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }

        cout << "\n\n";
    }

    return 0;
}