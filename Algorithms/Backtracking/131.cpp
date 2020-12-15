// O(N * 2^N)
class Solution {
public:
    void Dfs(int idx, string const &s, vector<string> &cur, vector<vector<string>> &ret)
    {
        int n = (int)s.size();
        if (idx >= n)
        {
            ret.emplace_back(cur);
            return;
        }
        
        for (int i = idx; i < n; ++i)
        {
            if (isPalindrome(idx, i, s))
            {
                cur.emplace_back(s.substr(idx, i - idx + 1));
                Dfs(i + 1, s, cur, ret);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(int l, int r, string const &s)
    {
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            ++l;
            --r;
        }
        
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        int n = (int)s.size();
        
        vector<vector<string>> ret;
        vector<string> cur;
        Dfs(0, s, cur, ret);
        
        return ret;
    }
};