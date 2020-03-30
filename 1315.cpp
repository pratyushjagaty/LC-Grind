/**
 * https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/   
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int ans = 0;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            
            if (node->val % 2 == 0) {
                if (node->left) {
                    if (node->left->left) {
                        ans += node->left->left->val;
                    }
                    if (node->left->right) {
                        ans += node->left->right->val;
                    }
                }    
                
                if (node->right) {
                    if (node->right->left) {
                        ans += node->right->left->val;
                    }
                    if (node->right->right) {
                        ans += node->right->right->val;
                    }
                }    
            }
            
            if (node->left) {
                q.push(node->left);
            }
            
            if (node->right) {
                q.push(node->right);
            }
        }
        
        return ans;
    }
};