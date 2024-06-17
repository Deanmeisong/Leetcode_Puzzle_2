class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.empty()) return 0;
        int n = arr.size();
        vector<int> maxArr(n,0);
        maxArr[0] = arr[0];
        for(int i = 1; i < n; ++i)
            maxArr[i] = max(maxArr[i-1], arr[i]);
        int count = 0;
        for(int i = 0; i < n; ++i)
            if(maxArr[i] == i) ++count;
        return count;
    }
};