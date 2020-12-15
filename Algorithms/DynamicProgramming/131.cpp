// O(2^N)
class Solution {
public:
    void Dfs(int idx, string const &s, vector<string> &cur, vector<vector<string>> &ret, vector<vector<int>> &dp)
    {
        int n = (int)s.size();
        if (idx >= n)
        {
            ret.emplace_back(cur);
            return;
        }
        
        for (int i = idx; i < n; ++i)
        {
            if (s[idx] == s[i] && (i - idx <= 2 || dp[idx + 1][i - 1]))
            {
                dp[idx][i] = 1;
                cur.emplace_back(s.substr(idx, i - idx + 1));
                Dfs(i + 1, s, cur, ret, dp);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = (int)s.size();
        
        vector<vector<string>> ret;
        vector<string> cur;
        vector<vector<int>> dp(n, vector<int>(n));
        Dfs(0, s, cur, ret, dp);
        
        return ret;
    }
};