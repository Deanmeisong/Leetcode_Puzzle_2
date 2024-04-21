class Solution {
public:
    vector<int> children[100000];
    int len[100000];
    int global = 1;
    string s;
    int longestPath(vector<int>& parent, string s) {
        this->s = s;
        for(int i = 0; i < parent.size(); ++i) {
            if(parent[i] == -1) continue;
            children[parent[i]].push_back(i);
        }
        
        dfs(0);
        return global;
    }
    
    void dfs(int cur) {
        if(children[cur].size() == 0) {
            len[cur] = 1;
            return;
        }
        
        vector<int> temp;
        int ret = 1;
        for(int child : children[cur]) {
            dfs(child);
            if(s[child] != s[cur]) {
                ret = max(len[child]+1, ret);
                temp.push_back(len[child]);
            }
 
        }
        len[cur] = ret;
        
        sort(temp.rbegin(), temp.rend());
        if(temp.size() >= 2) global = max(global, temp[0]+temp[1]+1);
        else if(temp.size() == 1) global = max(global, temp[0]+1);
        // else global = max(global, 1);
    }
};