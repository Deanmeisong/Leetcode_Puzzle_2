class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        if(deads.count("0000")) return -1;
        queue<string> q;
        q.push("0000");
        for(int step = 0; !q.empty(); ++step) {
            for(int i = q.size(); i > 0; --i) {
                string curr = q.front(); q.pop();
                if(target == curr) return step;
                for(string nei : getN(curr)) {
                    if(deads.count(nei)) continue;
                    deads.insert(nei);
                    q.push(nei);
                }
            }
        }

        return -1;
    }
    
    vector<string> getN(string code) {
        vector<string> result;
        for (int i = 0; i < 4; i++) {
            for (int diff = -1; diff <= 1; diff += 2) {
                string nei = code;
                nei[i] = (nei[i] - '0' + diff + 10) % 10 + '0';
                result.push_back(nei);
            }
        }
        return result;
    }
};