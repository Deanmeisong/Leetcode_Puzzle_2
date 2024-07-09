class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        short m[10001] = {};
        short max_cnt = 0, max_n = 0, pos = 0;;
        for(int bar : barcodes) {
            max_cnt = max(max_cnt, ++m[bar]);
            max_n = max_cnt == m[bar] ? bar : max_n;
        }
        for(int i = 0; i < 10001; ++i) {
            auto n = i == 0 ? max_n : i;
            while(m[n]-- > 0) {
                barcodes[pos] = n;
                pos = pos + 2 < barcodes.size() ? pos + 2 : 1;
            }
        }
        return barcodes;
    }
};