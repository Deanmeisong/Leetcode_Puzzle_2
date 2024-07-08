class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int i = n-2;
        for(; i >= 0; --i) {
            if(arr[i+1] < arr[i]) break;
        }
        if(i == -1) {
            cout<<"====================";
            return arr;
        }
        
        
        int j = n-1;
        while(arr[j] >= arr[i]) --j;
        while(arr[j] == arr[j-1]) --j;
        // for(; j > 0; --j) {
        //     if(arr[j] < arr[i] && arr[j] != arr[j-1]) break;
        // }
        swap(arr[i], arr[j]);
        return arr;
    }
};