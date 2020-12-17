// O(N^2 * logN)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = (int)A.size();
        vector<int> v;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                v.emplace_back(A[i] + B[j]);
        sort(v.begin(), v.end());
        
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int sum = C[i] + D[j];
                ret += upper_bound(v.begin(), v.end(), -sum) - lower_bound(v.begin(), v.end(), -sum);
            }
        }
        
        return ret;
    }
};