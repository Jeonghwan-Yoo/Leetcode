// O(N)
// Boyer-Moore Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {        
        int n = (int)nums.size();
        
        int cnt1 = 0;
        int cnt2 = 0;
        int val1 = -1;
        int val2 = -1;
        for (int i = 0;i < n; ++i)
        {
            if (val1 == nums[i])
                ++cnt1;
            else if (val2 == nums[i])
                ++cnt2;
            else if (cnt1 == 0)
            {
                val1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                val2 = nums[i];
                cnt2 = 1;
            }
            else
            {
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (val1 == nums[i])
                ++cnt1;
            else if (val2 == nums[i])
                ++cnt2;
        }
        
        vector<int> ret;

        int n3 = n / 3;
        if (cnt1 > n3)
            ret.emplace_back(val1);
        if (cnt2 > n3)
            ret.emplace_back(val2);
        
        return ret;
    }
};