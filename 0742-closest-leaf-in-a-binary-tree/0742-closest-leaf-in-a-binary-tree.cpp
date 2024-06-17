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
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    TreeNode* start = nullptr;
    int findClosestLeaf(TreeNode* root, int k) {
        dfs(root, nullptr, k);
        queue<TreeNode*> q;
        q.push(start);
        unordered_set<TreeNode*> seen;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                TreeNode* cur = q.front(); q.pop();
                seen.insert(cur);
                if(!cur->left && !cur->right) return cur->val;
                for(TreeNode* nei : graph[cur])
                    if (!seen.count(nei)) q.push(nei);
            }
        }
        return 0;
    }
    
    void dfs(TreeNode* node, TreeNode* parent, int val) {
        if(!node) return;
        if(node->val == val) start = node;
        if(parent) {
            graph[node].push_back(parent);
            graph[parent].push_back(node);
        }
        if(node->left) dfs(node->left, node, val);
        if(node->right) dfs(node->right, node, val);
    }
};