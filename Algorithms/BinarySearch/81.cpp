// O(N)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        
        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == target)
                return true;
            if (nums[l] == nums[mid])
            {
                ++l;
                continue;
            }
            
            bool pivotInc = nums[l] <= nums[mid]; 
            bool targetInc = nums[l] <= target;
            if (pivotInc == targetInc)
            {
                if (nums[mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else if (pivotInc)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return false;
    }
};