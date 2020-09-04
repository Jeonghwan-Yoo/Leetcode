// O(N)
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ret;
        
        int n = (int)S.size();
        vector<int> last(26);
        for (int i = 0; i < n; ++i)
            last[S[i] - 'a'] = i;
        
        for (int i = 0, l = 0, r = 0; i < n; ++i)
        {
            r = max(r, last[S[i] - 'a']);
            if (i == r)
            {
                ret.emplace_back(r - l + 1);
                l = r + 1;
            }
        }
        
        return ret;
    }
};