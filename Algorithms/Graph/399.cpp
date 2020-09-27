// O(NEQ)
class Solution {
public:
    double Dfs(string src, string const &dst, double val, unordered_set<string> &visited, unordered_map<string, vector<pair<string, double>>> &adj)
    {
        if (visited.count(src))
            return -1.0;
        
        visited.insert(src);
        if (src == dst)
            return val;
        
        double ret = -1.0;
        for (auto &a : adj[src])
        {
            ret = Dfs(a.first, dst, val * a.second, visited, adj);
            if (ret != -1.0)
                return ret;
        }
        
        return ret;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        int n = (int)equations.size();
        for (int i = 0; i < n; ++i)
        {
            adj[equations[i][0]].emplace_back(equations[i][1], values[i]);
            adj[equations[i][1]].emplace_back(equations[i][0], 1 / values[i]);
        }
        
        vector<double> ret;
        int m = (int)queries.size();
        for (int i = 0; i < m; ++i)
        {
            unordered_set<string> visited;
            if (adj.count(queries[i][0]))
                ret.emplace_back(Dfs(queries[i][0], queries[i][1], 1.0, visited, adj));
            else
                ret.emplace_back(-1.0);
        }
        
        return ret;
    }
};