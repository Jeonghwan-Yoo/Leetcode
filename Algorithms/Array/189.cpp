// Using Cyclic Replacements
// O(N)


// O(N)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        k %= n;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// O(N)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        k %= n;
        
        vector<int> tmp = nums;
        for (int i = 0; i < n; ++i)
            tmp[i] = nums[(i + n - k) % n];
        for (int i = 0; i < n; ++i)
            nums[i] = tmp[i];
    }
};