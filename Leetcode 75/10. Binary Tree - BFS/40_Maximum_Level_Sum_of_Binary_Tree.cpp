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
    int maxLevelSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        int currentLevel = 1;
        int minLevel = 1;

        int currentSum = 0;
        int maxSum = INT_MIN;

        while (!q.empty())
        {
            int size = q.size();
            currentSum = 0;

            for (int i = 0; i < size; i++)
            {
                TreeNode *current = q.front();
                q.pop();

                currentSum += current->val == INT_MIN ? 0 : current->val;

                if (current->left != nullptr)
                {
                    q.push(current->left);
                }

                if (current->right != nullptr)
                {
                    q.push(current->right);
                }
            }

            if (currentSum > maxSum)
            {
                maxSum = currentSum;
                minLevel = currentLevel;
            }

            currentLevel++;
        }

        return minLevel;
    }
};

int main()
{
    vector<int> nodes = {-100, -200, -300, -20, -5, -10, INT_MIN};
    TreeNode *root = buildTree(nodes);
    printTree(root);

    Solution solution;
    cout << solution.maxLevelSum(root);

    return 0;
}

// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75