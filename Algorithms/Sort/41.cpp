// O(NlogN)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = (int)nums.size();
        
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        int num = 1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
            {
                if (nums[i] == num)
                    ++num;
                else
                    return num;
            }
        }
        
        return num;
    }
};