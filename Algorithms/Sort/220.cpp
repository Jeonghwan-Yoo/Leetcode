// O(NlogN)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0 || t < 0)
            return false;
        
        int n = (int)nums.size();
        vector<pair<int, int> > sorted(n);
        for (int i = 0; i < n; ++i)
            sorted[i] = { nums[i], i };
        sort(sorted.begin(), sorted.end());
        
        for (int i = 0; i < n; ++i)
        {
            int j = i + 1;
            while (j < n && (long long)sorted[j].first - sorted[i].first <= t)
            {
                if (llabs((long long)sorted[j].second - sorted[i].second) <= k)
                    return true;
                ++j;
            }
        }
        
        return false;
    }
};