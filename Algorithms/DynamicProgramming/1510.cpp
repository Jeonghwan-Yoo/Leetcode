// O(N)
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                if (arr[i - j * j] == 0)
                {
                    arr[i] = 1;
                    break;
                }
            }
        }
        
        return arr[n];
    }
};