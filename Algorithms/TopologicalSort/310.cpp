// O(N)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ret;
        if (n == 1)
            ret.emplace_back(0);
        if (n < 2)
            return ret;
        
        vector<int> degree(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            adj[edges[i][0]].emplace_back(edges[i][1]);
            adj[edges[i][1]].emplace_back(edges[i][0]);
            ++degree[edges[i][1]];
            ++degree[edges[i][0]];
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (degree[i] == 1)
                q.emplace(i);
        while (!q.empty())
        {
            ret.clear();
            int sz = (int)q.size();
            for (int i = 0; i < sz; ++i)
            {
                int cur = q.front();
                q.pop();
                ret.emplace_back(cur);
                for (auto &a : adj[cur])
                {
                    --degree[a];
                    if (degree[a] == 1)
                        q.emplace(a);
                }
            }
        }
        
        return ret;
    }
};