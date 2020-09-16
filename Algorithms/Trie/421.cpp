// O(N)
class Solution {
public:
    struct Trie
    {
        Trie *node[2];
        Trie()
        {
            node[0] = node[1] = nullptr;
        }
        void Add(int num)
        {
            Trie *cur = this;
            for (int i = 31; i >= 0; --i)
            {
                int nxt = (num >> i) & 1;
                if (cur->node[nxt] == nullptr)
                    cur->node[nxt] = new Trie();
                cur = cur->node[nxt];
            }
        }
        int FindXor(int num)
        {
            int val = 0;
            Trie *cur = this;
            for (int i = 31; i >= 0; --i)
            {
                int nxt = (num >> i) & 1;
                if (cur->node[nxt ^ 1] != nullptr)
                {
                    nxt ^= 1;
                    val += (1 << i);
                }
                cur = cur->node[nxt];
            }
            return val;
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        int n = (int)nums.size();
        
        int maxVal = 0;
        Trie *root = new Trie();
        for (int i = 0; i < n; ++i)
        {
            root->Add(nums[i]);
            maxVal = max(maxVal, root->FindXor(nums[i]));
        }        
        
        return maxVal;
    }
};