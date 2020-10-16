// O(log(NM))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = (int)matrix.size();
        if (n == 0)
            return false;
        
        int m = (int)matrix[0].size();
        if (m == 0)
            return false;
        
        int l = 0;
        int r = n * m - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            int midVal = matrix[mid / m][mid % m];
            if (midVal < target)
                l = mid + 1;
            else if (midVal > target)
                r = mid - 1;
            else
                return true;
        }
        
        return false;
    }
};