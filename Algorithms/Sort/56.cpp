// O(NlogN)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = (int)intervals.size();
        
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());
        vector<int> cur(intervals[0].begin(), intervals[0].end());
        for (int i = 1; i < n; ++i)
        {
            if (intervals[i][0] <= cur[1])
                cur[1] = max(cur[1], intervals[i][1]);
            else
            {
                ret.emplace_back(cur);
                cur = intervals[i];
            }
        }
        ret.emplace_back(cur);
        
        return ret;
    }
};