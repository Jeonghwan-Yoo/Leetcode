// O(2^N)
class Solution {
public:
    void Backtracking(int idx, vector<int> &path, vector<vector<int>> &ans, vector<int> const &candidates, int target)
    {
        if (target == 0)
        {
            ans.emplace_back(path);
            return;
        }
        for (int i = idx; i < (int)candidates.size(); ++i)
        {
            int newTarget = target - candidates[i];
            if (newTarget >= 0)
            {
                path.emplace_back(candidates[i]);
                Backtracking(i, path, ans, candidates, newTarget);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        Backtracking(0, path, ret, candidates, target);
        
        return ret;
    }
};