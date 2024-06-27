class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%10 != 1 && k%10 != 3 && k%10 != 7 && k%10 != 9) return -1;
        int m = 0;
        unordered_set<int> ms;
        for(int i = 1; i <= k; ++i) {
            m = (m*10+1)%k;
            if(m == 0) return i;
            if(ms.count(m)) return -1;
            ms.insert(m);
        }
        return -1;
    }
};