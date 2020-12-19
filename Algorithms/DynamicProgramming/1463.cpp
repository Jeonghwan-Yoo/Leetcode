// O(N * M^2)
class Solution {
public:
    int Dfs(int row, int col1, int col2, vector<vector<vector<int>>> &dp, vector<vector<int>> const &grid)
    {
        if (row >= (int)grid.size() || col1 < 0 || col1 >= (int)grid[0].size() || col2 < 0 || col2 >= (int)grid[0].size())
            return 0;
        
        int &ret = dp[row][col1][col2];
        if (ret != -1)
            return ret;
        
        ret = grid[row][col1];
        if (col1 != col2)
            ret += grid[row][col2];
        
        int maxVal = 0;
        for (int i = col1 - 1; i <= col1 + 1; ++i)
            for (int j = col2 - 1; j <= col2 + 1; ++j)
                maxVal = max(maxVal, Dfs(row + 1, i, j, dp, grid));
        
        ret += maxVal;
        
        return ret;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        
        return Dfs(0, 0, m - 1, dp, grid);
    }
};