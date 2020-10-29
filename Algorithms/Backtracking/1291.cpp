// O(1)
class Solution {
public:
    void Dfs(int cur, int l, int h, vector<int> &ret)
    {
        if (cur > h)
            return;
        
        if (l <= cur && cur <= h)
            ret.emplace_back(cur);
        
        int ndigit1 = cur % 10 + 1;
        if (ndigit1 < 10)
            Dfs(cur * 10 + ndigit1, l, h, ret);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ret;
        
        for (int i = 1; i < 10; ++i)
            Dfs(i, low, high, ret);
        sort(ret.begin(), ret.end());
        
        return ret;
    }
};