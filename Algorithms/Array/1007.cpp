// O(N)
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int sz = (int)A.size();
        
        vector<int> cntA(7);
        vector<int> cntB(7);
        vector<int> same(7);
        for (int i = 0; i < sz; ++i)
        {
            ++cntA[A[i]];
            ++cntB[B[i]];
            if (A[i] == B[i])
                ++same[A[i]];
        }
        for (int i = 1; i <= 6; ++i)
            if (cntA[i] + cntB[i] - same[i] == sz)
                return sz - max(cntA[i], cntB[i]);
        
        return -1;
    }
};