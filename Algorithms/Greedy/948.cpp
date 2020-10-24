// O(NlogN)
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int n = (int)tokens.size();
        
        int ret = 0;
        int score = 0;
        sort(tokens.begin(), tokens.end());
        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            while (l <= r && P >= tokens[l])
            {
                P -= tokens[l];
                ++l;
                ++score;
                ret = max(ret, score);
            }
            if (score <= 0)
                break;
            
            P += tokens[r];
            --score;
            --r;
        }
        
        return ret;
    }
};