// O(NlogN)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&intervals](vector<int> const &a, vector<int> const &b)
        {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int n = (int)intervals.size();
        int cur = intervals[0][1];
        int cnt = 1;
        for (int i = 1; i < n; ++i)
        {
            if (cur < intervals[i][1])
            {
                cur = intervals[i][1];
                ++cnt;
            }
        }
        
        return cnt;
    }
};