// O(NlogN)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int n = (int)intervals.size();
        
        queue<pair<int, int>> q;
        q.emplace(intervals[0][0], intervals[0][1]);
        for (int i = 1; i < n; ++i)
        {
            if (intervals[i][1] > q.back().second)
            {
                if (intervals[i][0] > q.back().first)
                    q.emplace(intervals[i][0], intervals[i][1]);
                else if (intervals[i][0] == q.back().first)
                    q.back().second = intervals[i][1];
            }
        }
        
        return (int)q.size();
    }
};