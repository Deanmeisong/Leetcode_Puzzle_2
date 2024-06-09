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
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        dfs(root, root->val);
        return ans;
    }
    
    int dfs(TreeNode* node, int val) {
        if(node == NULL) return 0;
        int lv = dfs(node->left, node->val);
        int rv = dfs(node->right, node->val);
        ans = max(lv+rv, ans);
        if(val == node->val) return max(lv, rv)+1;
        return 0;
    }
};