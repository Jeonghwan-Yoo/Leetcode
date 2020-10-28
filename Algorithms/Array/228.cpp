// O(N)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = (int)nums.size();
        
        vector<string> ret;
        for (int i = 0; i < n; ++i)
        {
            int st = i;
            while (i + 1 < n && nums[i] + 1 == nums[i + 1])
                ++i;
            if (st == i)
                ret.emplace_back(to_string(nums[st]));
            else
                ret.emplace_back(to_string(nums[st]) + "->" + to_string(nums[i]));
        }
        
        return ret;
    }
};