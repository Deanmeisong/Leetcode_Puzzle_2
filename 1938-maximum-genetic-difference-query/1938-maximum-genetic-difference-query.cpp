class Solution {
    class TrieNode {
    public:
        TrieNode* next[2];
        int cnt;
        TrieNode() {
            for(int i = 0; i < 2; ++i) next[i] = NULL;
            cnt = 0;
        }
    };
public:
    TrieNode* root;
    vector<int> children[100005];
    unordered_map<int, vector<pair<int,int>>> Map;
    vector<int> rets;
    
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int rootVal = -1;
        for(int i = 0; i < parents.size(); ++i) {
            if(parents[i] == -1) rootVal = i;
            else children[parents[i]].push_back(i);
        }
        rets.resize(queries.size());
        root = new TrieNode();
        for(int i = 0; i < queries.size(); ++i) Map[queries[i][0]].push_back({queries[i][1], i});
        dfs(rootVal);
        return rets;
    }
    
    void dfs(int curVal) {
        TrieNode* node = root;
        for(int i = 31; i >= 0; --i) {
            int d = (curVal>>i)&1;
            if(node->next[d] == NULL) node->next[d] = new TrieNode();
            node = node->next[d];
            node->cnt++;
        }
        
        for(auto q : Map[curVal]) {
            int val = q.first; int idx = q.second;
            node = root;
            int ans = 0;
            for(int i = 31; i >= 0; --i) {
                int d = (val>>i)&1;
                if(node->next[1-d] != NULL && node->next[1-d]->cnt > 0) {
                    node = node->next[1-d];
                    ans = 2*ans + (1-d);
                } else {
                    node = node->next[d];
                    ans = 2*ans + (d);
                }
            }
            rets[idx] = ans^val;
        }
        
        for(int child : children[curVal]) dfs(child);
        node = root;
        for(int i = 31; i >= 0; --i) {
            int d = (curVal>>i)&1;
            node = node->next[d];
            node->cnt-=1;
        }
    }
};