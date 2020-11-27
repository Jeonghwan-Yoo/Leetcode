class Solution {
public:
    int DivideConquer(int start, int end, string &s, int k)
    {
        if (end < k)
            return 0;
        
        int n = (int)s.size();
        
        int cnt[26] = { 0, };
        for (int i = start; i < end; ++i)
            ++cnt[s[i] - 'a'];
        for (int i = start; i < end; ++i)
        {
            if (cnt[s[i] - 'a'] >= k)
                continue;
            
            int midNext = i + 1;
            while (midNext < end && cnt[s[midNext] - 'a'] < k)
                ++midNext;
            return max(DivideConquer(start, i, s, k), DivideConquer(midNext, end, s, k));
        }
        
        return end - start;
    }
    
    int longestSubstring(string s, int k) {
        int n = (int)s.size();
        
        return DivideConquer(0, n, s, k);
    }
};