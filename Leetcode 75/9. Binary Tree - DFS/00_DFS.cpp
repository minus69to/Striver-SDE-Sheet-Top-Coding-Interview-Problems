#include <bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;

// TreeNode class with conventional constructor style
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // Default constructor
    TreeNode()
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    // Parameterized constructor for value only
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    // Parameterized constructor for value + children
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode)
    {
        val = x;
        left = leftNode;
        right = rightNode;
    }
};

TreeNode *buildTree(vector<int> nodes)
{
    if (nodes.empty() || nodes[0] == INT_MIN)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(nodes[0]);

    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (i < nodes.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (nodes[i] != INT_MIN)
        {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != INT_MIN)
        {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        cout << "Empty Tree!" << endl;
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int lavelSize = q.size();

        for (int i = 0; i < lavelSize; i++)
        {
            TreeNode *current = q.front();
            q.pop();

            cout << current->val << " ";

            if (current->left != nullptr)
            {
                q.push(current->left);
            }

            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
        cout << endl;
    }
    cout << endl;
}

void freeTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

class Solution
{
public:
    void DFS(TreeNode *root, vector<int> &path, vector<vector<int>> &allPaths)
    {
        if (root == nullptr)
        {
            return;
        }

        path.push_back(root->val); // Add current node to path

        // If it's a leaf node, add the path to allPaths
        if (root->left == nullptr && root->right == nullptr)
        {
            allPaths.push_back(path);
        }
        else
        {
            // Recursive DFS for left and right children
            DFS(root->left, path, allPaths);
            DFS(root->right, path, allPaths);
        }

        path.pop_back(); // Backtrack
    }

    void printAllPaths(TreeNode *root)
    {
        vector<int> path;
        vector<vector<int>> allPaths;
        DFS(root, path, allPaths);

        for (auto path : allPaths)
        {
            for (auto val : path)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<int> nodes = {0, 1, 2, 1, 2, 3, 4, 1, 2, 3, 4, 5, 6, 7, 8};
    TreeNode *root = buildTree(nodes);
    printTree(root);

    Solution solution;
    solution.printAllPaths(root);

    return 0;
}