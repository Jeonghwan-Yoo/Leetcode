// O(N)
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = (int)timeSeries.size();
        if (n == 0)
            return 0;
        
        int ret = 0;
        for (int i = 1; i < n; ++i)
            ret += min(timeSeries[i] - timeSeries[i - 1], duration);
        
        return ret + duration;
    }
};