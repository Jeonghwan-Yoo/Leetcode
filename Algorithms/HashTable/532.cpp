// O(N)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i)
            ++cnt[nums[i]];
        
        int ret = 0;
        for (auto &c : cnt)
            if ((k == 0 && c.second > 1) || (k != 0 && cnt.count(c.first + k)))
                ++ret;
        
        return ret;
    }
};