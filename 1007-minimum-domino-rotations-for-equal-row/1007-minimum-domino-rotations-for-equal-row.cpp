class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> countA(7); vector<int> countB(7); vector<int> same(7);
        for(int i = 0; i < A.size(); ++i) {
            countA[A[i]]++;
            countB[B[i]]++;
            if(A[i] == B[i]) same[A[i]]++;
        }
        for(int i = 1; i < 7; ++i)
            if(countA[i] + countB[i] - same[i] == A.size()) return A.size() - max(countA[i], countB[i]);
        return -1;
    }
};