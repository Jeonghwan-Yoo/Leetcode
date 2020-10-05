// O(1)
class Solution {
public:
    int bitwiseComplement(int N) {
        int mask = 2;
        while (mask <= N)
            mask <<= 1;
        
        return (mask - 1) ^ N;
    }
};