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
public:
    void getMax(TreeNode *root, int &ans, int maximum)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->val >= maximum)
        {
            ans++;
            maximum = root->val;
        }

        getMax(root->left, ans, maximum);
        getMax(root->right, ans, maximum);
    }

    int goodNodes(TreeNode *root)
    {
        int ans = 0;
        getMax(root, ans, INT_MIN);

        return ans;
    }
};

int main()
{
    TreeNode *root = buildTree({3, 1, 4, 3, INT_MIN, 1, 5});
    printTree(root);

    Solution solution;
    cout << solution.goodNodes(root);

    return 0;
}