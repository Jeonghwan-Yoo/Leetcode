// O(N)
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int n = (int)pattern.size();
        vector<string> words;
        stringstream ss(str);
        string s;
        while(ss >> s)
            words.emplace_back(s);
        
        if (n != (int)words.size())
            return false;
        
        unordered_map<char, int> ump;
        unordered_map<string, int> ums;
        for (int i = 0; i < n; ++i)
        {
            if (!ump.count(pattern[i]))
                ump[pattern[i]] = i;
            
            if (!ums.count(words[i]))
                ums[words[i]] = i;
            
            if (ump[pattern[i]] != ums[words[i]])
                return false;
        }
        return true;
    }
};