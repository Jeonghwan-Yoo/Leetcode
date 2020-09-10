// O(N)
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = (int)secret.size();
        vector<int> s(10);
        vector<int> g(10);
        int bull = 0;
        for (int i = 0; i < n; ++i)
        {
            if (secret[i] == guess[i])
                ++bull;
            else
            {
                ++s[secret[i] - '0'];
                ++g[guess[i] - '0'];
            }
        }
        int cow = 0;
        for (int i = 0; i < 10; ++i)
            cow += min(s[i], g[i]);
        string ret = to_string(bull) + "A" + to_string(cow) + "B";
        
        return ret;
    }
};