class Solution {
    class TrieNode {
    public:
        TrieNode* next[2];
        int count;
        TrieNode() {
            count = 0;
            for(int i = 0; i < 2; ++i) next[i] = NULL;
        }
    };
    
    TrieNode* root;
    vector<int> children[100005];
    unordered_map<int,vector<pair<int,int>>> Map;
    vector<int> rets;
    
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size();
        rets.resize(queries.size());
        int start;
        for(int i = 0; i < n; ++i) {
            if(parents[i] == -1) start = i;
            else children[parents[i]].push_back(i);
        }
        
        for(int i = 0; i < queries.size(); ++i) {
            int cur = queries[i][0];
            Map[cur].push_back({queries[i][1], i});
        }
        root = new TrieNode();
        dfs(start);
        return rets;
    }
    
    void dfs(int cur) {
        TrieNode* node = root;
        for(int i = 31; i >= 0; --i) {
            int d = ((cur>>i)&1);
            if(node->next[d] == NULL) node->next[d] = new TrieNode();
            node = node->next[d];
            node->count += 1;
        }
        
        for(auto x : Map[cur]) {
            int val = x.first; int idx = x.second;
            TrieNode* node = root;
            int ans = 0;
            for(int i = 31; i >= 0; --i) {
                int d = (val>>i)&1;
                if(node->next[1-d] != NULL && node->next[1-d]->count > 0) {
                    node = node->next[1-d];
                    ans = ans*2 + (1-d);
                } else {
                    node = node->next[d];
                    ans = ans*2 + (d);
                }
            }
            
            rets[idx] = ans^val;
        }
        
        for(int child : children[cur]) dfs(child);
        
        node = root;
        for(int i = 31; i >= 0; --i) {
            int d = (cur>>i)&1;
            node = node->next[d];
            node->count -= 1;
        }

    }
};