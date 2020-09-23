// O(N)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size();
        
        int sumGas = 0;
        int sumCost = 0;
        int tank = 0;
        int st = 0;
        for (int i = 0; i < n; ++i)
        {
            sumGas += gas[i];
            sumCost += cost[i];
            tank += gas[i] - cost[i];
            if (tank < 0)
            {
                st = i + 1;
                tank = 0;
            }
        }
        return (sumGas >= sumCost ? st : -1);
    }
};

// O(N^2)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size();
        
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = 0; j < n; ++j)
            {
                int cur = (i + j) % n;
                sum += gas[cur] - cost[cur];
                if (sum < 0)
                    break;
            }
            if (sum >= 0)
                return i;
        }
        return -1;
    }
};