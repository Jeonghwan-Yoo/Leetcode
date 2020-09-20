// O(3^N)
class Solution {
public:
    int const dx[4] = { 0, 1, 0, -1 };
    int const dy[4] = { -1, 0, 1, 0 };
    
    int Dfs(int sx, int sy, int ex, int ey, int cnt, vector<vector<int>> &grid)
    {
        if (sx == ex && sy == ey)
        {
            if (cnt == 0)
                return 1;
            return 0;
        }
        
        int ret = 0;
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        for (int i = 0; i < 4; ++i)
        {
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            
            if (grid[ny][nx] != -1)
            {
                grid[ny][nx] = -1;
                ret += Dfs(nx, ny, ex, ey, cnt - 1, grid);
                grid[ny][nx] = 0;
            }
        }
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
        grid[sy][sx] = -1;
        
        return Dfs(sx, sy, ex, ey, cnt, grid);
    }
};