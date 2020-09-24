// O(N)
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ns = (int)s.size();
        int nt = (int)t.size();
        char ret = 0;
        
        for (int i = 0; i < ns; ++i)
        {
            ret ^= s[i];
            ret ^= t[i];
        }
        ret ^= t[nt - 1];
        
        return ret;
    }
};