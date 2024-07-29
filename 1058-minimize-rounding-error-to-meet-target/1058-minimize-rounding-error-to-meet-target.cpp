class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        int mi = 0;
        vector<double> arr;
        for(string p : prices) {
            double pd = stod(p);
            mi += (int)pd;
            double dd = pd - (int)pd;
            if(dd > 0) arr.push_back(dd);
        }
        
        if(target < mi || target > mi + arr.size()) return "-1";
        
        sort(arr.rbegin(), arr.rend());
        int d = target - mi;
        double ans = d;
        
        for(int i=0; i < d; ++i) {
            ans -= arr[i];
        }
        for(int i=d; i < arr.size(); ++i) {
            ans += arr[i];
        }
        string res = to_string(ans);
        return res.substr(0, res.find('.') + 4);

    }
};