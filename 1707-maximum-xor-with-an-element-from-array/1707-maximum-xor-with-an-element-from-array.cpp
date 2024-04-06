class Solution {
    class TrieNode {
        public:
        TrieNode* next[2];
    };
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < queries.size(); ++i) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), cmp);
        vector<int> rets(queries.size());
        int i = 0;
        TrieNode* root = new TrieNode();
        
        for(auto& q : queries) {
            while(i < nums.size() && nums[i] <= q[1]) {
                TrieNode* node = root;
                for(int k = 31; k >= 0; --k) {
                    if(node->next[(nums[i]>>k)&1] == NULL) node->next[(nums[i]>>k)&1] = new TrieNode();
                    node = node->next[(nums[i]>>k)&1];
                }
                ++i;
            }
            if(i == 0) {
                rets[q[2]] = -1; continue;
            }
            int ans = 0;
            TrieNode* node = root;
            for(int k = 31; k >= 0; --k) {
                if(node->next[1-((q[0]>>k)&1)] != NULL) {
                    ans = ans*2 + 1;
                    node = node->next[1-((q[0]>>k)&1)];
                } else {
                    ans = ans*2;
                    node = node->next[(q[0]>>k)&1];
                }
            }
             rets[q[2]] = ans;
        }
        return rets;
    }
};