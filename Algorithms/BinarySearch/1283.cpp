// O(NlogN)
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = (int)nums.size();
        
        int l = 1;
        int r = nums[n - 1];
        while (l <= r)
        {
            int mid = (l + r) >> 1; 
            int sum = 0;
            for (int i = 0; i < n; ++i)
                sum += (nums[i] + mid - 1) / mid;
            if (sum <= threshold)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return r + 1;
    }
};