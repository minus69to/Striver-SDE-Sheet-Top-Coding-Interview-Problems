#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     vector<int> dfsOfGraph(vector<vector<int>> &adj)
//     {
//         vector<int> dfs; // Final Answer
//         stack<int> s; // Stack

//         int V = adj.size();
//         vector<bool> visited(V, false);

//         s.push(0);

//         while (!s.empty())
//         {
//             int current = s.top();
//             s.pop();

//             if (!visited[current])
//             {
//                 dfs.push_back(current);
//                 visited[current] = true;

//                 for (int i = adj[current].size() - 1; i >= 0; i--)
//                 {
//                     int neighbour = adj[current][i];
//                     if (!visited[neighbour])
//                     {
//                         s.push(neighbour);
//                     }
//                 }
//             }
//         }

//         return dfs;
//     }
// };

class Solution
{
public:
    vector<int> dfsOfGraph(vector<vector<int>> &adj)
    {
        vector<int> result;
        vector<bool> visited(adj.size(), false);

        dfs(adj, 0, visited, result);

        return result;
    }

    void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited, vector<int>& result)
    {
        if (visited[node] ==  true)
        {
            return;
        }

        result.push_back(node);
        visited[node] = true;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int neighbour = graph[node][i];
            if (visited[neighbour] == false)
            {
                dfs(graph, neighbour, visited, result);
            }
        }
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;

    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
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
        vector<int> ans = obj.dfsOfGraph(adj);

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}