// O(1)
class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0)
            return 1;
        
        int power = (int)log2(N);
        int mask = pow(2, power + 1);
        
        return (mask - 1) ^ N;
    }
};