// O(N)
// Kadane's algorithm
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        
        int cur = 0;
        int maxDiff = 0;
        for (int i = 1; i < n; ++i)
        {
            cur += prices[i] - prices[i - 1];
            cur = max(0, cur);
            maxDiff = max(maxDiff, cur);
        }
        
        return maxDiff;
    }
};

// O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        
        int minVal = INT_MAX;
        int maxDiff = 0;
        for (int i = 0; i < n; ++i)
        {
            if (minVal > prices[i])
                minVal = prices[i];
            else if (maxDiff < prices[i] - minVal)
                maxDiff = prices[i] - minVal;
        }
        
        return maxDiff;
    }
};

// O(N^2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        
        int maxDiff = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                maxDiff = max(maxDiff, prices[j] - prices[i]);
        
        return maxDiff;
    }
};