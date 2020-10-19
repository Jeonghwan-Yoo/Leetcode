// O(N)
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int sz = (int)A.size();
        
        int a = 0;
        int b = 0;
        for (int i = 0; i < sz; ++i)
        {
            if (A[i] != A[0] && B[i] != A[0])
            {
                a = -1;
                break;
            }
            
            if (B[i] != A[0])
                ++a;
            if (A[i] != A[0])
                ++b;
        }
        if (a != -1)
            return min(a, b);
        
        a = 0;
        b = 0;
        for (int i = 0; i < sz; ++i)
        {
            if (B[i] != B[0] && A[i] != B[0])
            {
                b = -1;
                break;
            }
            
            if (B[i] != B[0])
                ++a;
            if (A[i] != B[0])
                ++b;
        }
        if (b != -1)
            return min(a, b);
        
        return -1;
    }
};