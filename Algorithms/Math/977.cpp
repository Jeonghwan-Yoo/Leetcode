// O(N)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = (int)nums.size();
        
        vector<int> ret(n);
        int idx = n - 1;
        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            if (abs(nums[l]) < abs(nums[r]))
            {
                ret[idx] = nums[r] * nums[r];
                --r;
            }
            else
            {
                ret[idx] = nums[l] * nums[l];
                ++l;
            }
            --idx;
        }
        
        return ret;
    }
};