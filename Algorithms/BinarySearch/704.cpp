// O(logN)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        
        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] < target)
                ++l;
            else if (nums[mid] > target)
                --r;
            else
                return mid;
        }
        
        return -1;
    }
};