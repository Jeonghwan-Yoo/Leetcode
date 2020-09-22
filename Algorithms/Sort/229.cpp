// O(NlogN)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        
        int n = (int)nums.size();
        if (n == 0)
            return ret;
        
        sort(nums.begin(), nums.end());
        int n3 = n / 3;
        int cnt = 1;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] == nums[i - 1])
                ++cnt;
            else
            {
                if (cnt > n3)
                    ret.emplace_back(nums[i - 1]);
                cnt = 1;
            }
        }
        if (cnt > n3)
            ret.emplace_back(nums[n - 1]);
        
        return ret;
    }
};