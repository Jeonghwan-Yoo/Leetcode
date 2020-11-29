// O(N)
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = (int)arr.size();
        
        queue<int> q;
        q.emplace(start);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (arr[cur] == 0)
                return true;
            if (arr[cur] < 0)
                continue;
            
            int next1 = cur - arr[cur];
            if (next1 >= 0)
                q.emplace(next1);
            int next2 = cur + arr[cur];
            if (next2 < n)
                q.emplace(next2);
            
            arr[cur] = -arr[cur];
        }
        
        return false;
    }
};