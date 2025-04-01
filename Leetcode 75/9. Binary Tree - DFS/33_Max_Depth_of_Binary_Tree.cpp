#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{
    // vector<int> nodes = {3, 9, 20, INT_MIN, INT_MIN, 15, 7};
    vector<int> nodes = {0, 1, 2, 1, 2, 3, 4, 1, 2, 3, 4, 5, 6, 7, 8};
    TreeNode *root = buildTree(nodes);
    printTree(root);

    Solution solution;
    cout << "Maximum depth: " << solution.maxDepth(root) << endl;

    return 0;
}