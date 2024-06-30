/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return ans;
        dfs(root, root->val, root->val);
        return ans;
    }
    
    void dfs(TreeNode* root, int curMax, int curMin) {
        if(!root) return;
        ans = max(ans, max(abs(curMax-root->val), abs(curMin-root->val)));
        curMax = max(root->val, curMax);
        curMin = min(root->val, curMin);
        dfs(root->left, curMax, curMin);
        dfs(root->right, curMax, curMin);
    }
};