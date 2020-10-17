// O(N)
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = (int)s.size();
        if (n < 10)
            return vector<string>();
        
        unordered_map<string, int> hash;
        string key;
        for (int i = 0; i <= n - 10; ++i)
        {
            key = s.substr(i, 10);
            ++hash[key];
        }
        vector<string> ret;
        for (auto &h : hash)
            if (h.second >= 2)
                ret.emplace_back(h.first);
        
        return ret;
    }
};