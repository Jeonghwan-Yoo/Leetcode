// O(N)
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = (int)A.size();
        
        int longest = 0;
        int i = 1;
        while (i < n)
        {
            int inc = 0;
            int dec = 0;
            while (i < n && A[i - 1] < A[i])
            {
                ++i;
                ++inc;
            }
            while (i < n && A[i - 1] > A[i])
            {
                ++i;
                ++dec;
            }
            if (inc && dec)
                longest = max(longest, inc + dec + 1);
            
            while (i < n && A[i - 1] == A[i])
                ++i;
        }
        
        return longest;
    }
};