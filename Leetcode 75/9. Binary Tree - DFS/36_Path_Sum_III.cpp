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

// class Solution
// {
//     int countPaths(TreeNode *node, long long target)
//     {
//         if (node == nullptr)
//         {
//             return 0;
//         }

//         int count = 0;
//         if (node->val == target)
//         {
//             count++; // count = 1 --> also correct;
//         }

//         count += countPaths(node->left, target - node->val) + countPaths(node->right, target - node->val);

//         return count;
//     }

// public:
//     int pathSum(TreeNode *root, int targetSum)
//     {
//         if (root == nullptr)
//         {
//             return 0;
//         }

//         return countPaths(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
//     }
// };

class Solution
{
    int countPaths(TreeNode *node, long long runningSum, long long targetSum, unordered_map<long long, long long> mp)
    {
        if (node == nullptr)
        {
            return 0;
        }

        runningSum += node->val;

        int count = mp[runningSum - targetSum];

        mp[runningSum]++;

        count += countPaths(node->left, runningSum, targetSum, mp) + countPaths(node->right, runningSum, targetSum, mp);

        mp[runningSum]--;

        return count;
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        unordered_map<long long, long long> mp;
        mp[0] = 1;

        return countPaths(root, 0, targetSum, mp);
    }
};

int main()
{
    TreeNode *root = buildTree({10, 5, -3, 3, 2, INT_MIN, 11, 3, -2, INT_MIN, 1});
    printTree(root);

    Solution solution;
    cout << solution.pathSum(root, 8);

    return 0;
}

// https://leetcode.com/problems/path-sum-iii/?envType=study-plan-v2&envId=leetcode-75