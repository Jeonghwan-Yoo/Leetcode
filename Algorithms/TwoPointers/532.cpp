// O(NlogN)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = (int)nums.size();
        int l = 0;
        int r = 1;
        int cnt = 0;
        while (r < n)
        {
            int diff = nums[r] - nums[l];
            if (diff < k || l == r)
                ++r;
            else if (diff > k)
                ++l;
            else
            {
                ++cnt;
                ++r;
                while (r < n && nums[r - 1] == nums[r])
                    ++r;
                ++l;
            }
            
        }
        
        return cnt;
    }
};