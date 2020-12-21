// O(NlogN)
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = (int)A.size();
        
        int ret = A[n - 1] - A[0];
        for (int i = 0; i < n - 1; ++i)
        {
            int big = max(A[i] + K, A[n - 1] - K);
            int small = min(A[i + 1] - K, A[0] + K);
            ret = min(ret, big - small);
        }
        
        return ret;
    }
};