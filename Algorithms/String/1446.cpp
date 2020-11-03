// O(N)
class Solution {
public:
    int maxPower(string s) {
        int ret = 0;
        
        int n = (int)s.size();
        char cur = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (cur == s[i])
                ++cnt;
            else
            {
                cur = s[i];
                cnt = 1;
            }
            ret =  max(ret, cnt);
        }
        
        return ret;
    }
};