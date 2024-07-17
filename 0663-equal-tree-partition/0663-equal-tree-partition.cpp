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
    vector<int> seen;
    bool checkEqualTree(TreeNode* root) {
        int total = dfs(root);
        seen.pop_back();
        for(int s : seen)
            if(2*s == total) return true;
        return false;
    }
    
    int dfs(TreeNode* root) {
        if(!root) return 0;
        seen.push_back(root->val + dfs(root->left) + dfs(root->right));
        return seen.back();
    }
};