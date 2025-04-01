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
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++)
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
    delete (root);
}

class Solution
{
    void maxZigZag(TreeNode *node, bool goLeft, int steps, int &maxLen)
    {
        if (node == nullptr)
        {
            return;
        }

        maxLen = max(maxLen, steps);

        if (goLeft)
        {
            // If we should go left, continue zigzag by going left
            maxZigZag(node->left, false, steps + 1, maxLen);
            // Reset zigzag by going right
            maxZigZag(node->right, true, 1, maxLen);
        }
        else
        {
            // If we should go right, continue zigzag by going right
            maxZigZag(node->right, true, steps + 1, maxLen);
            // Reset zigzag by going left
            maxZigZag(node->left, false, 1, maxLen);
        }
    }

public:
    int longestZigZag(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int maxLen = 0;

        // Start zigzag paths from the root
        maxZigZag(root, true, 0, maxLen);  // Try going left first
        maxZigZag(root, false, 0, maxLen); // Try going right first

        return maxLen;
    }
};

int main()
{
    TreeNode *root = buildTree({1, INT_MIN, 1, 1, 1, INT_MIN, INT_MIN, 1, 1, INT_MIN, 1, INT_MIN, INT_MIN, INT_MIN, 1});
    printTree(root);

    Solution solution;
    cout << "Longest ZigZag Path: " << solution.longestZigZag(root) << endl;

    return 0;
}