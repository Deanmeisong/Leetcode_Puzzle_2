/**
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
    unordered_map<TreeNode*, vector<TreeNode*>> neis;
    TreeNode* start;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) return std::vector<int>{target->val};
        dfs(root, nullptr);
        int steps = 0;
        queue<TreeNode*> q;
        unordered_set<TreeNode*> seen;
        q.push(target);
        seen.insert(target);
        vector<int> ans;
        while(!q.empty() && steps <= k) {
            int len = q.size();
            while(len--) {
                TreeNode* cur = q.front(); q.pop();
                if(steps == k) ans.push_back(cur->val);
                for(TreeNode* nei : neis[cur]) 
                    if(!seen.count(nei)) {
                        q.push(nei);
                        seen.insert(nei);
                    }
     
            }
            ++steps;
        }
        return ans;

    }
    void dfs(TreeNode* node, TreeNode* parent) {
        if(parent) {
            neis[node].push_back(parent);
            neis[parent].push_back(node);
        }
        if(node->left) dfs(node->left, node);
        if(node->right) dfs(node->right, node);
    }
};