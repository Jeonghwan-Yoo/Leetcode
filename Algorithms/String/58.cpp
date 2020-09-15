// O(N)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = (int)s.size();
        
        int len = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] == ' ')
            {
                if (len == 0)
                    continue;
                else
                    break;
            }
            ++len;
        }
        
        return len;
    }
};