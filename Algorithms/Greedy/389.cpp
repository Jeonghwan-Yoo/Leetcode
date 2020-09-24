// O(NlogN)
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ns = (int)s.size();
        int nt = (int)t.size();
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        for (int i = 0; i < ns; ++i)
            if (s[i] != t[i])
                return t[i];
        
        return t[nt - 1];
    }
};