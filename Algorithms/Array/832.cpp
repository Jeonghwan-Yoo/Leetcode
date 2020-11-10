// O(N^2)
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = (int)A.size();
        int n2 = (n + 1) >> 1;
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n2; ++j)
            {
                int tmp = A[i][j];
                A[i][j] = A[i][n - j - 1] ^ 1;
                A[i][n - j - 1] = tmp ^ 1;
            }
        }
        
        return A;
    }
};