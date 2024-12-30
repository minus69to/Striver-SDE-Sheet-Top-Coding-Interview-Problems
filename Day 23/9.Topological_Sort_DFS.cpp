#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        // Initialize
        int V = adj.size();
        stack<int> result;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                dfs(adj, i, visited, result);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            ans.push_back(result.top());
            result.pop();
        }

        return ans;
    }

    void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited, stack<int> &result)
    {
        if (visited[node] == true)
        {
            return;
        }

        visited[node] = true;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int neighbour = graph[node][i];
            if (visited[neighbour] == false)
            {
                dfs(graph, neighbour, visited, result);
            }
        }

        result.push(node);
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