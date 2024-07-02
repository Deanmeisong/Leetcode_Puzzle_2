class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min(min(a, b), c);
        int z = max(max(a, b), c);
        int y = a+b+c-x-z;
        int mi = 0, ma = 0;
        if(z-x > 2) {
            mi = y-x < 3 || z-y < 3 ? 1 : 2;
            ma = z - x - 2;
        }
        return {mi, ma};
    }
};