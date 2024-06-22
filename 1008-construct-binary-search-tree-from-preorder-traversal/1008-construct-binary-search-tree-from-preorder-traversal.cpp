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
    TreeNode* dfs(vector<int>& A, int& i, int bound) {
        if(i >= A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = dfs(A, i, root->val);
        root->right = dfs(A, i, bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return dfs(A, i, INT_MAX);
    }
};