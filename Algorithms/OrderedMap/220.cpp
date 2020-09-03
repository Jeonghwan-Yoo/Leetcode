// O(N)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0 || t < 0)
            return false;
        
        int n = (int)nums.size();
        unordered_map<int, int> um;
        for (int i = 0; i < n; ++i)
        {       
            int key = nums[i] / ((long long)t + 1);
            if (nums[i] < 0)
                --key;
            
            if (um.count(key))
                return true;
            if (um.count(key - 1) && (long long)nums[i] - um[key - 1] <= t)
                return true;
            if (um.count(key + 1) && (long long)um[key + 1] - nums[i] <= t)
                return true;
            
            if ((int)um.size() >= k)
            {
                int prv = nums[i - k];
                if (prv < 0)
                    --prv;
                um.erase(prv / ((long long)t + 1));
            }
            um[key] = nums[i];
        }
        
        return false;
    }
};

// O(NlongN)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0 || t < 0)
            return false;
        
        int n = (int)nums.size();
        set<long long> s;
        for (int i = 0; i < n; ++i)
        {
            auto l = s.lower_bound((long long)nums[i] - t);
            if (l != s.end() && (*l) - nums[i] <= t)
                return true;
            
            if ((int)s.size() >= k)
                s.erase(nums[i - k]);
            s.insert(nums[i]);
        }
        
        return false;
    }
};