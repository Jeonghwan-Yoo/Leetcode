// O(NlogN)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = (int)points.size();
        if (n == 0)
            return 0;
        
        sort(points.begin(), points.end(), [&points](vector<int> const &a, vector<int> const &b)
        {
            return a[1] < b[1];
        });
        
        int cnt = 1;
        int end = points[0][1];
        for (int i = 1; i < n; ++i)
        {
            if (points[i][0] > end)
            {
                end = points[i][1];
                ++cnt;
            }
        }
        
        return cnt;
    }
};