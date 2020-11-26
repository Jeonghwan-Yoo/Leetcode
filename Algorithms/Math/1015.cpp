// O(K)
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int mod = 0;
        for (int i = 1; i <= K; ++i)
        {
            mod = (10 * mod + 1) % K;
            if (mod == 0)
                return i;
        }
        
        return -1;
    }
};