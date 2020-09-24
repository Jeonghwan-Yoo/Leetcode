// O(N)
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ns = (int)s.size();
        int nt = (int)t.size();
        
        array<int, 26> cnt = { 0, };
        for (int i = 0; i < ns; ++i)
            ++cnt[s[i] - 'a'];
        for (int i = 0; i < nt; ++i)
            --cnt[t[i] - 'a'];
        for (int i = 0; i < (int)cnt.size(); ++i)
            if (cnt[i])
                return i + 'a';
        return 0;
    }
};