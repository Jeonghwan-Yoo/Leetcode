// O(N)
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int n = (int)S.size();
        long long sz = 0ll;
        for (int i = 0; i < n; ++i)
        {
            if (isdigit(S[i]))
                sz *= S[i] - '0';
            else
                ++sz;
        }
        
        for (int i = n - 1; i >= 0; --i)
        {
            K %= sz;
            if (K == 0 && isalpha(S[i]))
                return (string)"" + S[i];
            
            if (isdigit(S[i]))
                sz /= S[i] - '0';
            else
                --sz;
        }
        
        return "";
    }
};