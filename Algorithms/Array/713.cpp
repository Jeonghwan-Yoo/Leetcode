// O(NlogN)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = (int)nums.size();
        
        if (k <= 1)
            return 0;
        
        double logk = log(k);
        vector<double> ps(n + 1);
        for (int i = 0; i < n; ++i)
            ps[i + 1] = ps[i] + log(nums[i]);
        
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            int l = i + 1;
            int r = n;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (ps[mid] - ps[i] < abs(logk - 1e-9))
                    l = mid + 1; 
                else
                    r = mid - 1;
            }
            cnt += (l - 1) - i;
        }

        return cnt;
    }
};