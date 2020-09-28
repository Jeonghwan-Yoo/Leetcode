// O(N)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = (int)nums.size();
        
        int l = 0;
        int r = 0;
        int mul = 1;
        int cnt = 0;
        while (r < n)
        {
            mul *= nums[r];
            while (l <= r && mul >= k)
            {
                mul /= nums[l];
                ++l;
            }
            ++r;
            cnt += r - l;
        }
        
        return cnt;
    }
};