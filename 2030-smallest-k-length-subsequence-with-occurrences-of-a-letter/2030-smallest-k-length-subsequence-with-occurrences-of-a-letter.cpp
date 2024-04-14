class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int count1 = 0;
        int count2 = 0;
        int k1 = s.size() - k;
        int count = 0;
        for(char c : s)
            if(c == letter) ++count;
        int k2 = count - repetition;
        stack<int> Stack;
        for(int i = 0; i < s.size(); ++i) {
            while(!Stack.empty() && s[i] < Stack.top() && count1 < k1 && (Stack.top() != letter || (Stack.top() == letter && count2 < k2))) {
                count2 += (Stack.top() == letter);
                Stack.pop();
                ++count1;
            }
            Stack.push(s[i]);
        }
        
        string ret;
        while(!Stack.empty()) {
            ret.push_back(Stack.top());
            Stack.pop();
        }
        
        string ans;
        
        for(int i = 0; i < ret.size(); ++i) {
            if(count1 == k1 || (ret[i] == letter && k2 == count2)) ans.push_back(ret[i]);
            else {
                count1++;
                if(ret[i] == letter) ++count2;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};