// O(NM)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = (int)matrix.size();
        if (n == 0)
            return false;
        
        int m = (int)matrix[0].size();
        if (m == 0)
            return false;
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (matrix[i][j] == target)
                    return true;
        
        return false;
    }
};