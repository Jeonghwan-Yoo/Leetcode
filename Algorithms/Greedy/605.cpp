// O(N)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0)
            return true;
        
        int len = (int)flowerbed.size();
        
        int cnt = 0;
        for (int i = 0; i < len; ++i)
        {
            if ((i == 0 || flowerbed[i - 1] == 0) && flowerbed[i] == 0 && (i == len - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                ++cnt;
                if (cnt >= n)
                    return true;
            }
        }
        
        return false;
    }
};