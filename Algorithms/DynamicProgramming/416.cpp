// O(NM)
class Solution {
public:
    bool Dfs(int idx, int sum, vector<vector<int>> &dp, vector<int> const &nums)
    {
        if (idx >= (int)nums.size())
            return false;
        if (sum < 0)
            return false;
        if (sum == 0)
            return true;
        
        int &ret = dp[idx][sum];
        if (ret != -1)
            return ret;
        
        return ret = (Dfs(idx + 1, sum, dp, nums) || Dfs(idx + 1, sum - nums[idx], dp, nums));
    }
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        
        int total = 0;
        for (int i = 0; i < n; ++i)
            total += nums[i];
        if (total & 1)
            return false;
        
        int half = total >> 1;
        vector<vector<int>> dp(n + 1, vector<int>(half + 1, -1));
        return Dfs(0, half, dp, nums);
    }
};