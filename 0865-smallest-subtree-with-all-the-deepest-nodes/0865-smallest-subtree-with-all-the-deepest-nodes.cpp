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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
    
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if(!root) return {-1, nullptr};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int dl = l.first; int dr = r.first;
        return {max(dl, dr)+1, dl == dr ? root : dl > dr ? l.second : r.second};
    }
};