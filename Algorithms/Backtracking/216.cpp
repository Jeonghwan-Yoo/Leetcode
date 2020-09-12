// O(2^9)
class Solution {
public:
    void Combination(int val, int k, int n, vector<int> &cur, vector<vector<int> > &ret)
    {
        if (n == 0 && k == 0)
        {
            ret.emplace_back(cur);
            return;
        }
        
        if (n < 0 || k < 0 || val >= 10)
            return;
        
        cur.emplace_back(val);
        Combination(val + 1, k - 1, n - val, cur, ret);
        cur.pop_back();
        Combination(val + 1, k, n, cur, ret);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ret;
        
        vector<int> cur;
        Combination(1, k, n, cur, ret);
        
        return ret;
    }
};