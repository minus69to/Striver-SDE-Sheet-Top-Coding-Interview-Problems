#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<int> topSorted = topologicalSort(graph);

        if (topSorted.size() == numCourses)
        {
            return true;
        }

        return false;
    }

    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int course = prerequisites[i][0];
            int dependency = prerequisites[i][1];
            graph[dependency].push_back(course);
        }

        return graph;
    }

    vector<int> topologicalSort(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> inDegree(V, 0);
        vector<int> result;
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                int neighbour = graph[i][j];
                inDegree[neighbour] += 1;
            }
        }

        for (int i = 0; i < V; i++)
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

            for (int i = 0; i < graph[current].size(); i++)
            {
                int neighbour = graph[current][i];
                inDegree[neighbour] -= 1;

                if (inDegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        return result;
    }

    void printGraph(vector<vector<int>> graph)
    {
        for (int i = 0; i < graph.size(); i++)
        {
            cout << i << " : ";
            for (int j = 0; j < graph[i].size(); j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    // freopen("input.txt", "r", stdin);

    Solution soluton;

    int numCourses = 5;
    // vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}, {4, 3}};
    // vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}, {4, 3}};
    vector<vector<int>> prerequisites = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 3}};

    cout << soluton.canFinish(numCourses, prerequisites) << endl;

    return 0;
}