// O(N^3)
class Solution {
public:
    int Count1(int num)
    {
        int cnt = 0;
        while (num)
        {
            cnt += num & 1;
            num >>= 1;
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = (int)A.size();
        
        vector<int> A1(n);
        vector<int> B1(n);
        for (int i = 0; i < n; ++i)
        {
            int mask = 1;
            for (int j = 0; j < n; ++j)
            {
                A1[i] |= A[i][j] * mask;
                B1[i] |= B[i][j] * mask;
                mask <<= 1;
            }
        }
        
        int maxVal = 0;
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                int val = 0;
                for (int i = 0; i + y < n; ++i)
                    val += Count1((A1[i + y] >> x) & B1[i]);
                if (maxVal < val)
                    maxVal = val;
                
                val = 0;
                for (int i = 0; i + y < n; ++i)
                    val += Count1((B1[i + y] >> x) & A1[i]);
                if (maxVal < val)
                    maxVal = val;
            }
        }
        
        return maxVal;
    }
};

// O(N^4)
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = (int)A.size();
        
        int maxVal = 0;
        for (int y = -n + 1; y < n; ++y)
        {
            for (int x = -n + 1; x < n; ++x)
            {
                int val = 0;
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        if (i + y < 0 || i + y >= n || j + x < 0 || j + x >= n)
                            continue;
                        if (A[i + y][j + x] == 1 && B[i][j] == 1)
                            ++val;
                    }
                }
                if (maxVal < val)
                    maxVal = val;
            }
        }
        
        return maxVal;
    }
};