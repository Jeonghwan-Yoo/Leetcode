// O(N)
class Solution {
public:
    int GetMaximum(int st, int en, vector<int> const &nums)
    {
        int n = (int)nums.size();
        vector<vector<int>> dp(2, vector<int>(2));
        dp[st & 1][1] = nums[st & 1];
        for (int i = st + 1; i < en; ++i)
        {
            dp[i & 1][0] = max(dp[(i - 1) & 1][0], dp[(i - 1) & 1][1]);
            dp[i & 1][1] = dp[(i - 1) & 1][0] + nums[i];
        }
        
        return max(dp[(en - 1) & 1][0], dp[(en - 1) & 1][1]);
    }
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1)
            return nums[0];
        
        return max(GetMaximum(0, n - 1, nums), GetMaximum(1, n, nums));
    }
};

// O(N)
class Solution {
public:
    int GetMaximum(int st, int en, vector<int> const &nums)
    {
        int n = (int)nums.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[st][1] = nums[st];
        for (int i = st + 1; i < en; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        
        return max(dp[en - 1][0], dp[en - 1][1]);
    }
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1)
            return nums[0];
        
        return max(GetMaximum(0, n - 1, nums), GetMaximum(1, n, nums));
    }
};