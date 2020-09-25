// O(NlogN)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = (int)nums.size();
        
        vector<string> numsToString(n);
        for (int i = 0; i < n; ++i)
            numsToString[i] = to_string(nums[i]);
        sort(numsToString.begin(), numsToString.end(), [&numsToString](string const &a, string const &b)
        {
            return a + b > b + a;
        });
        
        string ret;
        for (int i = 0; i < n; ++i)
            ret += numsToString[i];
        if (!ret.empty() && ret[0] == '0')
            return "0";
        
        return ret;
    }
};