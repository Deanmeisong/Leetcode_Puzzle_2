class BIT {
    public:
    int N;
    vector<long long> arr;
    long long M = 1e9+7;
    
    BIT(int N) {
        this->N = N;
        arr.resize(N+1);
    }
    
    void update(int i, int delta) {
        int idx = i;
        while (idx <= N)
        {
            arr[idx]+=delta;
            arr[idx] %= M;
            idx+=idx&(-idx);
        }
    }
    
    long long query(int i) {
        long long result = 0;
        while (i){
            result += arr[i];
            result %= M;
            i-=i&(-i);
        }
        return result;
    }
    
    long long querySum(int i, int j) {
        return query(j) - query(i-1);
    }
    
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int> Map;
        for(int i = 0; i < n; ++i)
            Map[nums1[i]] = i;
        for(int i = 0; i < n; ++i)
            nums2[i] = Map[nums2[i]] + 1;
        BIT bit1(100005);
        vector<int> preSmaller(n, 0);
        for(int i = 0; i < n; ++i) {
            preSmaller[i] = bit1.querySum(1, nums2[i]);
            bit1.update(nums2[i], 1);
        }
        BIT bit2(100005);
        vector<int> afterBigger(n, 0);
        for(int i = n-1; i >= 0; --i) {
            afterBigger[i] = bit2.querySum( nums2[i], 100005);
            bit2.update(nums2[i], 1);
        }
        long long ret = 0;
        for(int i = 0; i < n; ++i)
            ret += (long long)preSmaller[i] * (long long)afterBigger[i];
        return ret;
    }
};