// O(N)
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if ((int)A.size() != (int)B.size())
            return false;
        
        int n = (int)A.size();
        if (A == B)
            return (unordered_set<char>(A.begin(), A.end()).size() < n);
        
        int l = 0;
        int r = n - 1;
        while (l < n && A[l] == B[l])
            ++l;
        while (r >= 0 && A[r] == B[r])
            --r;
        if (l < r)
            swap(B[l], B[r]);
        
        return (A == B);
    }
};