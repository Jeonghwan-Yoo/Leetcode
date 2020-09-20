// O(3^N)
class Solution {
public:
    int Backtracking(int sx, int sy, int ex, int ey, int cnt, vector<vector<int>> &grid)
    {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        if (sx < 0 || sx >= m || sy < 0 || sy >= n)
            return 0;
        
        if (grid[sy][sx] == -1)
            return 0;
        
        if (sx == ex && sy == ey)
        {
            if (cnt == 0)
                return 1;
            return 0;
        }
        
        int ret = 0;
        grid[sy][sx] = -1;
        ret += Backtracking(sx, sy - 1, ex, ey, cnt - 1, grid) + Backtracking(sx + 1, sy, ex, ey, cnt - 1, grid) + Backtracking(sx, sy + 1, ex, ey, cnt - 1, grid) + Backtracking(sx - 1, sy, ex, ey, cnt - 1, grid);
        grid[sy][sx] = 0;
        
        return ret;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        
        int sx = 0;
        int sy = 0;
        int ex = 0;
        int ey = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 0)
                    ++cnt;
                else if (grid[i][j] == 1)
                {
                    sx = j;
                    sy = i;
                }
                else if (grid[i][j] == 2)
                {
                    ex = j;
                    ey = i;
                    ++cnt;
                }
            }
        }
        
        return Backtracking(sx, sy, ex, ey, cnt, grid);
    }
};