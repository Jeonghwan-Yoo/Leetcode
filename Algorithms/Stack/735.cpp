// O(N)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = (int)asteroids.size();
        
        vector<int> s;
        vector<int> ret;
        for (int i = 0; i < n; ++i)
        {
            if (asteroids[i] > 0)
                s.emplace_back(asteroids[i]);
            else
            {
                bool flag = true;
                int curSz = -asteroids[i];
                while (!s.empty())
                {
                    if (curSz > s.back())
                        s.pop_back();
                    else if (curSz == s.back())
                    {
                        flag = false;
                        s.pop_back();
                        break;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    ret.emplace_back(asteroids[i]);
            }
        }
        for (int i = 0; i < s.size(); ++i)
            ret.emplace_back(s[i]);
        
        return ret;
    }
};