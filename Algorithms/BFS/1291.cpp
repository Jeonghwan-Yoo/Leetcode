// O(1)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ret;
        queue<int> q;
        for (int i = 1; i <= 9; ++i)
            q.emplace(i);
        while (!q.empty())
        {
            int a = q.front();
            q.pop();
            
            if (a > high)
                break;
            
            if (low <= a && a <= high)
                ret.emplace_back(a);
            
            int ndigit1 = a % 10 + 1;
            if (ndigit1 < 10)
                q.emplace(a * 10 + ndigit1);
        }
        
        return ret;
    }
};