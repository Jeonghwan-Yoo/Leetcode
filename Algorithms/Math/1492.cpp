// O(rootN)
class Solution {
public:
    int kthFactor(int n, int k) {
        int cnt = 0;
        int sqrtN = sqrt(n);
        vector<int> fac;
        for (int i = 1; i <= sqrtN; ++i)
        {
            if (n % i == 0)
            {
                ++cnt;
                if (cnt == k)
                    return i;
                fac.emplace_back(i);
            }
        }
        
        int rear = (int)fac.size() << 1;
        if (sqrtN * sqrtN == n)
            --rear;
        if (k <= rear)
            return n / fac[rear - k];
        
        return -1;
    }
};

// O(N)
class Solution {
public:
    int kthFactor(int n, int k) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (n % i == 0)
            {
                ++cnt;
                if (cnt == k)
                    return i;
            }
        }
        
        return -1;
    }
};