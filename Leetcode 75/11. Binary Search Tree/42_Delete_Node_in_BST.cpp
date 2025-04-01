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
    TreeNode *inorderSuccessor(TreeNode *root)
    {
        while (root->left != nullptr)
        {
            root = root->left;
        }

        return root;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == nullptr)
            {
                TreeNode *temp = root->right;
                delete (root);
                return temp;
            }
            else if (root->right == nullptr)
            {
                TreeNode *temp = root->left;
                delete (root);
                return temp;
            }

            TreeNode *temp = inorderSuccessor(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};

int main()
{
    vector<int> arr = {5, 3, 6, 2, 4, 7};

    TreeNode *root = buildTree(arr);

    cout << "In-order traversal of BST: ";
    inorder(root);
    cout << endl;

    Solution solution;

    cout << "In-order traversal of BST: ";
    inorder(solution.deleteNode(root, 2));
    cout << endl;

    return 0;
}