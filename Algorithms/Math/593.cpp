// O(1)
class Solution {
public:
    int dist(vector<int> &p1, vector<int> &p2)
    {
        int x = p1[0] - p2[0];
        int y = p1[1] - p2[1];
        
        return x * x + y * y;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int, int> cnt;
        ++cnt[dist(p1, p2)];
        ++cnt[dist(p1, p3)];
        ++cnt[dist(p1, p4)];
        ++cnt[dist(p2, p3)];
        ++cnt[dist(p2, p4)];
        ++cnt[dist(p3, p4)];
        
        return (cnt.count(0) == 0 && (int)cnt.size() == 2);
    }
};