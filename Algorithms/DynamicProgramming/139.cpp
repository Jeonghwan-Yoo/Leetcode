
// O(N^3)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = (int)s.size();
        int m = (int)wordDict.size();
        
        unordered_set<string> wordSet;
        for (auto &w : wordDict)
            wordSet.insert(w);
        
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] == 1 && wordSet.count(s.substr(j, i - j)))
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};