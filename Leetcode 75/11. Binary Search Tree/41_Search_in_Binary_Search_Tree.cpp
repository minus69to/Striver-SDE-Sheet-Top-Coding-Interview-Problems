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

TreeNode *insert(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return new TreeNode(val);
    }

    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }

    if (val > root->val)
    {
        root->right = insert(root->right, val);
    }

    return root;
}

TreeNode *buildTree(vector<int> arr)
{
    TreeNode *root = nullptr;

    for (int i = 0; i < arr.size(); i++)
    {
        root = insert(root, arr[i]);
    }

    return root;
}

TreeNode *search(TreeNode *root, int val)
{
    if (root == nullptr || root->val == val)
    {
        return root;
    }

    if (val < root->val)
    {
        return search(root->left, val);
    }

    return search(root->right, val);
}

void inorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr || root->val == val)
        {
            return root;
        }
    
        if (val < root->val)
        {
            return searchBST(root->left, val);
        }
    
        return searchBST(root->right, val);
    }
};

int main()
{
    vector<int> arr = {50, 30, 70, 20, 40, 60, 80};

    TreeNode *root = buildTree(arr);

    cout << "In-order traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}