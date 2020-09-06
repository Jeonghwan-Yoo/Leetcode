// O(N^4)
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = (int)A.size();
        
        int maxVal = 0;
        for (int y = -n + 1; y < n; ++y)
        {
            for (int x = -n + 1; x < n; ++x)
            {
                int val = 0;
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        if (i + y < 0 || i + y >= n || j + x < 0 || j + x >= n)
                            continue;
                        if (A[i + y][j + x] == 1 && B[i][j] == 1)
                            ++val;
                    }
                }
                if (maxVal < val)
                    maxVal = val;
            }
        }
        
        return maxVal;
    }
};