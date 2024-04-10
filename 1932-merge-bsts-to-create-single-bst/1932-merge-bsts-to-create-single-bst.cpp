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
    unordered_map<int, TreeNode*> val2root;
    unordered_set<int> leafs;
    unordered_set<int> roots;
    
    void find(TreeNode* node) {
        if(node == NULL) return;
        leafs.insert(node->val);
        find(node->left); find(node->right);
    }
    
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        int n = trees.size();
        for(int i = 0; i < n; ++i) {
            val2root[trees[i]->val] = trees[i];
            find(trees[i]->left); find(trees[i]->right);
        }
        TreeNode* rt;
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(leafs.find(trees[i]->val) == leafs.end()) {
                rt = trees[i];
                ++count;
            }
        }
        if(count != 1) return NULL;
        roots.insert(rt->val);
        if(dfs(rt, INT_MIN, INT_MAX) && roots.size() == n) return rt;
        else return NULL;
    }
    
    bool dfs(TreeNode*& node, int mn, int mx) {
        if(node == NULL) return true;
        int val = node->val;
        if(val < mn || val > mx) return false;
        if(node->left || node->right) return dfs(node->left, mn, val-1) && dfs(node->right, val+1, mx);
        else if(val2root.find(val) != val2root.end()) {
            node = val2root[val];
            roots.insert(val);
            return dfs(node->left, mn, val-1) && dfs(node->right, val+1, mx);
        } else return true;
    }
};