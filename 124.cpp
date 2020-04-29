// https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
    int ans = INT_MIN;
public:
    int maxUtil(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int leftSum = maxUtil(root->left);
        int rightSum = maxUtil(root->right);
        
        int curMax = max({leftSum, rightSum, leftSum + rightSum, 0}) + root->val;
        ans = max(ans, curMax);
        
        return max({leftSum, rightSum, 0}) + root->val;
        
    }
    
    int maxPathSum(TreeNode* root) {
        maxUtil(root);
        return ans;
    }
};