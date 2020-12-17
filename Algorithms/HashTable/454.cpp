// O(N^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = (int)A.size();
        unordered_map<int, int> um;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ++um[A[i] + B[j]];
        
        int ret = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ret += um[-(C[i] + D[j])];
        
        return ret;
    }
};