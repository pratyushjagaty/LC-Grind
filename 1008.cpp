/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    int n;

public:
    TreeNode *constructTree(int &cur, int mini, int maxi, vector<int> &preorder)
    {
        if (cur >= n)
        {
            return NULL;
        }

        TreeNode *root = NULL;

        if (preorder[cur] >= mini and preorder[cur] <= maxi)
        {
            root = new TreeNode(preorder[cur++]);

            if (cur < n)
            {
                root->left = constructTree(cur, mini, root->val, preorder);
                root->right = constructTree(cur, root->val, maxi, preorder);
            }
        }

        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        n = preorder.size();
        int start = 0;
        return constructTree(start, INT_MIN, INT_MAX, preorder);
    }
};